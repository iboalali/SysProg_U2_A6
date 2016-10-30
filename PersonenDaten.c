#include "PersonenDaten.h"
#include "StringFuncs.h"

void personHinzufuegen(char *vorname, char *nachname){
    node *n;
    n = malloc(sizeof(node));
    n->vorname = vorname;
    n->nachname = nachname;
    n->succ = NULL;

    nodeSortiertHinzufuegen(n);
}

void nodeSortiertHinzufuegen(node *n){
    if (head == NULL){
        nodeAmAnfangHinzufuegen(n);
        return;
    }

    node *p; // head location
    node *q; // head location + 1
    p = head; // should not be NULL
    q = head->succ; // could be NULL

    if(node_count == 1){
        if (namecmp(n->nachname, head->nachname) == 1){
            // Neuer Name kommt vor den derzeitigen Name in der liste
            nodeAmAnfangHinzufuegen(n);
        }
        else if(namecmp(n->nachname, head->nachname) == 0){
            // Neuer Name is exakt gleich.
            // Vorname vergleichen
            if(namecmp(n->vorname, head->vorname) == 1){
                // Wenn die Nachnamen gleich sind, aber der neue vorname
                // vor den in der liste
                nodeAmAnfangHinzufuegen(n);
            }else{
                // Wenn die vornamen gleich sind, oder der neuer vorname 
                // nachher kommt, wird der neue node am ende hinzufügen
                nodeAmEndeHinzufuegen(n);
            }
        }else{
            // Neuer Name kommt nach den derzeitigen Name in der liste
            nodeAmEndeHinzufuegen(n);
        }
        return;
    }

    // Name mit der ersten node vergleichen
    if(namecmp(n->nachname, p->nachname) == 1){
        nodeAmAnfangHinzufuegen(n);
        return;
    }else if(namecmp(n->nachname, p->nachname) == 0){
        if(namecmp(n->vorname, p->vorname) == 1){
                nodeAmAnfangHinzufuegen(n);
                return;
        }

        while((q != NULL) && (namecmp(n->nachname, q->nachname) == 0)){
            if(namecmp(n->vorname, q->vorname) == 1){
                p->succ = n;
                n->succ = q;
                return;
            }

            // move the markers to the next position
            p = q;
            q = q->succ;
        }
        p->succ = n;
        n->succ = q;
        return;
    }

    // if there are more than one node
    while (q != NULL){
        if (namecmp(n->nachname, q->nachname) == 1){
            // Neuer Name kommt vor den derzeitigen Name in der liste.

            // put the new node between the current node and the previous one
            p->succ = n;
            n->succ = q;
            return;
        }else if(namecmp(n->nachname, q->nachname) == 0){
            // Der Name is exakt gleich

            // Vorname vergleichen
            if(namecmp(n->vorname, q->vorname) == 1){
                // put the new node between the current node and the previous one
                p->succ = n;
                n->succ = q;
                return;
            }
            
            // move the markers to the next position
            p = q;
            q = q->succ;
            // hier wird geprüft ob noch mehr leute den gleichen Namen besitzen
            while((q != NULL) && (namecmp(n->nachname, q->nachname) == 0)){
                if(namecmp(n->vorname, q->vorname) == 1){
                    // put the new node between the current node and the previous one
                    p->succ = n;
                    n->succ = q;
                    return;
                }
                // move the markers to the next position
                p = q;
                q = q->succ;
            }
            // put the new node between the current node and the previous one
            p->succ = n;
            n->succ = q;
            return;

        }
        // move the markers to the next position
        p = q;
        q = q->succ;

    }

    // gone through the whole list. just add to the end
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

void moveToTheNextPositionInTheList(node *p, node *q){
    p = q;
    q = q->succ;
}

void putNewNodeInTheList(node *p, node *q, node *n){
    p->succ = n;
    n->succ = q;
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