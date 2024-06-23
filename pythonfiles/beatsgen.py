import random
from random import randint
song_name = input("Enter song name: ")
bpm = int(input("Enter bmp: "))
seconds = int(input("Enter seconds: "))
buffer_lines = 0;
total_lines = 2*bpm*(seconds/60)

def generate_beats() -> str:
    beats = ""
    one_pos = random.randint(0, 3)
    for i in range(0, 4):
        if i == one_pos:
            beats += "1"
        else:
            beats += "0"
    return beats + "\n"

with open(song_name+".txt", "w") as f:
    for i in range(int(total_lines)):
        if(i < buffer_lines):
            f.write("0000\n")
            continue;
        if(i % 2 == 0):
            f.write(generate_beats())
        else:
            f.write("0000\n")