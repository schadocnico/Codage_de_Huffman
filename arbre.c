#include "utils.h"
#include "arbre.h"


nda _creer_noeuda(void *_val, void(*_copier)(void*, void**)) {
    nda n = (nda)malloc(sizeof(struct noeuda));

    _copier(_val, &(n->valeur));
    n->droite = NULL;
    n->gauche = NULL;

    return n;
    
}

void _detruire_noeuda(nda* n, void(* _detruire)(void**)) {
    if ((*n)!=NULL) {
        if ((*n)->gauche != NULL) {
            _detruire_noeuda(&((*n)->gauche), _detruire);
        }
        if ((*n)->droite != NULL) {
            _detruire_noeuda(&((*n)->droite), _detruire);
        }  
        _detruire(&((*n)->valeur));
        free(*n);
        *n = NULL;
    }
}


arb creer_arbre(void *_val_racine, void(*_copier)(void*, void**), void(*_detruire)(void**)) {
    arb a = (arb)malloc(sizeof(struct arbre));

    a->racine = _creer_noeuda(_val_racine, _copier);
    a->copier = _copier;
    a->detruire = _detruire;

    return a;

}

arb fusionner_arbre(arb* a_droite, arb* a_gauche, void(*_addition)(void*, void*, void**)) {
    nda n_droite = (*a_droite)->racine;
    nda n_gauche = (*a_gauche)->racine;

    void *add;
    
    _addition(n_droite->valeur, n_gauche->valeur, &add);

    arb a = creer_arbre(add, (*a_droite)->copier, (*a_droite)->detruire);

    free(add);

    (*a_droite)->racine = NULL;
    (*a_gauche)->racine = NULL;

    detruire_arbre(a_droite);
    detruire_arbre(a_gauche);

    a->racine->droite = n_droite;
    a->racine->gauche = n_gauche;

    return a;

}

void changer_val_racine(void* _val, arb a) {
    a->copier(_val, &(a->racine->valeur));
}

void* val_racine(arb a) {
    return a->racine->valeur;
}

void detruire_arbre(arb* a) {
    _detruire_noeuda(&((*a)->racine), (*a)->detruire);

    free(*a);
    *a = NULL;
}


