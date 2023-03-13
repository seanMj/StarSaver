# StarSaver backup program! [My Free time project]
someone knows something I dont... i could feel it... somewhere somehow i missed something, somewhere.. 

Working, WORK IN PROGRESS, ONLY SUPPORTS A SINGLE DIRECTORYS FOR SEARCH AND SAVE, OH GOD ITS IN ALL CAPS. 

Files to be be used for backup with this program must have two symbols for it to find the correct file eg. [**Filename].txt
when someone needs to save backups by simply adding a symbol to the file, this symbol is then removed from within file in the saved directory
for the user allowing easier data saving, each cycle it will find the new files that have been added. 
-
    Compile:
    clang++ main.cpp        --std=c++17 -lstdc++fs -o StarSaver                   #Size: ~645K
    
    Compile:
    clang++ main.cpp -Os -s --std=c++17 -lstdc++fs -o StarSaver                   #Size: ~129K
    
    Compile:
    clang++ main.cpp -O1 -s --std=c++17 -lstdc++fs -o StarSaver                   #Size: ~161K
    
    Compile: 
    clang++ main.cpp -O2    --std=c++17 -lstdc++fs -o StarSaver                   #Size: ~221K
    
    Compile:
    clang++ main.cpp -O0 -g --std=c++17 -lstdc++fs -o StarSaver                   #Size: ~1.7MB
    
    Using UPX idk i was curious (how low can you go type of thing):
    Compile:
    clang++ main.cpp -O2 -s --std=c++17 -lstdc++fs -o StarSaver                   #Size: 61K

-
dreaming the night. 
- 
    WHAT DOES IT DO: searches system directory recursively for a file(s) that has/have symbols as in
    > "[symbol][symbol]filename.txt" or "filename[symbol][symbol].txt" 
    (using the latter means symbol won't be removed in projects current state)
    This data is found by starsaver, copied, and then the symbol is removed from the filename in users requested location. 
    files are then Segregated through organization of file extension type. 
 -   
     Basically how it works. Simple but allows very very fast backup lookup without a bunch of hassle by the user. 
     
This program was written with the user in mind, not for me or because.

    [+] Searching for Files:
    
    [+] Found **filename.png
    
    [+] Creating Directory named png
    
        [-] Does the file not exist
    
    [+] Copy file to png
    
    [+] Remove symbol from **filename.png to filename.png 
    
        [-] File exists
    
    [+] Update existing file.
