#include <string.h>


int checkIfLetterInWord(char* letter[], char* word[]){
    puts("code is here");
    int length = strlen(word);
    printf("%s", length);
    for(int i; i < strlen(word); i++){
        printf("%d", i);
        if (*word[i] == letter){
            printf("found letter\n");
            return 1;
        }
        else{
            puts("letter not present in word\n");
        }
    }
    return 0;
}