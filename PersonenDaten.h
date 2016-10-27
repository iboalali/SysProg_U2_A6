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
void personHinzufuegen(char *vorname, char *nachname);
void nodeAmEndeHinzufuegen(node *n);
void printListe(node *liste);

#endif