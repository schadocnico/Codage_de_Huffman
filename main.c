#include "utils.h"
#include "huffman.h"
#include "arbre.h"
#include "heapq.h"
#include "couple.h"

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

void _addition_int(void* _val1, void* _val2, void** _res){
    _copier_int(_val1, _res);
    int val1 = *((int*)_val1);
    int val2 = *((int*)_val2);

    int *res = (int*)malloc(sizeof(int));
    *res = val1 + val2;

    memcpy(*_res, (void *)res, sizeof(int));

    free(res);
    
}

//CHAR ------------------------------

void _copier_char(void* val1, void** val2){
    *val2 = (char*)malloc(sizeof(char));
    memcpy(*val2, val1, sizeof(char));
}

void _detruire_char(void** val){
    free(*val);
    *val = NULL;
}

int _comparer_char(void* _val1, void* _val2){
    char val1 = *((char*)_val1);
    char val2 = *((char*)_val2);

    return val1-val2;
}

void _addition_char(void* _val1, void* _val2, void** zero){
    _copier_char(_val1, zero);
    char val1 = *((char*)_val1);
    char val2 = *((char*)_val2);

    char *res = (char*)malloc(sizeof(char));
    *res = val1 + val2;

    memcpy(*zero, (void *)res, sizeof(char));

    free(res);
    
}

//Couple ------------------------------

void _copier_couple_intchar(void* val1, void** val2){
    *val2 = (couple*)malloc(sizeof(struct couple));
    memcpy(*val2, val1, sizeof(struct couple));
}

void _detruire_couple_intchar(void** val){
    detruire_couple((couple*)*val);
    free(*val);
    *val = NULL;
}

int _comparer_couple_intchar(void* _val1, void* _val2){
    couple v1 = (couple)_val1;
    couple v2 = (couple)_val2;

    int res = *((int*) v1->val1) - *((int*) v2->val1);

    if (res != 0) return res;

    if(v1->val2 == NULL) 
        return -1;

    if(v2->val2 == NULL) 
        return 1;

    res = *((char*) v1->val2) - *((char*) v2->val2);

    return res;
}

void _addition_couple_intchar(void* _val1, void* _val2, void** _res){
    couple val1 = (couple)_val1;
    couple val2 = (couple)_val2;

    int *res = malloc(sizeof(int));

    _addition_int(val1->val1, val2->val2, (void*)res );

    couple res_couple = creer_couple(res, NULL, val1->copier_val1, val1->detruire_val1, val1->copier_val2, val1->detruire_val2);
    memcpy(*_res, res_couple, sizeof(struct couple));
    //detruire_couple(res_couple);
}

//Arbre_couple ------------------------------

void _copier_arbre_couple(void* val1, void** val2){
    *val2 = (arb*)malloc(sizeof(struct arbre));
    memcpy(*val2, val1, sizeof(struct arbre));
}

void _detruire_arbre_couple(void** val){
    detruire_arbre((arb*)*val);
    free(*val);
    *val = NULL;
}

int _comparer_arbre_couple(void* _val1, void* _val2){
    couple v1 = ((arb)_val1)->racine->valeur;
    couple v2 = ((arb)_val2)->racine->valeur;

    return _comparer_couple_intchar(v1, v2);

}


//MAIN -------------------

int main(void) {
    
    int v1 = 1;
    char w1 = 'b';
    couple c1 = creer_couple(&v1, &w1, &_copier_int, &_detruire_int, &_copier_char, &_detruire_char);
    int v2 = 1;
    //char w2 = 'c';
    couple c2 = creer_couple(&v2, NULL, &_copier_int, &_detruire_int, &_copier_char, &_detruire_char);
    int v3 = 3;
    char w3 = 'y';
    couple c3 = creer_couple(&v3, &w3, &_copier_int, &_detruire_int, &_copier_char, &_detruire_char);
    
    heapq liste = creer_heap(&_copier_couple_intchar, &_detruire_couple_intchar, &_comparer_couple_intchar);

    ajouter_heap((void*)c1, liste);
    ajouter_heap((void*)c2, liste);
    ajouter_heap((void*)c3, liste);

    puts("extraire");

    couple r1 = extraire_min(liste);

    puts("extraire !");

    //printf("%i / %c\n", *((int*)r1->val1), *((char*)r1->val2));

    puts("extraire");

    couple r2 = extraire_min(liste);

    puts("affich");

    printf("%i / %c\n", *((int*)r2->val1), *((char*)r2->val2));

    puts("affich2");

    couple r3 = extraire_min(liste);

    printf("%i / %c\n", *((int*)r3->val1), *((char*)r3->val2));

    detruire_couple(&r1);
    puts("r2");
    detruire_couple(&r2);
    puts("r3");
    detruire_couple(&r3);

    free(liste);

    return 0;
}
