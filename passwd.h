#ifndef PASSWD
#define PASSWD

#define MIN 33
#define MAX 126

int takeInput();
char* generatePassword(int size);
void display(char *passwd);
void entropy(char *passwd, int size);
// int* probability(char *passwd, int size);

#endif
