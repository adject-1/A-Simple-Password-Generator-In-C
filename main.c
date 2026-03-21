#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "passwd.h"

// ASCII printable characters range from (32 - 127)
//
int main(){

    int size = takeInput();
    printf("%d\n", size);

    srand(time(NULL));
    generatePassword(size);

    return 0;
}
