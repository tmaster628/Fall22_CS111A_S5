#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>

const char *FILE_NAME_IN = "book.txt";
const char *FILE_NAME_OUT = "res.txt";
const char *CAT = "cat";


#define buf_sz 1024

/**
 * Cats and Bats
 * -------------
 *  The purpose of this program is to give you more practice with system
 *  calls in C.
 *
 *  Your task is to read in a provided file "book.txt," locate all instances
 *  of the word "cat," and write a new version of the file to "res.txt." 
 *  where all instances of "cat" are changed to "bat."
 *
 *  A few notes about the problem:
 *  - You may assume that book.txt exists and is a valid text file
 *  - We have provided the name res.txt as the constant "FILE_NAME_OUT."
 *    You may not assume that res.txt does not exist already in the folder.
 *  - We have also provided the name book.txt as the constant
 *    "FILE_NAME_IN." You may asssume the function takes in no arguments.
 *  - CAT shold be case insensitive -- the case should be the same between
 *    text files (i.e. CAT -> BAT; cAt -> bAt).
 *  - As a final hint, this program will look a lot like the copy solution
 *    code from /afs/ir/class/cs111/lecture-code/lect5 directory. Feel free
 *    to keep that open as reference.
*/
int main (int argc, char *argv[]) {
    int outFD = open(FILE_NAME_OUT, O_TRUNC | O_CREAT | O_RDWR, 0777);
    int inFD = open(FILE_NAME_IN, O_RDONLY);

    char buf[buf_sz];

    while (true) {
        ssize_t bytesRead = read(inFD, buf, sizeof(buf));
        if (bytesRead == 0) break;

        // loop looking for "cat"
        for (size_t i = 0; i < bytesRead - 3; i++) {
            if (strncasecmp(CAT, buf + i, strlen(CAT)) == 0) {
                buf[i] = buf[i] - 1; // subtract ascii value by 1


            } 
        }

        size_t bytesWritten = 0;
        while (bytesWritten < bytesRead) {
            ssize_t count = write(outFD, buf + bytesWritten, bytesRead - bytesWritten);
            bytesWritten += count;
        }
    }
    close (inFD);
    close (outFD);
    return 0;
}
