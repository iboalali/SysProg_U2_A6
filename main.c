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
	
	
	
	
	char vorname[50];
	char nachname[50];
	
	while((fscanf(fp, "%s %s", vorname, nachname))!=EOF){
		personAmEndeHinzufuegen(vorname, nachname);
		printf("Name: %s %s\n", vorname, nachname);
	}
	
	printf("\n");
	
	printListe(head);
	
	fclose(fp);    
    printf("Datei geschlossen\n");
	
	

    return 0;
}