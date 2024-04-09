// check the inner led 

#include<Arduino.h>

// define the inner led values 
const int First_Led = PA1;
const int Second_Led = PA2;
const int Third_Led = PA3;

void setup(){
    // define the bud rate 
    Serial.begin(9600);

    pinMode(First_Led , OUTPUT);
    pinMode(Second_Led , OUTPUT);
    pinMode(Third_Led , OUTPUT);
}

void loop(){

    digitalWrite(First_Led , 1);
    digitalWrite(Second_Led , 1);
    digitalWrite(Third_Led , 1);

    delay(1000);

    digitalWrite(First_Led , 0);
    digitalWrite(Second_Led , 0);
    digitalWrite(Third_Led , 0);

    delay(1000);

}