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

char* generatePassword(int size){

    printf("\n\nStarted genPass funct\n\n");  /* Debug print statements */

    char* passwd = malloc((size+1) * sizeof(char));
    if (passwd == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    printf("Memory allocated");

    for (int i = 0; i < size ; i++) {
        int code = rand() % (MAX + 1 - MIN) + MIN;
        passwd[i] = (char)code;
    }

    printf("\n\nGenerated Passwd\n\n");     /* Debug print statements */

    passwd[size] = '\0';
    return passwd;
}

void display(char *passwd){

    int i = 0;

    if (passwd == NULL) {
        printf("Password Did not generated\n");
        return;
    }

    while (passwd[i] != '\0') {
        printf("%c", passwd[i++]);
    }

    printf("\n\n");

}
