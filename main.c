#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "passwd.h"

// ASCII printable characters range from (32 - 127)
//
int main(){

    int size = takeInput();

    srand(time(NULL));

    char *passwd = generatePassword(size);

    display(passwd);

    free(passwd);

    return 0;
}
