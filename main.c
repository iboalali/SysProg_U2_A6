#include <stdio.h>
#include <stdlib.h>

#include "PersonenDaten.h"
#include "StringFuncs.h"

int main(int argc, char **argv){
    
    printTest();

    printListe(head);
    personHinzufuegen("Ibrahim", "Al-Alali");
    printListe(head);
    personHinzufuegen("Joshua", "Koenen");
    printListe(head);
	personHinzufuegen("Nico", "Krösinger");
	printListe(head);
	
	

    return 0;
}