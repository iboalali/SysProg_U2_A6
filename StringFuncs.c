/*
    Noch zu implementieren:
    -Strings kopieren (?)
*/

#include "StringFuncs.h"

int mystrlen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

/**
    namemcp return:
    0: Namen sind exakt gleich
    1: fname kommt vor sname
   -1: sname kommt fname
**/

int namecmp(char *first_str, char *second_str) {

    int fname_l;
    int sname_l;
    int shorter;
    int i;

    fname_l = mystrlen(first_str);
    sname_l = mystrlen(second_str);
    if(fname_l < sname_l) shorter = fname_l;
    else shorter = sname_l;

    if(first_str[i] < second_str[i]) return 1;
    else if(first_str[i] == second_str[i]) {
        for(i = 0; i < shorter; i++) {
            if (first_str[i] == second_str[i]) continue;
        }
    }
    else return -1;
}

int strlenWort(char* str){
	int i=0;
	
	while (*str!='\0')
    {		
		if(*str==' '){
			return i;
		}	
		else{
			i++;
			str++;
		}
    }
    return i-2;
}

int strlenOhneLeerzeichen(char* str){
	int i=0;
    while (*str!='\0')
    {
		if(*str == ' '){
			str++;
		}
		else{
			i++;
			str++;
		}
    }
    return i-2;
}

char *toLower(char *str) {
	//Groß-Buchstaben von 65-90
	//Klein-Buchstaben von 97-122
	int i = 0;
	int length = mystrlen(str);
	char *str_l = malloc(length);
	if (str_l == NULL) printf("Malloc failed");

	while (i < length) {
		if (str[i] <= 90) {
			str_l[i] = str[i] + 32;
			i++;
		}
		else {
			str_l[i] = str[i];
			i++;
			continue;
		}
	}
	str_l[i] = '\0';
	return str_l;
}