import requests
from secret_api import *

filename = "/Users/ankitmaskara/Desktop/sounds/YAF_wire_sad.wav"
audio_url = upload(filename)

save_transcript(audio_url, 'file_title')