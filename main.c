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
	
	

    return 0;
}