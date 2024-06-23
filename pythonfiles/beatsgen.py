import random
from random import randint
info = [["night", "136", "162"], ["ASMRZ", "130", "149"], ["blingbling", "157", "172"], ["magnetic", "131", "138"],
        ["night_dancer", "117", "210"], ["racing_night", "130", "261"], ["unforgiven", "104", "189"],
        ["waiting_for_love", "128", "230"]]
for song in range(len(info)):
    '''song_name = input("Enter song name: ")
    bpm = int(input("Enter bpm: "))
    seconds = int(input("Enter seconds: "))'''
    song_name = info[song][0]
    bpm = int(info[song][1])
    seconds = int(info[song][2])
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