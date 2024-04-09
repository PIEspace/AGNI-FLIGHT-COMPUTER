# CONTROL THE LED USING GUI APPLICATION

import customtkinter
import pyttsx3
import serial


# define the pyttsx3 module 
Engine_Say = pyttsx3.init()
# change the voices 
voice = Engine_Say.getProperty('voices')
Engine_Say.setProperty('voice' , voice[1].id)

# define the function for pyttsx3 module
def Speak(Voice):
    Engine_Say.say(Voice)
    Engine_Say.runAndWait()

    

# define the serial monitor
Arduino_Port = 'COM13'
SerialMonitor = serial.Serial(Arduino_Port , 9600  , timeout=1)



# create a function to control the led 

# create a first function 
def First_Led_Function():
    print("TURN ON THE FIRST LED !")
    Speak("TURN ON THE FIRST LED")
    SerialMonitor.write(b'a')

# turn off the first led 
def Second_Led_Function():
    print("TURN OFF THE FIRST LED ")
    Speak("TURN OFF THE FIRST LED ")
    SerialMonitor.write(b'b')


#  turn on the second led  
def Third_Led_Function():
    print("TURN ON THE SECOND LED !")
    Speak("TURN ON THE SECOND LED")
    SerialMonitor.write(b'c')

# turn off the second led 
def Fourth_Led_Function():
    print("TURN OFF THE SECOND LED ")
    Speak("TURN OFF THE SECOND LED ")
    SerialMonitor.write(b'd')


#  turn on the third led  
def Fifth_Led_Function():
    print("TURN ON THE THIRD LED !")
    Speak("TURN ON THE THIRD LED")
    SerialMonitor.write(b'e')

# turn off the third led 
def Six_Led_Function():
    print("TURN OFF THE THIRD LED ")
    Speak("TURN OFF THE THIRD LED ")
    SerialMonitor.write(b'f')





customtkinter.set_appearance_mode("dark")
customtkinter.set_default_color_theme("green")

# define the main window 
Window = customtkinter.CTk()
# define the window title
Window.title("PIE.SPACE")
# define the window size 
Window.geometry("500x300")

# define the label 
First_Label = customtkinter.CTkLabel(Window , text="CONTROL THE LED USING GUI APPLICATION" , font=customtkinter.CTkFont("Bold" , 20))
First_Label.grid(padx = 20 , pady = 10)

# define the frame 
First_frame = customtkinter.CTkFrame(Window , width=300 , height=200)
First_frame.grid(  padx = 5 , pady = 5)


# define the button inside the frame 

# define the first led button 
First_Button = customtkinter.CTkButton(First_frame , text="TURN ON FIRST LED" , font=customtkinter.CTkFont("Arial" , 15) , command=First_Led_Function)
First_Button.grid(padx = 5 , pady = 20 , row = 1 , column = 0 )

Second_Button = customtkinter.CTkButton(First_frame , text="TURN OFF FIRST LED" , font=customtkinter.CTkFont("Arial" , 15) , command= Second_Led_Function)
Second_Button.grid(padx = 5 , pady = 5 , row = 1 , column = 1)


# define the second  led button 
Third_Button = customtkinter.CTkButton(First_frame , text="TURN ON SECOND LED" , font=customtkinter.CTkFont("Arial" , 15) , command= Third_Led_Function)
Third_Button.grid(padx = 5 , pady = 20 , row = 2 , column = 0 )

Fourth_Button = customtkinter.CTkButton(First_frame , text="TURN OFF SECOND LED" , font=customtkinter.CTkFont("Arial" , 15) , command=Fourth_Led_Function)
Fourth_Button.grid(padx = 5 , pady = 5 , row = 2 , column = 1)


# define the second  led button 
Fifth_Button = customtkinter.CTkButton(First_frame , text="TURN ON THIRD LED" , font=customtkinter.CTkFont("Arial" , 15) , command=Fifth_Led_Function)
Fifth_Button.grid(padx = 5 , pady = 20 , row = 3 , column = 0 )

Six_Button = customtkinter.CTkButton(First_frame , text="TURN OFF THIRD LED" , font=customtkinter.CTkFont("Arial" , 15) , command=Six_Led_Function)
Six_Button.grid(padx = 5 , pady = 5 , row = 3 , column = 1)




# define the mainLoop
Window.mainloop()
SerialMonitor.close()
