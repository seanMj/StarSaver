# StarSaver
FILES to be be used for backup with this program must have two symbols for it to find the correct file eg. [**Filename].txt
when someone needs to save backups by simply adding a symbol to the file, this symbol is then removed from within the saved directory for the user allowing easier data saving


Compile command: clang++ main.cpp -Os -s --std=c++17 -lstdc++fs -o test1.1_02s


dream
 * WHAT_IT_DOES: searches system directory for a file that has symbols as in > "[symbol][symbol]filename.txt" or "filename[symbol][symbol].txt"
                 This data is found, copied and then the symbol is removed from the file in users requested location. 
                 Then files are Segregated through organization of file extension type. 
              
