import speech_recognition as sr
import pyttsx3
import serial
import datetime

# Initialize the pyttsx3 engine
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[1].id)

# Function to speak
def speak(text):
    engine.say(text)
    engine.runAndWait()


# Define the Arduino serial port
arduino_port = "COM13"
baud_rate = 9600

# Open the serial port
serial_monitor = serial.Serial(arduino_port, baud_rate)

# Define the function for day
def hour_Wish():
    Hour = (datetime.datetime.now().hour)
    if  (Hour <= 0 or Hour <=12):
        print("Good Morning Sir")
        speak("Good Morning Sir")
    elif (Hour<=12 or Hour<=18):
        print("Good Afternoon Sir")
        speak("Good Afternoon Sir")
    else:
        print("Good Evening Sir")
        speak("Good Evening Sir")

# Define the speech recognizer
recognizer = sr.Recognizer()

# Set microphone sensitivity level
with sr.Microphone() as source:
    recognizer.adjust_for_ambient_noise(source)

hour_Wish()
while True:
    


    with sr.Microphone() as source:
        print("Listening...")
        recognizer.pause_threshold = 0.5
        audio = recognizer.listen(source, timeout=1, phrase_time_limit=5)

    try:
        print("Recognizing...")
        text = recognizer.recognize_google(audio)
        print(f"You said: {text}")

        if text == "turn on first LED" or text == "turn on first led":
            serial_monitor.write(b'a')
            speak("Turning on LED")

        elif text == "turn off first LED" or text  == "turn off first led":
            serial_monitor.write(b'b')
            speak("Turning off LED")

        elif text == "turn on second LED" or text  == "turn on second led":
            serial_monitor.write(b'c')
            speak("Turning on LED")

        elif text == "turn off second LED" or text  == "turn off second led":
            serial_monitor.write(b'd')
            speak("Turning off LED")

        elif text == "turn on third LED" or text  == "turn on third led":
            serial_monitor.write(b'e')
            speak("Turning on LED")

        elif text == "turn off third LED" or text  == "turn off third led":
            serial_monitor.write(b'f')
            speak("Turning off LED")
        
       
        


    except sr.UnknownValueError:
        print("Sorry, I could not understand what you said.")
        speak("Sorry, I could not understand what you said.")
    except sr.RequestError as e:
        print(f"Sorry, an error occurred: {e}")

# Close the serial port
serial_monitor.close()
