from pydub import AudioSegment
import os

def convert_ogg_to_wav(directory):
    for filename in os.listdir(directory):
        if filename.endswith(".ogg"):
            ogg_file = os.path.join(directory, filename)
            wav_file = os.path.join(directory, filename.replace(".ogg", ".wav"))
            sound = AudioSegment.from_file(ogg_file, format="ogg")
            sound.export(wav_file, format="wav")
if __name__ == '__main__' :
    convert_ogg_to_wav("D:/OOP/2023s/teamproject/NecroDancer/NecroDancer/Resources/audio")