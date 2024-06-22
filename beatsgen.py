import random
from random import randint
bpm = int(input("Enter bmp: "))
seconds = int(input("Enter seconds: "))
total_lines = 2*bpm*seconds


def generate_beats() -> str:
    beats = ""
    one_pos = random.randint(0, 3)
    for i in range(0, 4):
        if i == one_pos:
            beats += "1"
        else:
            beats += "0"
    return beats + "\n"

with open("beats.txt", "w") as f:
    for i in range(total_lines):
        if(i % 2 == 0):
            f.write(generate_beats())
        else:
            f.write("0000\n")