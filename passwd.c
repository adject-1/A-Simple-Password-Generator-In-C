#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "passwd.h"




#define MIN 33
#define MAX 126

int takeInput(){
    int strSize;
    printf("Enter the length of your password: ");
    scanf("%d", &strSize);
    return strSize;
}

void generatePassword(int size){

    printf("Started genPass funct\n");

    char* passwd = malloc(size * sizeof(char));
    if (passwd == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    srand(time(NULL));

    int index = 0;
    for (int i = 0; i < size ; i++) {
        int code = rand() % (MAX + 1 - MIN) + MIN;
        scanf("%c", &passwd[index++]);
    }

    for (int i = 0; i< size; i++) {
        printf("%c", passwd[i]);
    }

    printf("Ended genPass funct\n");

    printf("\n");
}
