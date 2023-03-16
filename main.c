#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "displayWord.c"
// #include "wordList.c"
#include "utils.c"
// this is the code for a word guessing game1

// all words are declared in easy words
char easyWords[][10] = {"Happy", "Sad", "Glad"};

int main()
{
    printf("words %s \n", easyWords[0]);
    char guessedWord[10] = "__________";
    char guessedLetter = ' ' ;

    // start the program while user says play

    
    int play = 1;

    do
    {

        // printf("Press 1 to start/continue the game \n");
        // scanf("%d", &play);

        char *activeWord = easyWords[1];

        // printf("%s\n", activeWord);

        printf("Guess a letter in the word\n");

        scanf(" %c", &guessedLetter);
        printf("you entered %c\n", guessedLetter);

        struct RValues result = checkIfLetterInWord(guessedLetter, &activeWord);
        if (result.valueFound == 1)
        {
            printf("index is %d\n", result.index);
            // strncat(guessedWord, &guessedLetter, 1);
            guessedWord[result.index] = guessedLetter;

            printf("%s  \n", guessedWord);
        }
        else
        {
            printf("Sorry pleae try again \n\n");
        }

        if (strcmp(guessedWord, activeWord) == 0)
        {
            printf("YOU HAVE SUCCESSFULLY GUESSED THE WORD\n");
        }
        else
        {
            printf("Keep going bro, you ve got htis\n");
        }


    } while (play == 1);
    return 0;
}
