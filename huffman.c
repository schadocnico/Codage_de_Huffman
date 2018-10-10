#include "huffman.h"

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

void _copier_arbre_ptr(void* _arbre1, void** _arbre2){
    *_arbre2 = malloc(sizeof(arb*));
    memcpy(*_arbre2, _arbre1, sizeof(arb*));
}

void _detruire_arbre_ptr(void** _arbre){
    arb* arbre = (arb*)(*_arbre);
    detruire_arbre(arbre);

    free(*_arbre);
    *_arbre = NULL;
}

int _comparer_arbre_couple_ptr(void* _val1, void* _val2){
    couple* v1 = (couple*)val_racine(*((arb*)_val1));
    couple* v2 = (couple*)val_racine(*((arb*)_val2));

    return _comparer_couple_intchar(v1, v2);
}

/*

*/
int* occurrences_ASCII(char *chaine, int* tab){

    for(int i = 0; i < (int)strlen(chaine); ++i) {
        tab[(int)chaine[i]]++;
    }

    return tab;
    
}

arb* arbre_huffman(char *chaine){

    int *occurrences  = calloc(256, sizeof(int) );

    occurrences_ASCII(chaine, occurrences); //tableau de taille 256

    heapq liste = creer_heap(&_copier_arbre_ptr, &_detruire_arbre_ptr, &_comparer_arbre_couple_ptr);

    for(int i = 0; i < 256; i++) {
        if (occurrences[i] > 0){
            couple* c = _creer_couple_intchar(occurrences[i], (char)i);
            arb a = _creer_arbre_coupleintchar(c);
            detruire_couple(&c);
            ajouter_heap((void*)&a, liste);
        }
    }

    arb* m1;
    arb* m2;
    arb f;

    while(taille(liste) > 1){
        m1 = extraire_min(liste);
        m2 = extraire_min(liste);
        f = fusionner_arbre(m1, m2, &_addition_couple_intchar);
        free(m1);
        free(m2);

        ajouter_heap(&f, liste);
    }

    arb *fin = extraire_min(liste);


    free(occurrences);
    free(liste);

    return fin;

}
