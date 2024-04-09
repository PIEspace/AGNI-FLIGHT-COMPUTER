// check the buzzer 

#include<Arduino.h>

// connect the buzzer 
const int buzzer = PC13;

void setup(){
    // define the pinMode
    pinMode(buzzer , OUTPUT);
}

void loop(){

    digitalWrite(buzzer , 1);
    delay(1000);

    digitalWrite(buzzer , 0);
    delay(1000);

}