#include "PersonenDaten.h"

void printTest(){
    printf("%s", "hello friend!\n");
}

void personHinzufuegen(char *vorname, char *nachname){
    node *n;
    n = malloc(sizeof(node));
    n->vorname = vorname;
    n->nachname = nachname;
    n->succ = NULL;

    nodeAmEndeHinzufuegen(n);
}

void nodeAmEndeHinzufuegen(node *n){
    if(head == NULL){
        head = n;
        return;
    }

    struct node *q;
    q = head;

    while(q->succ != NULL){
        q = q->succ;
    }

    q->succ = n;
}

void printListe(node *liste){
    struct node *q;
    q = liste;

    if(q == NULL){
        printf("%s\n", "Liste ist Leer");
        return;
    }

    while(q != NULL){
        printf("%s %s\n", q->vorname, q->nachname);
        q = q->succ;
    }
}