# StarSaver backup program!
Working, WORK IN PROGRESS, ONLY SUPPORTS A SINGLE DIRECTORYS FOR SEARCH AND SAVE, BUG USING MULTIPLES CURRENTLY. OH GOD ITS IN ALL CAPS. 
    Files to be be used for backup with this program must have two symbols for it to find the correct file eg. [**Filename].txt
when someone needs to save backups by simply adding a symbol to the file, this symbol is then removed from within file in the saved directory
for the user allowing easier data saving, each cycle it will find the new files that have been added. 

    Compile command: clang++ main.cpp -Os -s --std=c++17 -lstdc++fs -o test1.1_02s

dreaming
    WHAT DOES IT DO: searches system directory recursively for a file(s) that has/have symbols as in > "[symbol][symbol]filename.txt" or "filename[symbol][symbol].txt"
                 This data is found by starsaver, copied, and then the symbol is removed from the file in users requested location. 
                 files are then Segregated through organization of file extension type. 
              


    TODO: fix bug when using more then one save directory, and more than one search directory. 
    TODO: fix regex
    TODO: check to see if it will run on windows. 
    TODO: allow non-organized Data saving. 
    TODO: GET A LIFE. 
    TODO: FOUND A LIFE
    TODO: LOOSE THAT LIFE, BACK TO CODE. 
