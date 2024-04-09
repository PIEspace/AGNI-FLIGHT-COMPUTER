// let control the led using speech recognition module 

#include<Arduino.h>

// define the led 
const int First_Led = PB12;
const int Second_Led = PB13;
const int Third_Led = PB14;




void setup(){
    // define the bud rate so in this case i am using 9600 bits per second 
    Serial.begin(9600);

    // define the led pinMode
    pinMode(First_Led , OUTPUT);
    pinMode(Second_Led , OUTPUT);
    pinMode(Third_Led , OUTPUT);

    // DEFINE THE PATH 
    Serial.println("TURN ON FIRST LED PRESS = A");
    Serial.println("TURN OFF FIRST LED PRESS = B");

    Serial.println("TURN ON SECOND LED PRESS = C");
    Serial.println("TURN OFF SECOND LED PRESS = D");

    Serial.println("TURN ON THIRD LED PRESS = E");
    Serial.println("TURN ON THIRD LED PRESS = F");
}

void loop(){

    if(Serial.available() > 0){
        char command  = Serial.read();


        //DEFINE THE FIRST LED 
        if(command == 'A' || command == 'a'){
            digitalWrite(First_Led , 1);
            Serial.println("TURN ON THE FIRST LED ! ");
        }

        else if (command == 'B' || command == 'b'){
            digitalWrite(First_Led , 0);
            Serial.println("TURN OFF THE SECOND LED ! ");
        }

        // DEFINE THE SECOND LED 
        else if(command == 'C' || command == 'c'){
            digitalWrite(Second_Led , 1);
            Serial.println("TURN ON THE SECOND LED ! ");
        }

        else if (command == 'D' || command == 'd'){
            digitalWrite(Second_Led , 0);
            Serial.println("TURN OFF THE SECOND LED ! ");
        }

        // DEFINE THE THIRD LED 
        else if (command == 'E' || command == 'e'){
            digitalWrite(Third_Led , 1);
            Serial.println("TURN ON THE THIRD LED ! ");
        }

        else if (command == 'F' || command == 'f'){
            digitalWrite(Third_Led , 0 );
            Serial.println("TURN OFF THE THIRD LED ! ");
        }


        
    }

}