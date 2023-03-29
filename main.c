#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "displayWord.c"
#include "wordList.c"
#include "utils.c"
// this is the code for a word guessing game1

// all words are declared in easy words

int main()
{
    // printf("words %s \n", easyWords[0]);
    char guessedWord[20] = "__________";
    char guessedLetter = ' ';
    char userName[10] = "";

    int play = 1;
    int selection;
    int score = 0;
start:

    printf("\n ****************************************************\n");
    printf("Hello. Welcome to group 19 C Programming Assignment. \n This is a WORD GUESSING GAME \n");
    printf("\n ****************************************************\n");

    printf("\t 1. Start game \n \t 2. Check your score \n ");
    char userEntry = ' ';

    scanf("%c", &userEntry);
    switch (userEntry) /* code */
    {
    case '1':
        printf("\n Great your game is about to begin \n ");
        printf("To ask for a hint type 4 \n");
        printf("To quit press 0 \n");
        printf("\nType your name to start \n");

        scanf(" %s", userName);
        switch (*userName)
        {
        case '4':
            goto begin;
            break;

        default:
            break;
        }
        break;

    case '2':
        printf("\n Your score is %d \n", score);
        printf("Press 1 to go back \n");
        goto start;
        break;
    default:
        goto start;
        break;
    }

begin:
    do
    {

        char *activeWord = easyWords[3];
        printf("Guess a letter in the word\n");

        scanf(" %c", &guessedLetter);

        struct RValues result = checkIfLetterInWord(guessedLetter, &activeWord);
        if (result.valueFound == 1)

        {
            printf("\n CORRECT \n ");
            for (int i = 0; i < result.indexLength; i++)
            {
                score += 5;
                guessedWord[result.index[i]] = guessedLetter;
            }
            printf("%s \n", guessedWord);
            printf("SCORE: %d \n \n", score);
        }
        else
        {
            printf("Sorry please try again \n\n");
        }

        if (strcmp(guessedWord, activeWord) == 0)
        {
            printf("YOU HAVE SUCCESSFULLY GUESSED THE WORD\n");
            printf("SCORE: %d \n \n", score);
            goto replay;
        }

    replay:
        printf("Congratulations %s, you have succesfully guessed the word\n", userName);
        printf("Press 1 to play again");
        scanf(" %c", &userEntry);
        switch (userEntry)
        {
        case '1':
            goto start;
            break;

        default:
            break;
        }

    } while (play == 1);
    return 0;
}
