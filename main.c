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
    char guessedWord[10] = "";
    char guessedLetter = ' ' ;

    // start the program while user says play
    int play = 0;

    do
    {

        printf("Press 1 to start/continue the game \n");
        scanf("%d", &play);

        char *activeWord = easyWords[0];

        // printf("%s\n", activeWord);

        printf("Guess a letter in the word\n");

        scanf(" %c", &guessedLetter);
        printf("you entered %c\n", guessedLetter);

        int result = checkIfLetterInWord(guessedLetter, &activeWord);

        printf("%d is the result of the function \n", result);

        if (result == 1)
        {
            strncat(guessedWord, &guessedLetter, 1);
            printf("%s  \n", guessedWord);
        }
        else
        {
            printf("%s is the guessed Word \n \n ", guessedWord);
        }

        printf("%d\n", strcmp(guessedWord, activeWord));
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
