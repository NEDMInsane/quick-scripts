import os


def folder_finder(directory):
    #initialize Boolean variables
    running = True
    initialrun = True
    folderdeleted = False
    
    while running:
        if initialrun == True or folderdeleted == True:
            #After for loop is done, change folder deleted back for next run
            folderdeleted = False
            for root, dir, files in os.walk(directory):
                a = []
                #for f in files:
                #print(os.path.join(root, f) + ' was not deleted')

                try:
                    os.rmdir(root)
                    print('"' + root + '"' + ' was deleted!!!')
                    #Change boolean to run again (this could be done better)
                    folderdeleted = True
                except:
                    #just need the computer to do something.
                    a.append(files)
                    #print('Path isnt empty') #This is slow as balls.
            #Once the first run is done, change to False.
            initialrun = False
            
        elif initialrun == False and folderdeleted == False:
            running = False
            
    return 'complete!'
    

print('We are about to destroy some files are you ready?')
input()


print(folder_finder('C:'))
