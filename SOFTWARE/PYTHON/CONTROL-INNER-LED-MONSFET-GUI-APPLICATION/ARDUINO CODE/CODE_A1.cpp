// control the inner led and monsfet using gui application

#include<Arduino.h>

// Define the inner led pinOut 
const int Inner_Led_One = PA1;
const int Inner_Led_Two = PA2;
const int Inner_Led_Three = PA3;

// Define the monsfet pinOut 
const int First_Monsfet = PC14;
const int Second_Monsfet = PC15;
const int Third_Monsfet = PA0;


char command ;

void setup(){
    // define the bud rate so in this case i am using 9600 bits per second 
    Serial.begin(9600);

    // define the pinMode
    pinMode(Inner_Led_One , OUTPUT);
    pinMode(Inner_Led_Two , OUTPUT);
    pinMode(Inner_Led_Three , OUTPUT);

    // define the pinMode
    pinMode(First_Monsfet , OUTPUT);
    pinMode(Second_Monsfet , OUTPUT);
    pinMode(Third_Monsfet , OUTPUT);

    // DEFINE THE COMMAND LINE BOTH FOR INNER LED AND MONSFET 
    
    // DEFINE THE FIRST LED 
    Serial.println("TURN ON THE FIRST LED PRESS = A ");
    Serial.println("TURN OFF THE FIRST LED PRESS = B ");


    // DEFINE THE SECOND LED 
    Serial.println("TURN ON THE SECOND LED PRESS = C ");
    Serial.println("TURN OFF THE SECOND LED PRESS = D ");

    // DEFINE THE THIRD LED 
    Serial.println("TURN ON THE THIRD LED PRESS = E ");
    Serial.println("TURN OFF THE THIRD LED PRESS = F ");


    // DEFINE THE MONSFET VALUES 
    // DEFINE THE FIRST MONSFET 
    Serial.println("TURN ON THE FIRST MONSFET PRESS = G ");
    Serial.println("TURN OFF THE SECOND MONSFET PRESS = H");

    // DEFINE THE SECOND MONSFET 
    Serial.println("TURN ON THE SECOND MONSFET PRESS = I");
    Serial.println("TURN OFF THE SECOND MONSFET PRESS = J ");

    // DEFINE THE THIRD MONSFET 
    Serial.println("TURN ON THE THIRD MONSFET PRESS = K ");
    Serial.println("TURN OFF THE THIRD MONSFET PRESS = L");

}


void loop(){

    if(Serial.available() > 0){

        command = Serial.read();
        
        // turn on and turn on and turn off first inner led 
        if(command == 'a' || command == 'A'){
            Serial.println("TURN ON THE FIRST LED ");
            digitalWrite(Inner_Led_One , 1);
        }

        else if (command == 'b' || command == 'B'){
            Serial.println("TURN OFF THE FIRST LED ");
            digitalWrite(Inner_Led_One , 0);

        }

        // turn on and turn off second inner led 
        else if (command == 'c' || command == 'C'){
            Serial.println("TURN ON THE SECOND LED ");
            digitalWrite(Inner_Led_Two , 1 );
        }

        else if (command == 'd' || command == 'D'){
            Serial.println("TURN OFF THE SECOND LED ");
            digitalWrite(Inner_Led_Two , 0);
        }

        // turn on and turn off third  inner led 
        else if (command == 'e' || command == 'E'){
            Serial.println("TURN ON THE THIRD LED ");
            digitalWrite(Inner_Led_Three , 1 );
        }

        else if (command == 'f' || command == 'F'){
            Serial.println("TURN OFF THE THIRD LED ");
            digitalWrite(Inner_Led_Three , 0);
        }


        // DEFINE THE MONSFET 

        // turn on and turn on and turn off first monsfet 
        else if(command == 'g' || command == 'G'){
            Serial.println("TURN ON THE FIRST MONSFET  ");
            digitalWrite(First_Monsfet , 1);
        }

        else if (command == 'h' || command == 'H'){
            Serial.println("TURN OFF THE FIRST MONSFET  ");
            digitalWrite(First_Monsfet , 0);

        }

        // turn on and turn off second monsfet  
        else if (command == 'i' || command == 'I'){
            Serial.println("TURN ON THE SECOND MONSFET  ");
            digitalWrite(Second_Monsfet , 1 );
        }

        else if (command == 'j' || command == 'J'){
            Serial.println("TURN OFF THE SECOND MONSFET  ");
            digitalWrite(Second_Monsfet , 0);
        }

        // turn on and turn off third  MONSFET  
        else if (command == 'k' || command == 'K'){
            Serial.println("TURN ON THE THIRD MONSFET  ");
            digitalWrite(Third_Monsfet , 1 );
        }

        else if (command == 'l' || command == 'L'){
            Serial.println("TURN OFF THE THIRD MONSFET  ");
            digitalWrite(Third_Monsfet , 0);
        }


        

    }

}