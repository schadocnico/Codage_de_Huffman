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
    if(*val == NULL)
        return;

    free(*val);
    *val = NULL;
}

/*int _comparer_int(void* _val1, void* _val2){
    int val1 = *((int*)_val1);
    int val2 = *((int*)_val2);

    return val1-val2;
}*/

void _addition_int(void* _val1, void* _val2, void** _res){
    *_res = (int*)malloc(sizeof(int));
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
    if(*val == NULL)
        return;

    free(*val);
    *val = NULL;
}

/*int _comparer_char(void* _val1, void* _val2){
    char val1 = *((char*)_val1);
    char val2 = *((char*)_val2);

    return val1-val2;
}*/

/*void _addition_char(void* _val1, void* _val2, void** zero){
    _copier_char(_val1, zero);
    char val1 = *((char*)_val1);
    char val2 = *((char*)_val2);

    char *res = (char*)malloc(sizeof(char));
    *res = val1 + val2;

    memcpy(*zero, (void *)res, sizeof(char));

    free(res);
    
}*/

//Couple ------------------------------

couple* _creer_couple_intchar(int a, char c){
    return creer_couple(&a, &c, &_copier_int, &_detruire_int, &_copier_char, &_detruire_char);

}

couple* _creer_couple_intchar_ptr(int* a, char* c){
    return creer_couple(a, c, &_copier_int, &_detruire_int, &_copier_char, &_detruire_char);

}

void _copier_couple_intchar(void* _couple1, void** _couple2){
    couple* couple1 = (couple*)_couple1;

    *_couple2 = _creer_couple_intchar_ptr(couple1->val1, couple1->val2);
}

void _detruire_couple_intchar(void** val){
    detruire_couple((couple**)val);
    
    free(*val);
    *val = NULL;
}

int _comparer_couple_intchar(void* _val1, void* _val2){
    couple* v1 = (couple*)_val1;
    couple* v2 = (couple*)_val2;

    int res = *((int*) v1->val1) - *((int*) v2->val1);

    if (res != 0) return res;

    if(v1->val2 == NULL) 
        return 1;

    if(v2->val2 == NULL) 
        return -1;

    res = *((char*) v1->val2) - *((char*) v2->val2);

    return res;
}

void _afficher_couple_intchar(void *_val){
    couple* c = (couple*)_val;
    printf("(%d,", *((int*)c->val1));
    if(c->val2 != NULL)
        printf("%c", *((char*)c->val2));
    printf(")");
}

void _addition_couple_intchar(void* _val1, void* _val2, void** _res){
    couple* val1 = (couple*)_val1;
    couple* val2 = (couple*)_val2;

    void* res;

    _addition_int(val1->val1, val2->val1, &res );

    *_res = _creer_couple_intchar_ptr(res, NULL);

    /**_res = malloc(sizeof(struct couple));

    memcpy(*_res, res_couple, sizeof(struct couple));
    */
    free(res);
    res = NULL;

}

//Arbre_couple ------------------------------

arb _creer_arbre_coupleintchar(couple* c){
    return creer_arbre(c, &_copier_couple_intchar, &_detruire_couple_intchar);
}

void _copier_arbre_couple(void* _arbre1, void** _arbre2){
    arb arbre1 = (arb)_arbre1;

    *_arbre2 = _creer_arbre_coupleintchar(val_racine(arbre1));
}

void _detruire_arbre_couple(void** val){
    detruire_arbre((arb*)*val);

    free(*val);
    *val = NULL;
}

int _comparer_arbre_couple(void* _val1, void* _val2){
    couple* v1 = (couple*)val_racine(((arb)_val1));
    couple* v2 = (couple*)val_racine(((arb)_val2));

    return _comparer_couple_intchar(v1, v2);
}

//MAIN -------------------

int main(void) {

    couple* c1 = _creer_couple_intchar(1, 'b');
    couple* c2 = _creer_couple_intchar(1, 'c');
    couple* c3 = _creer_couple_intchar(3, 'y');
    couple* c4 = _creer_couple_intchar(2, 'z');

    arb a1 = _creer_arbre_coupleintchar(c1);
    arb a2 = _creer_arbre_coupleintchar(c2);
    arb a3 = _creer_arbre_coupleintchar(c3);
    arb a4 = _creer_arbre_coupleintchar(c4);

    detruire_couple(&c1);
    detruire_couple(&c2);
    detruire_couple(&c3);
    detruire_couple(&c4);

    heapq liste = creer_heap(&_copier_arbre_couple, &_detruire_arbre_couple, &_comparer_arbre_couple);

    ajouter_heap((void*)a1, liste);
    ajouter_heap((void*)a2, liste);
    ajouter_heap((void*)a3, liste);
    ajouter_heap((void*)a4, liste);

    arb m1 = extraire_min(liste);
    arb m2 = extraire_min(liste);
    arb f = fusionner_arbre(&m1, &m2, &_addition_couple_intchar);
    ajouter_heap((void*)f, liste);

    m1 = extraire_min(liste);
    m2 = extraire_min(liste);
    f = fusionner_arbre(&m1, &m2, &_addition_couple_intchar);
    ajouter_heap((void*)f, liste);

    m1 = extraire_min(liste);
    m2 = extraire_min(liste);
    f = fusionner_arbre(&m1, &m2, &_addition_couple_intchar);
    ajouter_heap((void*)f, liste);


    _afficher_noeud_tout(f->racine, &_afficher_couple_intchar);




    return 0;
}
