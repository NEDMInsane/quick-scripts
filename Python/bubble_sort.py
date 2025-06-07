#!/bin/python3

from random import randint
# Create empty list of random values
unsorted = []
for i in range(1500):
    unsorted.append(randint(0,3000))
original_len = len(unsorted)
print(unsorted)
# Create min values
min_value = (0, unsorted[0])

# Create new empy list to store sorted entries
sorted_list = []

# Bubble sort
# Take the value, check to see if that value is the lowest.
# If that value is the lowest throughout the list, add it to the sorted list.
# Remove it from the unsorted list.
# Check for the next lowest value and repeat, until the list is in order.
while len(sorted_list) < original_len:
    for key, value in enumerate(unsorted):
        if value <= min_value[1]:
            min_value = (key, value)
    sorted_list.append(unsorted.pop(min_value[0]))
    if len(unsorted) > 0:
        min_value = (0, unsorted[0])

print(sorted_list)

