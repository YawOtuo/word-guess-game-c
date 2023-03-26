#include <string.h>
#include <stdio.h>

struct RValues
{
    int valueFound;
    int indexLength;
    int index[5];
};

struct RValues checkIfLetterInWord(char letter, char *word[])
{
    struct RValues r;
    r.index[0] = 0;
    r.valueFound = 0;
    // printf("%s is the word of the string\n", *word);
    int length = strlen(*word);
    // printf("%c is the letter that was entered", letter);
    int counter = 0;

    for (int i = 0; i < strlen(*word); i++)
    {

        if (*(word[0] + i) == letter)
        {
            r.valueFound = 1;
            r.index[counter] = i;
            counter++;
            r.indexLength = counter;
        }
    };

    return r;
}
