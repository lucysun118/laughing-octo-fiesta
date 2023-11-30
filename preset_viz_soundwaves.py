import wave

wav_obj = wave.open('file.wav', 'rb')

sample_freq = wav_obj.getframerate()
