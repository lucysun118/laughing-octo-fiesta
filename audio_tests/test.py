"""
Audio recording script using PyAudio. Captures 5 seconds of stereo audio input, 
specified by the 'channels', 'rate', 'input_device_index', and 'frames_per_buffer'
parameters. Saves the recorded audio to a WAV file named 'audio-recording.wav' with
properties defined by 'setnchannels', 'setsampwidth', and 'setframerate' in the 
'wave' module. Adjustments can be made to parameters based on recording requirements.
"""

import pyaudio
import wave

# CHANNELS = 2
# RATE = 44100
# CHUNK = 4096
# FORMAT = pyaudio.paInt16

pa = pyaudio.PyAudio()

stream_in = pa.open(
    format = pyaudio.paInt16,
    channels = 2, 
    rate = 44100,
    input_device_index = 4,
    input = True,
    frames_per_buffer = 1024)

# read 5 seconds of the input stream
input_audio = stream_in.read(5 * 48000)

output_filename = 'audio-recording.wav'
wav_file = wave.open(output_filename, 'wb')

# define audio stream properties
wav_file.setnchannels(2)        # number of channels
wav_file.setsampwidth(2)        # sample width in bytes
wav_file.setframerate(48000)    # sampling rate in Hz

# write samples to the file
wav_file.writeframes(input_audio)