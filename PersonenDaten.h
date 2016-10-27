#ifndef _PERSONENDATEN
#define _PERSONENDATEN

#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    struct node *succ;
    char *vorname;
    char *nachname;
};

node *head;

void printTest();
void personAmAnfangHinzufuegen(char *vorname, char *nachname);
void personAmEndeHinzufuegen(char *vorname, char *nachname);
void nodeAmAnfangHinzufuegen(node *n);
void nodeAmEndeHinzufuegen(node *n);
void printListe(node *liste);

#endif
