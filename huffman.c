#include "utils.h"

/*
    Prend un chaine de de caractere ASCII en parametre et retourne un tableau de int de taille 256,
        ou l'element i de tab represente le nombre d'occurences de la notation en entier du caractere.
*/
int* occurence_ASCII(char *chaine){
    int *tab = calloc( 256, sizeof(int) );

    for(int i = 0; i < (int)strlen(chaine); ++i) {
        tab[(int)chaine[i]]++;
    }

    return tab;
    
}

