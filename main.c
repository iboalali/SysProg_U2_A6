#include <stdio.h>
#include <stdlib.h>

#include "PersonenDaten.h"
#include "StringFuncs.h"

int main(int argc, char **argv){

    printTest();

    printListe(head);
    personAmAnfangHinzufuegen("Ibrahim", "Al-Alali");
    printListe(head);
    personAmAnfangHinzufuegen("Joshua", "Koenen");
    printListe(head);
	personAmEndeHinzufuegen("Nico", "Krösinger");
	printListe(head);

	FILE* fp;
    printf("Welche Datei soll geöffnet werden: ");
    scanf("%s", name);

	head =NULL;

	fp = fopen(name, "r");
    if(fp == NULL)
    {
        printf("Datei wurde nicht gefunden");
        return 1;
    }




	char *vorname;
	char *nachname;

	while((fscanf(fp, "%99s %99s", vorname, nachname))!=EOF){  //man kann strings auch so einlesen
		personAmEndeHinzufuegen(vorname, nachname);              //das heißt "bis 100 chars" (0-99) ;)
		printf("Name: %s %s\n", vorname, nachname);
	}

	printf("\n");

	printListe(head);

	fclose(fp);
    printf("Datei geschlossen\n");



    return 0;
}
