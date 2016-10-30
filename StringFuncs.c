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

	int fstr_l;    //Länge vom ersten String
	int sstr_l;    //Länge vom zweiten String
	int shorter;   //Länge vom kürzeren String
	int i = 0;     //Laufvariable

	fstr_l = mystrlen(first_str);
	sstr_l = mystrlen(second_str);
	if (fstr_l < sstr_l) shorter = fstr_l;
	else shorter = sstr_l;

	if (first_str[i] < second_str[i]) return 1;                //Trivial-Fall 1: Der Anfangstbuchtabe von Name 1 kommt vor 2
	else if (first_str[i] > second_str[i]) return -1;          //Trivial-Fall 1: Der Anfangstbuchtabe von Name 2 kommt vor 1
	else  {
		while (first_str[i] == second_str[i] && i < shorter) {   //So lange laufen lassen bis die Buchstaben sich unterscheiden oder shorter erreicht ist
			i++;
		}
	}
	if (first_str[i] < second_str[i]) return 1;          //Buchstaben an den stellen vergleichen
	else if (first_str[i] > second_str[i]) return -1;    //Eventuell sind sie bis i gleich aber einer ist kürzer
	else return 0;                                       //Wenn beide gleich sind
}

/*
  toLower:
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
 			str_l[i] = str[i] + 32;       //32 addieren (siehe auch ASCII-Tabelle)
			i++;
		}
		else {
			str_l[i] = str[i];           //Ansonsten wir er Buchstabe übernommen
			i++;
			continue;
		}
	}
	str_l[i] = '\0';                //Null-char noch einfügen
	return str_l;
}
