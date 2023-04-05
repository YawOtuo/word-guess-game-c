#include <string.h>
#include <stdio.h>

struct RValues
{
    int valueFound;
    int indexLength;
    int index[5];
};

struct RValues checkIfLetterInWord(char letter, char *word)
{
    struct RValues r;
    r.index[0] = 0;
    r.valueFound = 0;
    int length = strlen(word);
    int counter = 0;
    // printf("word is %c", *(word + 2));

    for (int i = 0; i < strlen(word); i++)
    {

        if (*(word + i) == letter)
        {
            r.valueFound = 1;
            r.index[counter] = i;
            counter++;
            r.indexLength = counter;
        }
    };

    return r;
}

void generateDashes(char *word, char *guessedWords)
{
    for (int i = 0; i < strlen(word); i++)
    {
        *(guessedWords + i) = '_';
    }
}

void provideClue(char *word, char *guessedWords)
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (*(word+i) != *(guessedWords+i)){
            printf("Clue: %c\n", *(word+i));
            return 1;
        }
    }
}