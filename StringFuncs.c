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

/*
    namemcp return:
    0: Namen sind exakt gleich
    1: fname kommt vor sname
   -1: sname kommt fname
*/

int namecmp(char *first_str, char *second_str) {

	int fstr_l;
	int sstr_l;
	int shorter;
	int i = 0;

	fstr_l = mystrlen(first_str);
	sstr_l = mystrlen(second_str);
	if (fstr_l < sstr_l) shorter = fstr_l;
	else shorter = sstr_l;

	if (first_str[i] < second_str[i]) return 1;
	else if (first_str[i] > second_str[i]) return -1;
	else  {
		while (first_str[i] == second_str[i] && i < shorter) {
			i++;
		}
	}
	if (first_str[i] < second_str[i]) return 1;
	else if (first_str[i] > second_str[i]) return -1;
	else return 0;
}

/*
	Groß-Buchstaben von 65-90
	Klein-Buchstaben von 97-122
*/

char *toLower(char *str) {
	int i = 0;
	int length = mystrlen(str);
	char *str_l = malloc(length);
	if (str_l == NULL) printf("Malloc failed");

	while (i < length) {                 
		if (str[i] <= 90) {             //Wenn str[i] ein Groß-Buchstabe ist
 			str_l[i] = str[i] + 32;     //32 addieren (siehe auch ASCII-Tabelle)
			i++;
		}
		else {
			str_l[i] = str[i];
			i++;
			continue;
		}
	}
	str_l[i] = '\0'; //Null-char noch einfügen
	return str_l;
}