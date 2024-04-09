// this is a transmitter code 
// in this part i am using STM32F103C8 
// hello everyone this is a first part of this flight computer software 

#include <Arduino.h>
#include <Wire.h>
#include <MPU6050.h>
#include <SimpleKalmanFilter.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Adafruit_BMP280.h>

/*
 _________________________________________________________________________________
|                                                                                 |
|_________________________________________________________________________________|
*/
// Define the mpu6050 sensor 
MPU6050 mpu;
int16_t ax, ay, az; // Accelerometer raw data
int16_t gx, gy, gz; // Gyroscope raw data
float AccX, AccY, AccZ;    // Accelerometer scaled data
float GyroX, GyroY, GyroZ; // Gyroscope scaled data
float roll, pitch, yaw; // Calculated roll and pitch angles
// Define Kalman filter parameters
// define the kalman filter for roll , pitch and yaw values 
SimpleKalmanFilter kalmanPitch(2, 2, 0.15); // Q, R, initial estimate
SimpleKalmanFilter kalmanRoll(2, 2, 0.15);  // Q, R, initial estimate
SimpleKalmanFilter kalmanYaw(2, 2, 0.15);   // Q , R , initial estimate

// define the kalman filter for accelerometer 
SimpleKalmanFilter kalmanAccX(2,2,0.15);
SimpleKalmanFilter kalmanAccY(2,2,0.15);
SimpleKalmanFilter kalmanAccZ(2,2,0.15);

/*
 _________________________________________________________________________________
|                                                                                 |
|_________________________________________________________________________________|
*/
// define the nrf24l01 module 
//define the CE and CNS pin 
const int CE_PIN = PA4 ;
const int CNS_PIN = PB0;
//define the radio
RF24 radio (CE_PIN , CNS_PIN);
//define the address 
const byte address[][7] = {"12345" , "123456"};

struct Data_Package
{
    float Roll_Value;
    float Pitch_Value;
    float Yaw_Value;

    float Temperature;
    float pressure;
    float Altitude;

    float AccX;
    float AccY;
    float AccZ;

    
};

Data_Package data;

/*
 _________________________________________________________________________________
|                                                                                 |
|_________________________________________________________________________________|
*/
// define the bmp280 sensor 
Adafruit_BMP280 bmp; // I2C
// use kalman filter for better accuracy 
SimpleKalmanFilter kalmanTemp(2 , 2 , 0.15);
SimpleKalmanFilter kalmanPressure (2,2,0.15);
SimpleKalmanFilter kalmanAltitude(2,2,0.15);

#define ALTITUDE_REFERENCE 0 //initial altitude at ground level
#define SEA_LEVEL_PRESSURE 1000 //Sea level pressure in hpa

/*
 _________________________________________________________________________________
|                                                                                 |
|_________________________________________________________________________________|
*/
// define the buzzer 
const int Buzzer = PC13;
// DEFINE THE INNER LED 
const int First_Led = PA1;
const int Second_Led = PA2;
const int Third_Led = PA3;
// check the led 
const int First_Led_Outer = PB12;
const int Second_Led_Outer = PB13;
const int Third_Led_Outer = PB14;
// define the monsfet 
const int First_Monsfet = PC14;
const int Second_Monsfet = PC15;
const int Third_Monsfet =  PA0;




void setup(){
    // Define the bud rate in this case i am using 9600 bits per second 
    Serial.begin(9600);

    // Define the mpu6050 sensor 
    Wire.begin();
    mpu.initialize();
    mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_2);  // Set accelerometer range to +/- 2g
    mpu.setFullScaleGyroRange(MPU6050_GYRO_FS_2000); // Set gyroscope range to +/- 2000 degrees/sec


    radio.begin();
    radio.openWritingPipe(address[0]); //the address is = 12345
    radio.openReadingPipe(1 , address[1]); //the address is = 123456
    radio.setPALevel(RF24_PA_HIGH);
    radio.stopListening();

    // define the bmp280 i2c address 
    // in this case bmp280 i2c address is 0x76
    if (!bmp.begin(0x76)) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
    }

    pinMode(Buzzer , OUTPUT);

    pinMode(First_Led , OUTPUT);
    pinMode(Second_Led , OUTPUT);
    pinMode(Third_Led , OUTPUT);

    pinMode(First_Led_Outer , OUTPUT);
    pinMode(Second_Led_Outer , OUTPUT);
    pinMode(Third_Led_Outer , OUTPUT);

    pinMode(First_Monsfet , OUTPUT);
    pinMode(Second_Monsfet , OUTPUT);
    pinMode(Third_Monsfet , OUTPUT);


}

