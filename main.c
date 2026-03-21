#include <stdio.h>
#include "passwd.h"

// ASCII printable characters range from (32 - 127)
//
int main(){

    int size = takeInput();
    printf("%d\n", size);

    generatePassword(size);

    return 0;
}
