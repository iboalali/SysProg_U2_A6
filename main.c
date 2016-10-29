#include <stdio.h>
#include <stdlib.h>

#include "PersonenDaten.h"
#include "StringFuncs.h"

#define ZEILENLAENGE 80

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
    char puffer[ZEILENLAENGE], name[20];	
    printf("Welche Datei soll geöffnet werden: ");
    scanf("%s", name);
	
	head =NULL;
	
	fp = fopen(name, "r");
    if(fp == NULL)
    {
        printf("Datei wurde nicht gefunden");
        return 1;
    }
	
	char* vname;
	char* nname;
	
	int i;
	int j;
	
	while(fgets(puffer, ZEILENLAENGE, fp)){
		
		// if(head==NULL){			
			// int vornamel;
			// vornamel = strlenWort(puffer);
			// int nachnamel = strlenOhneLeerzeichen(puffer+vornamel);
			
		
			
			
			// char vorname[vornamel];
			// char nachname[nachnamel];
			// int i;
			// for(i=0;i<vornamel;i++){
				// vorname[i] = puffer[i];
			// }
			
			// for(i=0;i<nachnamel;i++){
				// nachname[i] = puffer[vornamel+i+1];
			// }
			// personAmAnfangHinzufuegen(vorname, nachname);
			
			// printf("Vorname: %s\n", vorname);
		// printf("Nachname: %s\n", nachname);
		// }
		// else{
			// int vornamel;
			// vornamel = strlenWort(puffer);
			// int nachnamel = strlenOhneLeerzeichen(puffer+vornamel);
			

			// char vorname[vornamel];
			// char nachname[nachnamel];
			// int i;
			// for(i=0;i<vornamel;i++){
				// vorname[i] = puffer[i];
			// }
			// for(i=0;i<nachnamel;i++){
				// nachname[i] = puffer[vornamel+i+1];
			// }
			// personAmEndeHinzufuegen(vorname, nachname);
			
			// printf("Vorname: %s\n", vorname);
		// printf("Nachname: %s\n", nachname);
		// }
		
		fputs(puffer, stdout);
				
		int vornamel;
		vornamel = strlenWort(puffer);
		int nachnamel = strlenOhneLeerzeichen(puffer+vornamel);
		
		if(feof(fp)){
			printf("\n");
			nachnamel+=2;
		}
		printf("Anzahl Buchstaben Vorname: %d\n", vornamel);		
		printf("Anzahl Buchstaben Nachname: %d\n", nachnamel);
		
		printf("Vorname: ");
		for(i =0;i<vornamel;i++){
			printf("%c", puffer[i]);
		}
		
		j=nachnamel;
		printf("\nNachname: ");
		
		for(i=0;i<j;i++){
			if(puffer[i+vornamel]!=' '){
				printf("%c", puffer[i+vornamel]);
			}
			else if(puffer[i+vornamel]=='\0'){
				i=j;
			}
			else j++;
		}
        	
		printf("\n\n");
		
		
	}
	
	printListe(head);
	
	fclose(fp);    
    printf("Datei geschlossen\n");
	
	

    return 0;
}