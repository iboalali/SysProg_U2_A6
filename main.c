#include <stdio.h>
#include <stdlib.h>

#include "PersonenDaten.h"
#include "StringFuncs.h"

int main(int argc, char **argv){

    printListe(head);
    personHinzufuegen("Ibrahim", "Al-Alali"); // test for insertion in an empty list
    personHinzufuegen("Joshua", "Koenen"); // test for insertion in a list with one node
	personHinzufuegen("Nico", "Krösinger"); // test for the insertion after the second node
    personHinzufuegen("Lukas", "Nebelung"); // test for insert bertween
    personHinzufuegen("Jamal", "Al-Alali"); // test for a previously inserted name
	printListe(head);
	
	

    return 0;
}