"""
Usage example: 

Run file with terminal command:
/Users/lucysun/laughing-octo-fiesta/serial_read/musenet_code/text_to_midi.py -e 7 -n 3 -m 8 -t 5 -u 6 -r 4 -j 9

"""

import time
import serial
import subprocess
import webbrowser  # Import the webbrowser module
from scale_vals import scale_values
from musenet_code import text_to_midi

ser = serial.Serial(port="/dev/tty.usbserial-110", baudrate=115200, timeout=5)

time.sleep(0.5)

def read_line():
    try:
        return ser.readline().decode('utf-8').strip()
    except UnicodeDecodeError as e:
        print(f"UnicodeDecodeError: {e}")
        return ""

while True:
    elapsed_time_val = read_line()
    print(f"raw val: {elapsed_time_val}")

    scaled_val = scale_values(elapsed_time_val)
    print(f"scaled val: {scaled_val}")

    # Run the other script with the scaled value as an argument
    subprocess.run(["/usr/local/bin/python3", "/Users/lucysun/laughing-octo-fiesta/serial_read/musenet_code/text_to_midi.py", "-e", str(scaled_val)])

    # Open the HTML page with the generated MIDI file in a web browser
    webbrowser.open('midi_notes.html', new=2)

ser.close()




