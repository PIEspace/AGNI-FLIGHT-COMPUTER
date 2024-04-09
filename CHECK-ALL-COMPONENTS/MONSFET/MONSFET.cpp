// check the monsfet

#include<Arduino.h>

// define the monsfet 
const int First_Monsfet = PC14;
const int Second_Monsfet = PC15;
const int Third_Monsfet =  PA0;


void setup(){
    // define the bud rate 
    Serial.begin(9600);

    pinMode(First_Monsfet , OUTPUT);
    pinMode(Second_Monsfet , OUTPUT);
    pinMode(Third_Monsfet , OUTPUT);


}

void loop(){

    digitalWrite(First_Monsfet , 1);
    digitalWrite(Second_Monsfet , 1);
    digitalWrite(Third_Monsfet , 1);
    delay(1000);

    digitalWrite(First_Monsfet , 0);
    digitalWrite(Second_Monsfet , 0);
    digitalWrite(Third_Monsfet , 0);
    delay(1000);

}