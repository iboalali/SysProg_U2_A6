#ifndef _STRINGFUNCS
#define _STRINGFUNCS

#include <stdlib.h>
#include <stdio.h>

int namecmp(char *first_str, char *second_str);
int mystrlen(char *str);
int strlenWort(char* str);
int strlenOhneLeerzeichen(char* str);
char* toLower(char *str);

#endif
