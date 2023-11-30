# larger ambient noise levels result in movement of servos at higher GPIO pin numbers
# the servo index is determined based on the noise level, and the servo at that index is moved accordingly. 

import sounddevice as sd
import numpy as np
from adafruit_servokit import ServoKit

# Initialize the PCA9685 servo controller
kit = ServoKit(channels=16)

# Function to map a value from one range to another
def map_value(value, in_min, in_max, out_min, out_max):
    return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

# Number of servos
num_servos = 16

# Callback function for audio input
def audio_callback(indata, frames, time, status):
    if status:
        print(f"Error in audio input: {status}")
        return

    # Calculate the root mean square (RMS) of the audio signal
    rms = np.sqrt(np.mean(indata**2))

    # Map RMS value to servo index
    servo_index = int(map_value(rms, 0, 0.1, 0, num_servos - 1))

    # Set the angle based on servo index
    kit.servo[servo_index].angle = int(map_value(rms, 0, 0.1, 0, 180))

# Set up audio stream
with sd.InputStream(callback=audio_callback):
    print("Listening for ambient noise and sounds...")

    try:
        sd.sleep(1000000)  # Run the program for a long duration
    except KeyboardInterrupt:
        print("Program terminated by user.")
