#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "displayWord.c"
#include "wordList.c"
#include "utils.c"

// this is the code for a word guessing game1

// all words are declared in easy words

int main()
{
    // printf("words %s \n", easyWords[0]);
    srand(time(NULL));

    char guessedWord[20] = "";
    char guessedLetter = ' ';
    char userName[20] = "";

    int play = 1;
    int selection;
    int score = 0;
    char *activeWord;

start:

    printf("\n ****************************************************\n");
    printf("Hello. Welcome to group 19 C Programming Assignment. \n This is a WORD GUESSING GAME \n");
    printf("\n ****************************************************\n");

    printf("Please enter your name \n");
    scanf("%s", userName);
    printf("WELCOME, %s \n", userName);
    printf("1. Start game  \n");
    char userEntry = ' ';

    scanf(" %c", &userEntry);
    switch (userEntry) /* code */
    {
    case '1':
        printf("\n Great!.Your game is about to begin \n \n ");
        printf("1. Select a difficulty\n ");
        printf("2. To quit press 0 \n");
        printf("3. To ask for a hint during the game, enter 6 for CLUE \n");

        // printf("\nType your name to start \n");

        scanf(" %c", &userEntry);
        switch (userEntry)
        {
        case '2':
            goto end;
            break;

        case '1':
            printf("\n 1. Easy \n 2. Medium \n 3. Difficult \n");
            scanf(" %c", &userEntry);

            if (userEntry == '1')
            {
                activeWord = easyWords[rand() % (sizeof(easyWords) / sizeof(easyWords[0]))];
                generateDashes(activeWord, guessedWord);
                // check what size of easy words 0 does
            }
            if (userEntry == '2')
            {
                activeWord = mediumWords[rand() % (sizeof(mediumWords) / sizeof(mediumWords[0]))];
                generateDashes(activeWord, guessedWord);
            }

            if (userEntry == '3')
            {
                activeWord = difficultWords[rand() % (sizeof(difficultWords) / sizeof(difficultWords[0]))];
                generateDashes(activeWord, guessedWord);
            }
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

        // }
        while (strcmp(guessedWord, activeWord) != 0)
        {
            printf("\n Guess a letter in the word. \n");

            scanf(" %c", &guessedLetter);

            if (guessedLetter == '6')
            {
                provideClue(activeWord, guessedWord);
                goto begin;
            }

            struct RValues result = checkIfLetterInWord(guessedLetter, activeWord);

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
                printf("%s \n", guessedWord);
            }
        }

        printf("YOU HAVE SUCCESSFULLY GUESSED THE WORD\n");
        printf("SCORE: %d \n \n", score);
        play++;
        goto replay;

    replay:

        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
        printf("\n Congratulations %s, you have succesfully guessed the word %s\n", userName, guessedWord);
        printf("Your total score is %d \n", score);
        printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ \n$");

    end:
        printf("Gaem Ended \n");
        play++;

    } while (play == 1);
    return 0;
}
