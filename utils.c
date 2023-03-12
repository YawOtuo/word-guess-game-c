#include <string.h>
#include <stdio.h>

int checkIfLetterInWord(char letter, char *word[])
{

    // printf("%s is the word of the string\n", *word);
    int length = strlen(*word);
    printf("%c is the letter that was entered", letter);

    for (int i = 0; i < strlen(*word); i++)
    {

        // printf("Memory address is  %d \n", word);
        // printf("Second Memory address is  %d \n", word[0]);

        // printf("First letter of word is %c \n", *(word[0] + i));
        if (*(word[0]+i) == letter)
        {
            printf("\n found letter \n \n");
            return 1;
        }
     
    };
    return 0;
}