void loop(){

    radio.write(&data , sizeof(Data_Package));

    // set the mpu6050 value 
    // define the roll pitch and yaw value 
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); // Get raw sensor data

    // Convert raw accelerometer data to G's
    AccX = (float)ax / 16384.0;
    AccY = (float)ay / 16384.0;
    AccZ = (float)az / 16384.0;

    // Check if AccY and AccZ are both non-zero to avoid division by zero

    // Convert raw gyroscope data to degrees/second
    GyroX = (float)gx / 131.0;
    GyroY = (float)gy / 131.0;
    GyroZ = (float)gz / 131.0;

    // Calculate roll, pitch, and yaw angles
    // convert the radian to degree = 180/pi
    roll = atan2(AccY, AccZ) * 180.0 / M_PI;
    pitch = atan(-AccX / sqrt(AccY * AccY + AccZ * AccZ)) * 180.0 / M_PI;
    yaw = atan2(-GyroX, sqrt(GyroY * GyroY + GyroZ * GyroZ)) * 180.0 / M_PI;

    // Apply Kalman filter to smooth pitch and roll angles
    pitch = kalmanPitch.updateEstimate(pitch);
    roll = kalmanRoll.updateEstimate(roll);
    yaw = kalmanYaw.updateEstimate(yaw);

    roll -= 88;


    



    //set the bmp280 value 
    float Temperature_Data = bmp.readTemperature();
    float Pressure_Data = bmp.readPressure();
    float Altitude_Data = bmp.readAltitude(SEA_LEVEL_PRESSURE);

    Temperature_Data = kalmanTemp.updateEstimate(Temperature_Data);
    Pressure_Data = kalmanPressure.updateEstimate(Pressure_Data);
    Altitude_Data = kalmanAltitude.updateEstimate(Altitude_Data);

    

    Altitude_Data -= ALTITUDE_REFERENCE;


    // define the accelerometer value 
    AccX = kalmanAccX.updateEstimate(AccX);
    AccY = kalmanAccY.updateEstimate(AccY);
    AccZ = kalmanAccZ.updateEstimate(AccZ);


    


    // send on the nrf24l01 module
    // send the roll pitch and yaw data
    data.Roll_Value = roll;
    data.Pitch_Value = pitch;
    data.Yaw_Value = yaw;

    data.Temperature = Temperature_Data;
    data.pressure = Pressure_Data;
    data.Altitude = Altitude_Data;

    data.AccX = AccX;
    data.AccY = AccY;
    data.AccZ = AccZ;
     




    // // print on the serial monitor 
    // Serial.print(data.Roll_Value);
    // Serial.print(",");
    // Serial.print(data.Pitch_Value);
    // Serial.print(",");
    // Serial.print(data.Yaw_Value);
    // Serial.print(",");

    // Serial.print(data.Temperature);
    // Serial.print(",");
    // Serial.print(data.pressure);
    // Serial.print(",");
    // Serial.print(data.Yaw_Value);
    // Serial.print(",");

    // Serial.print(data.AccX);
    // Serial.print(",");
    // Serial.print(data.AccY);
    // Serial.print(",");
    // Serial.print(data.AccZ);
    // Serial.print(",");

    Serial.print("Altitude: ");
    Serial.print(Altitude_Data);
    Serial.println(" M ");



    


    

}



