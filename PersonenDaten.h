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

// head of the list
node *head;

// always updated count of the nodes in the list (node *head);
int node_count;

void printTest();
void personHinzufuegen(char *vorname, char *nachname);
void nodeSortiertHinzufuegen(node *n);
void nodeAmAnfangHinzufuegen(node *n);
void nodeAmEndeHinzufuegen(node *n);
void printListe(node *liste);

#endif
