# StarSaver backup program! [My Free time project]
Working, WORK IN PROGRESS, ONLY SUPPORTS A SINGLE DIRECTORYS FOR SEARCH AND SAVE, OH GOD ITS IN ALL CAPS. 
Files to be be used for backup with this program must have two symbols for it to find the correct file eg. [**Filename].txt
when someone needs to save backups by simply adding a symbol to the file, this symbol is then removed from within file in the saved directory
for the user allowing easier data saving, each cycle it will find the new files that have been added. 

    Compile command: clang++ main.cpp -Os -s --std=c++17 -lstdc++fs -o test1.1_02s

dreaming the night. 
  
    WHAT DOES IT DO: searches system directory recursively for a file(s) that has/have symbols as in
    > "[symbol][symbol]filename.txt" or "filename[symbol][symbol].txt" 
    (using the latter means symbol won't be removed in projects current state)
    This data is found by starsaver, copied, and then the symbol is removed from the filename in users requested location. 
    files are then Segregated through organization of file extension type. 
    
     Basically how it works. Simple but allows very very fast backup lookup without a bunch of hassle by the user. 
     This program was written with the user in mind, not for me or because.
     Ex.
        Found **filename.png
            Creating Directory named png
        Does the file not exist
            Copy file to png
            Remove symbol from **filename.png to filename.png 
        File exists
            Update existing file. 
              

    TODO(5): implementation of optimizing functions by implementing data lookups instead of iteration for example.
    TODO(4): Fix bug when symbol is moved from start to middle of filename.
          Causes the program to try and remove a symbol it cannot reach.
          Honestly should have thought of that first. 
    TODO(1): fix bug when using more then one save directory, and more than one search directory. 
    TODO(2): fix regex
    TODO(0): check to see if it will run on windows. 
    TODO(3): allow non-organized Data saving. 
    TODO:    I'm sure something else will come up after my code review so this is placeholder. 
    TODO:
    TODO: GET A LIFE. 
