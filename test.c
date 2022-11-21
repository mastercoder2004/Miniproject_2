#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE* textfile;  //creates a variable to call and manipulate the file
    char character;
    textfile=fopen("../../../Downloads/path_tester.txt", "r");    //opens the file to read when given the relative path
    do
    {
        character = fgetc(textfile); //gets a single character
        printf("%c", character);
    }
    while (character != EOF);
    return 0;
}