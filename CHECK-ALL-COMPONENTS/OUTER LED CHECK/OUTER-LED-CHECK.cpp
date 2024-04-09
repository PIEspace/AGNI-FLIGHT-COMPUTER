// check the led 


#include<Arduino.h>

// define the led
const int First_Led = PB12;
const int Second_Led = PB13;
const int Third_Led = PB14;


void setup(){
    // define the bud rate 
    Serial.begin(9600);

    // Define the pinMode
    pinMode(First_Led , OUTPUT);
    pinMode(Second_Led , OUTPUT);
    pinMode(Third_Led , OUTPUT);


}

void loop(){
    digitalWrite(First_Led , HIGH);
    digitalWrite(Second_Led , HIGH);
    digitalWrite(Third_Led , HIGH);
    delay(1000);

    digitalWrite(First_Led , LOW);
    digitalWrite(Second_Led , LOW);
    digitalWrite(Third_Led , LOW);
    delay(1000);
    

}