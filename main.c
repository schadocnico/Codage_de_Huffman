#include "utils.h"
#include "huffman.h"
#include "arbre.h"
#include "heapq.h"
#include "couple.h"

void _afficher_couple_intchar(void *_val){
    couple* c = (couple*)_val;
    printf("(%d,", *((int*)c->val1));
    if(c->val2 != NULL)
        printf("%c", *((char*)c->val2));
    printf(")");
}

//MAIN -------------------

int main(void) {

    /*arb* fin = arbre_huffman("aaaafregregeegergrgergegr");


    _afficher_noeud_tout((*fin)->racine, &_afficher_couple_intchar);

    detruire_arbre(fin);
    free(fin);*/

    char *c = malloc(10 * sizeof(char));

    c[0] = 'a';
    c[1] = '2';

    printf("%d", (int)strlen(c));

    free(c);

    return 0;
}
