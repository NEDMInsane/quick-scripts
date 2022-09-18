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
hello_world_list = []
i = 0


def generate_string():
    num_iterations = 0
    proposed_string = ""
    while num_iterations < 11:
        random_num = rand.randint(1, 27)
        add_letter = letters[random_num]
        proposed_string = proposed_string + add_letter
        num_iterations = num_iterations + 1

    if proposed_string in hello_world_list:
        proposed_string = ""
        generate_string()
    elif proposed_string not in hello_world_list:
        hello_world_list.append(proposed_string)
        print(len(hello_world_list))
        return proposed_string


while hello_world_string != "hello world":
    hello_world_string = generate_string()
    print(hello_world_string)

print("This took " + str(i) + " iterations")
