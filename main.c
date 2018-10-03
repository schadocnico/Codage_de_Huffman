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
    *val = NULL;
}

int _comparer_int(void* _val1, void* _val2){
    int val1 = *((int*)_val1);
    int val2 = *((int*)_val2);

    return val1-val2;
}

void _addition_int(void* _val1, void* _val2, void** zero){
    _copier_int(_val1, zero);
    int val1 = *((int*)_val1);
    int val2 = *((int*)_val2);

    int *res = (int*)malloc(sizeof(int));
    *res = val1 + val2;

    memcpy(*zero, (void *)res, sizeof(int));

    free(res);
    
}

int main(void) {
    int v1 = 1;
    int v2 = 1;

    arb a1 = creer_arbre(&v1, &_copier_int, &_detruire_int);
    arb a2 = creer_arbre(&v2, &_copier_int, &_detruire_int);

    arb a3 = fusionner_arbre(&a1, &a2, &_addition_int);

    int *val = (int*)val_racine(a3);

    printf("%i", *val);

    detruire_arbre(&a3);

    return 0;
}
