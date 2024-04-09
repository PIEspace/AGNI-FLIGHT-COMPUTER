import cv2
import numpy as np
import serial

# Define the Arduino serial port
arduino_port = "COM13"
baud_rate = 9600

# Open the serial port
arduino = serial.Serial(arduino_port, baud_rate)

# Function to preprocess the frame and get the hand mask
def get_hand_mask(frame):
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    lower_skin = np.array([0, 48, 80], dtype=np.uint8)
    upper_skin = np.array([20, 255, 255], dtype=np.uint8)
    mask = cv2.inRange(hsv, lower_skin, upper_skin)
    mask = cv2.erode(mask, None, iterations=2)
    mask = cv2.dilate(mask, None, iterations=2)
    return mask

# Function for gesture recognition
def get_hand_gesture(hand_mask):
    contours, _ = cv2.findContours(hand_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    if len(contours) > 0:
        contour = max(contours, key=cv2.contourArea)
        hull = cv2.convexHull(contour, returnPoints=False)
        defects = cv2.convexityDefects(contour, hull)
        if defects is not None:
            count_defects = 0
            for i in range(defects.shape[0]):
                s, e, f, d = defects[i, 0]
                start = tuple(contour[s][0])
                end = tuple(contour[e][0])
                far = tuple(contour[f][0])

                a = np.sqrt((end[0] - start[0]) ** 2 + (end[1] - start[1]) ** 2)
                b = np.sqrt((far[0] - start[0]) ** 2 + (far[1] - start[1]) ** 2)
                c = np.sqrt((end[0] - far[0]) ** 2 + (end[1] - far[1]) ** 2)
                angle = np.arccos((b ** 2 + c ** 2 - a ** 2) / (2 * b * c))
                if angle <= np.pi / 2:
                    count_defects += 1

            if count_defects == 0:
                return "rock"  # Fist
            elif count_defects == 1:
                return "one"  # One finger
            elif count_defects == 2:
                return "two"  # Two fingers
            elif count_defects == 3:
                return "three"  # Three fingers

    return "none"

# Capture video from the webcam
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    hand_mask = get_hand_mask(frame)
    gesture = get_hand_gesture(hand_mask)

    if gesture == "rock":
        arduino.write(b'd')
    elif gesture == "one":
        arduino.write(b'a')
    elif gesture == "two":
        arduino.write(b'b')
    elif gesture == "three":
        arduino.write(b'c')

    cv2.imshow('Frame', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
arduino.close()
