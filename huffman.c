#include "huffman.h"

/*
    Prend un chaine de de caractere ASCII en parametre et retourne un tableau de int de taille 256,
        ou l'element i de tab represente le nombre d'occurences de la notation en entier du caractere.
*/
int* occurrences_ASCII(char *chaine){
    int *tab = calloc( 256, sizeof(int) );

    for(int i = 0; i < (int)strlen(chaine); ++i) {
        tab[(int)chaine[i]]++;
    }

    return tab;
    
}

arb arbre_huffman(char *chaine){
    int *occurrences = occurrences_ASCII(chaine); //tableau de taille 256

    //heapq liste = creer_heap();

    for(int i = 0; i < 256; i++) {
        if (occurrences[i] > 0)
            break;
            //liste
    }

    return NULL;
    
}