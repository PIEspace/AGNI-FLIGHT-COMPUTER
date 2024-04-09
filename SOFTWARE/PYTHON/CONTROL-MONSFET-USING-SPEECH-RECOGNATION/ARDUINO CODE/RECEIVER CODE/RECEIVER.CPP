// check the nrf24l01 module 
// this is  a receiver section i am using arduino nano  
#include<Arduino.h>
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
// define the ce and cns pin 
const int CE = PA4;
const int CNS = PB0;
RF24 radio (CE , CNS);

// DEFINE THE ADDRESS 
const byte address[6] = "00001";

// define the leds 
const int First_Led = PB12;
const int Second_Led = PB13;
const int Third_Led = PB14;


const int First_Monsfet = PC14;
const int Second_Monsfet = PC15;
const int Third_Monsfet =  PA0;


const int First_Led_inner = PA1;
const int Second_Led_inner = PA2;
const int Third_Led_inner = PA3;

void setup(){
    Serial.begin(9600) ; //in this case i am using 9600 bits per second 
    radio.begin();
    radio.openReadingPipe(0,address);
    radio.setPALevel(RF24_PA_HIGH);
    radio.startListening();

    pinMode(First_Led , OUTPUT);
    pinMode(Second_Led , OUTPUT);
    pinMode(Third_Led , OUTPUT);

    pinMode(First_Monsfet , OUTPUT);
    pinMode(Second_Monsfet , OUTPUT);
    pinMode(Third_Monsfet , OUTPUT);

    pinMode(First_Led_inner , OUTPUT);
    pinMode(Second_Led_inner , OUTPUT);
    pinMode(Third_Led_inner , OUTPUT);

}

void loop(){

    if(radio.available()){
        char  command ;
        radio.read(&command , sizeof(command));

        if(command == 'a'){
            digitalWrite(First_Led , 1);
            digitalWrite(First_Monsfet,  1);
            digitalWrite(First_Led_inner , 1);
        }

        else if(command == 'b'){
            digitalWrite(First_Led , 0);
            digitalWrite(First_Monsfet , 0);
            digitalWrite(First_Led_inner , 0);
        }

        else if (command == 'c'){
            digitalWrite(Second_Led , 1);
            digitalWrite(Second_Monsfet , 1);
            digitalWrite(Second_Led_inner , 1);
        }

        else if (command == 'd'){
            digitalWrite(Second_Led , 0);
            digitalWrite(Second_Monsfet , 0);
            digitalWrite(Second_Led_inner , 0);
        }

        else if (command == 'e'){
            digitalWrite(Third_Led , 1);
            digitalWrite(Third_Monsfet , 1);
            digitalWrite(Third_Led_inner , 1);
        }

        else if (command == 'f'){
            digitalWrite(Third_Led , 0);
            digitalWrite(Third_Monsfet, 0);
            digitalWrite(Third_Led_inner , 0);
        }

    }

}