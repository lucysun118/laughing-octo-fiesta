import time
import serial
import subprocess
import webbrowser
from scale_vals import scale_values
#from musenet_code import text_to_midi

ser = serial.Serial(port="/dev/tty.usbserial-110", baudrate=115200, timeout=5)

time.sleep(0.5)

# Initialize variables
e, n, m, t, u, r, j = 0, 0, 0, 0, 0, 0, 0
command_executed = False

def read_line():
    try:
        return ser.readline().decode('utf-8').strip()
    except UnicodeDecodeError as e:
        print(f"UnicodeDecodeError: {e}")
        return ""

while True:
    elapsed_time_val = read_line()
    print(f"raw val: {elapsed_time_val}")

    # Check the first two characters of the incoming serial data
    prefix = elapsed_time_val[:2]

    # Assign values based on the prefix
    if prefix == "e:":
        e = int(elapsed_time_val[2:])
    elif prefix == "n:":
        n = int(elapsed_time_val[2:])
    elif prefix == "m:":
        m = int(elapsed_time_val[2:])
    elif prefix == "t:":
        t = int(elapsed_time_val[2:])
    elif prefix == "u:":
        u = int(elapsed_time_val[2:])
    elif prefix == "r:":
        r = int(elapsed_time_val[2:])
    elif prefix == "j:":
        j = int(elapsed_time_val[2:])

    print(f"e: {e}, n: {n}, m: {m}, t: {t}, u: {u}, r: {r}, j: {j}")

    # Check if all variables are set
    if all((e, n, m, t, u, r, j)):
        # Run the command with the stored values
        command = ["/Users/lucysun/laughing-octo-fiesta/serial_read/musenet_code/text_to_midi.py",
                   "-e", str(e), "-n", str(n), "-m", str(m), "-t", str(t), "-u", str(u), "-r", str(r), "-j", str(j)]

        subprocess.run(["/usr/local/bin/python3"] + command)

        # Open the HTML page with the generated MIDI file in a web browser
        webbrowser.open('midi_notes.html', new=2)

        # Reset variables
        e, n, m, t, u, r, j = 0, 0, 0, 0, 0, 0, 0
        command_executed = True

    elif command_executed:
        # Reset variables if the command has been executed and not all variables are set
        e, n, m, t, u, r, j = 0, 0, 0, 0, 0, 0, 0
        command_executed = False

ser.close()