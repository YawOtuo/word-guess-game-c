#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "displayWord.c"
// #include "wordList.c"
#include "utils.c"
// this is the code for a word guessing game1

// all words are declared in easy words
char easyWords[][10] = {"Happy", "Sad", "Glad", "Shabalala"};

int main()
{
    // printf("words %s \n", easyWords[0]);
    char guessedWord[10] = "_________";
    char guessedLetter = ' ';

    int play = 1;
    int selection;
    int score = 0;

    // switch (selection)
    // {
    // //check your score/
    // // change difficulty
    // // quit
    // case /* constant-expression */:
    //     /* code */
    //     break;

    // default:
    //     break;
    // }

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
        }
        else
        {
            printf("Keep going bro, you ve got htis\n");
        }

    } while (play == 1);
    return 0;
}
