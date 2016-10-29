#include "PersonenDaten.h"
#include "StringFuncs.h"

void personHinzufuegen(char *vorname, char *nachname){
    node *n;
    n = malloc(sizeof(node));
    n->vorname = vorname;
    n->nachname = nachname;
    n->succ = head;

    nodeSortiertHinzufuegen(n);
}

void nodeSortiertHinzufuegen(node *n){
    if (head == NULL){
        nodeAmAnfangHinzufuegen(n);
        return;
    }

    node *p; // head location
    node *q; // head location + 1
    p = head; 
    q = head->succ;

    if(node_count == 1){
        if (namecmp(n->nachname, head->nachname) == 1){
            // Neuer Name kommt vor den derzeitigen Name in der liste
            nodeAmAnfangHinzufuegen(n);
        }
        else if(namecmp(n->nachname, head->nachname) == 0){
            // Neuer Name is exakt gleich

            // Vorname vergleichen

            //nodeAmEndeHinzufuegen(n);
        }
        return;
    }

    // if there are more nodes than one
    while (q->succ != NULL){
        if (namecmp(n->nachname, p->nachname) == 1){
            // Neuer Name kommt vor den derzeitigen Name in der liste
            p->succ = n;
            n->succ = q;
            return;
        }else if(namecmp(n->nachname, p->nachname) == 0){
            // Der Name is exakt gleich

            // Vorname vergleichen
        }
        p = q;
        q = q->succ;

    }

    // gone through the whole list, just add to the end
    nodeAmEndeHinzufuegen(n);
}

void nodeAmAnfangHinzufuegen(node *n){
    if (head == NULL){
        head = n;
        node_count = 1;
    }
    else{
        n->succ = head;
        head = n;
        node_count++;
    }
}

void nodeAmEndeHinzufuegen(node *n){
    if (head == NULL){
        head = n;
        node_count = 1;
        return;
    }

    node *q;
    q = head;

    while (q->succ != NULL){
        q = q->succ;
    }
    node_count++;
    q->succ = n;
}

int getNodeCount(){
    if(head == NULL){
        return 0;
    }

    node *q;
    q = head;

    int i;
    i = 0;

    while(q == NULL){
        i++;
        q = q->succ;
    }

    return i;
}

void printListe(node *liste){
    node *q;
    q = liste;

    if (q == NULL){
        printf("%s\n", "Liste ist Leer");
        return;
    }

    while (q != NULL){
        printf("%s %s\n", q->vorname, q->nachname);
        q = q->succ;
    }
    printf("\n");
}