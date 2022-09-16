import random as rand
import time

letters = {
    1: "a",
    2: "b",
    3: "c",
    4: "d",
    5: "e",
    6: "f",
    7: "g",
    8: "h",
    9: "i",
    10: "j",
    11: "k",
    12: "l",
    13: "m",
    14: "n",
    15: "o",
    16: "p",
    17: "q",
    18: "r",
    19: "s",
    20: "t",
    21: "u",
    22: "v",
    23: "w",
    24: "x",
    25: "y",
    26: "z",
    27: " "}
hello_world_string = ""
i = 0
while hello_world_string != "hello world":
    o = 0
    while o < 12:
        random_num = rand.randint(1, 27)
        add_letter = letters[random_num]
        hello_world_string = hello_world_string + add_letter
        o = o + 1
    print(hello_world_string)
    #time.sleep(.060)
    if len(hello_world_string) > 11:
        hello_world_string = hello_world_string[:-1]
    if hello_world_string != "hello world":
        hello_world_string = ""
    i = i + 1

print("This took " + str(i) + " iterations")
