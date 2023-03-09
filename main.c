#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "displayWord.c"
#include "wordList.c"
#include "utils.c"
// this is the code for a word guessing game
// all words are declared in easy words

int main()
{
    printf("Hello world!\n");
    printf("words %s", easyWords[2]);

    // start the program while user says play
    int play = 0;
    // do
    // {
    printf("Press 1 to start the game \n");
    scanf("%d", &play);

    // select a word from the word list
    char greetings[] = "Hello World!";

    // char activeWord[] = easyWords[1];

    char *activeWord = easyWords[0];
    char guessWord[] = "";
    char guessedLetter[] = "";
    printf("%s\n", activeWord);

    printf("Guess a letter in the word\n");
    scanf("%s", &guessedLetter);
    printf("you entered %s\n", guessedLetter);

    int result = checkIfLetterInWord(guessedLetter, guessWord);
    printf("%d\n", result);
    // printf("%s", guessWord);

    // } while (play == 1);

    printf("\n");
    printf("\n");

    printf("\n");
    return 0;
}
