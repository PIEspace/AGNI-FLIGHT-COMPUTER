// THIS IS A RECEIVER CODE 
//CONTROL BOX VERSION TWO
//THIS IS A MAIN RECEIVER BOX TO SHOW THE PROCESSING CODE 


#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>




// Define the CE and CNS pin
const int CE_PIN = 7;
const int CNS_PIN = 8;

// Define the radio
RF24 radio(CE_PIN, CNS_PIN);

// Define the address
const byte address[][7] = {"12345", "123456"};


struct Data_Package
{
    float Roll_Value;
    float Pitch_Value;
    float Yaw_Value;

    // float Temperature;
    // float pressure;
    // float Altitude;

    

    
};

Data_Package data;


void setup()
{
    // Define the baud rate
    Serial.begin(9600);

    // Define the radio
    radio.begin();
    radio.openWritingPipe(address[1]);
    radio.openReadingPipe(1, address[0]);
    radio.setPALevel(RF24_PA_HIGH);
    radio.startListening();




}

void loop()
{
    if (radio.available())
    {
        radio.read(&data, sizeof(Data_Package));

        //DEFINE THE MPU6050
        Serial.print(data.Roll_Value);
        Serial.print(",");
        Serial.print(data.Pitch_Value);
        Serial.print(",");
        Serial.println(data.Yaw_Value);
        // Serial.print(",");

        // Serial.print(data.Temperature);
        // Serial.print(",");
        // Serial.print(data.pressure);
        // Serial.print(",");
        // Serial.println(data.Altitude);
        

        
        

        
        
    }
}

