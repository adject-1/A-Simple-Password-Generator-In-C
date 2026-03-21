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

    printf("Started genPass funct\n");  /* Debug print statements */

    char* passwd = malloc((size+1) * sizeof(char));
    if (passwd == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < size ; i++) {
        int code = rand() % (MAX + 1 - MIN) + MIN;
        passwd[i] = (char)code;
    }

    passwd[size] = '\0';

    printf("Generated Passwd\n\n");     /* Debug print statements */

    for (int i = 0; i< size; i++) {
        printf("%c", passwd[i]);
    }

    free(passwd);

    printf("Ended genPass funct\n");    /* Debug print statements */

    printf("\n");
}
