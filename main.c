#include "utils.h"
#include "huffman.h"
#include "arbre.h"
#include "heapq.h"

void _copier_int(void* val1, void** val2){
    *val2 = (int*)malloc(sizeof(int));
    memcpy(*val2, val1, sizeof(int));
}

void _detruire_int(void** val){
    free(*val);
}

int _comparer_int(void* _val1, void* _val2){
    int val1 = *((int*)_val1);
    int val2 = *((int*)_val2);

    return val1-val2;
}

int main(void) {

    int v1 = 1;
    int v2 = 2;
    int v3 = 3;

    puts("Creation ?");

    heapq h = creer_heap(&_copier_int, &_detruire_int, &_comparer_int);

    puts("Creation !");

    ajouter_heap(&v2, h);
    ajouter_heap(&v1, h);
    ajouter_heap(&v3, h);

    puts("Ajouté !");

    int *p = (int*)extraire_min(h);
    int *p1 = (int*)extraire_min(h);

    puts("Extrait !");

    printf("%i", *p);

    free(p);
    p = NULL;

    free(p1);
    p1 = NULL;
    
    free_heap(&h);

    return 0;
}
