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
	char name[20];
    printf("Welche Datei soll geöffnet werden: ");
    scanf("%s", name);

	head =NULL;
	
	fp = fopen(name, "r");
    if(fp == NULL)
    {
        printf("Datei wurde nicht gefunden");
        return 1;
    }
	
	char vorname[50];
	char nachname[50];


	while((fscanf(fp, "%99s %99s", vorname, nachname))!=EOF){  
		char *temp1 = malloc(50);
		char *temp2 = malloc(50);
		int i;
		for(i=0;i<50;i++){
			temp1[i] = vorname[i];
			temp2[i] = nachname[i];
		}
		
		personAmEndeHinzufuegen(temp1, temp2);             
		printf("Name: %s %s\n", temp1, temp2);
		printListe(head);
	}

	printf("\n");

	printListe(head);

	fclose(fp);
    printf("Datei geschlossen\n");
	
	freeList(head);
	printf("Liste leer\n");
	printListe(head);

    return 0;
}
