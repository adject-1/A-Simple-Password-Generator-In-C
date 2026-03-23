#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// int* probability(char *passwd, int size){

// }

void entropy(char *passwd, int size){

    /*
        Shannon entropy formula: H(X)=−∑p(x)*log2p(x)
     */

    printf("Entropy function started: \n");

    float entropy = 0;
    float prob = 0;

    int *freqSymbol = malloc(256 * sizeof(int));
    memset(freqSymbol, 0, 256 * sizeof(int));

    for (int i = 0 ; i < size; i++) {
        int pos = (unsigned char)passwd[i];
        freqSymbol[pos] += 1;
    }

    for (int k = 0; k < 256; k++) {
        if (freqSymbol[k] > 0) {
            prob = (float)freqSymbol[k] / (float)size;
            entropy -= prob * log2(prob);
        }
    }

    printf("Entropy is: %.02f ", entropy);

    printf("Entropy function ended: \n");

    free(freqSymbol);
}
