import os

#create function to output file and dir to list
def find_files(filename, directory):
    result = []
#walk top-down from root
    for root, dir, files in os.walk(directory):
        #looks through files to find 'filename'
        #print(root)
        if filename in files:
            result.append(os.path.join(root, filename))
    return result

print('What files shall we find?')

file = input()

print(find_files(file, "C:"))
