# CONTROL THE INNER LED AND MONSFET USING GUI APPLICATION 

import pyttsx3
import customtkinter
import serial

# define the pyttsx3 
Engine_Say = pyttsx3.init()

# change the voice 
voices = Engine_Say.getProperty('voices')
Engine_Say.setProperty('voice' , voices[1].id)

# define the serial monitor
ArduinoPort = "COM13"
BudRate = 9600
SerialMonitor = serial.Serial(ArduinoPort , BudRate , timeout=1 )

# create a function for text to speech module 
def Speak (Voices):
    Engine_Say.say(Voices)
    Engine_Say.runAndWait()

# define the background and themes color
customtkinter.set_appearance_mode("dark")
customtkinter.set_default_color_theme("green")

# define the function for turn on and turn off the led 
def First_Led_Value ():
    print("TURN ON FIRST LED ")
    Speak("TURN ON FIRST LED ")
    SerialMonitor.write(b'a' )

def Second_Led_Value ():
    print("TURN OFF FIRST LED ")
    Speak("TURN OFF FIRST LED")
    SerialMonitor.write(b'b')


def Third_Led_Value ():
    print("TURN ON SECOND LED ")
    Speak("TURN ON SECOND LED ")
    SerialMonitor.write(b'c')

def Fourth_Led_Value ():
    print("TURN OFF SECOND LED ")
    Speak("TURN OFF SECOND LED")
    SerialMonitor.write(b'd')


def Fifth_Led_Value ():
    print("TURN ON THIRD LED ")
    Speak("TURN ON THIRD LED ")
    SerialMonitor.write(b'e')

def Six_Led_Value ():
    print("TURN OFF THIRD LED ")
    Speak("TURN OFF THIRD LED")
    SerialMonitor.write(b'f')



# define the function for MONSFET JUST TURN ON AND TURN OFF 
def First_Monsfet_Value ():
    print("TURN ON FIRST MONSFET ")
    Speak("TURN ON FIRST MONSFET ")
    SerialMonitor.write(b'g' )

def Second_Monsfet_Value ():
    print("TURN OFF FIRST MONSFET ")
    Speak("TURN OFF FIRST MONSFET")
    SerialMonitor.write(b'h')


def Third_Monsfet_Value ():
    print("TURN ON SECOND MONSFET ")
    Speak("TURN ON SECOND MONSFET ")
    SerialMonitor.write(b'i')

def Fourth_Monsfet_Value ():
    print("TURN OFF SECOND MONSFET ")
    Speak("TURN OFF SECOND MONSFET")
    SerialMonitor.write(b'j')


def Fifth_Monsfet_Value ():
    print("TURN ON THIRD MONSFET ")
    Speak("TURN ON THIRD MONSFET ")
    SerialMonitor.write(b'k')

def Six_Monsfet_Value ():
    print("TURN OFF THIRD MONSFET ")
    Speak("TURN OFF THIRD MONSFET")
    SerialMonitor.write(b'l')



# create a main window 
window = customtkinter.CTk()
# define the title
window.title('PIE.SPACE(AGNI FLIGHT COMPUTER VERSION TWO )')
# define the window size 
window.geometry("700x700")

# define the label 
First_Label = customtkinter.CTkLabel(window , text="CONTROL THE INNER LED AND MONSFET USING GUI APPLICATION" , font=customtkinter.CTkFont("Arial" , 20))
First_Label.grid(padx = 10 , pady = 10 )

# define the frame 
First_Frame = customtkinter.CTkFrame(window , width= 400 , height=400)
First_Frame.grid(padx = 10 , pady =10 )

# define the button to control the inner led and monsfet 

Second_Label = customtkinter.CTkLabel(First_Frame , text="CONTROL THE LED " , font=customtkinter.CTkFont("Bold" , 20))
Second_Label.grid(padx = 10 , pady = 10 )

# define the first button to control the led 
First_Button = customtkinter.CTkButton(First_Frame , text="FIRST LED ON " , font=customtkinter.CTkFont("Bold" , 10) , command= First_Led_Value)
First_Button.grid(padx = 5 , pady = 5 , row = 1 , column = 0)

Second_Button = customtkinter.CTkButton(First_Frame , text="FIRST LED OFF" , font=customtkinter.CTkFont("Bold" , 10) , command= Second_Led_Value)
Second_Button.grid(padx = 5 , pady = 5 , row = 1 , column = 1 )

# define the second button to control the led 
Third_button = customtkinter.CTkButton(First_Frame , text="SECOND LED ON " , font=customtkinter.CTkFont("Bold" , 10) , command= Third_Led_Value)
Third_button.grid(padx = 5 , pady = 5 , row = 2 , column = 0 )

Fourth_ButtON = customtkinter.CTkButton(First_Frame , text="SECOND LED OFF " , font=customtkinter.CTkFont("Bold" ,10) , command= Fourth_Led_Value)
Fourth_ButtON.grid(padx = 5 , pady = 5, row = 2 , column = 1)


# define the third  button to control the led 
Fifth_button = customtkinter.CTkButton(First_Frame , text="THIRD LED ON " , font=customtkinter.CTkFont("Bold" , 10) , command=Fifth_Led_Value)
Fifth_button.grid(padx = 5 , pady = 5 , row = 3 , column = 0 )

Six_ButtON = customtkinter.CTkButton(First_Frame , text="THIRD LED OFF " , font=customtkinter.CTkFont("Bold" ,10) , command=Six_Led_Value)
Six_ButtON.grid(padx = 5 , pady = 5, row = 3 , column = 1)


# define the monsfet 

# define the label 
Third_Label = customtkinter.CTkLabel(First_Frame , text="CONTROL THE MONSFET  " , font=customtkinter.CTkFont("Bold" , 20))
Third_Label.grid(padx = 10 , pady = 10 )

Seven_Button = customtkinter.CTkButton(First_Frame , text="FIRST MONSFET ON " , font=customtkinter.CTkFont("Bold" , 10) , command= First_Monsfet_Value)
Seven_Button.grid(padx = 5 , pady = 5 , row = 6 , column = 0)

Eight_Button = customtkinter.CTkButton(First_Frame , text="FIRST MONSFET  OFF" , font=customtkinter.CTkFont("Bold" , 10) , command= Second_Monsfet_Value)
Eight_Button.grid(padx = 5 , pady = 5 , row = 6 , column = 1 )

# define the second button to control the led 
Nine_button = customtkinter.CTkButton(First_Frame , text="SECOND MONSFET ON " , font=customtkinter.CTkFont("Bold" , 10) , command= Third_Monsfet_Value)
Nine_button.grid(padx = 5 , pady = 5 , row = 7 , column = 0 )

Ten_ButtON = customtkinter.CTkButton(First_Frame , text="SECOND MONSFET OFF " , font=customtkinter.CTkFont("Bold" ,10) , command= Fourth_Monsfet_Value)
Ten_ButtON.grid(padx = 5 , pady = 5, row = 7, column = 1)


# define the third  button to control the led 
Eleven_button = customtkinter.CTkButton(First_Frame , text="THIRD MONSFET ON " , font=customtkinter.CTkFont("Bold" , 10) , command=Fifth_Monsfet_Value)
Eleven_button.grid(padx = 5 , pady = 5 , row = 8 , column = 0 )

Twelve_ButtON = customtkinter.CTkButton(First_Frame , text="THIRD MONSFET OFF " , font=customtkinter.CTkFont("Bold" ,10) , command=Six_Monsfet_Value)
Twelve_ButtON.grid(padx = 5 , pady = 5, row = 8 , column = 1)





# define the mainLoop
window.mainloop()
SerialMonitor.close()


    