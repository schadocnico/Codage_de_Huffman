#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

nda _creer_noeud(void *_val, void(*_copier)(void*, void**)) {
    nda n = (nda)malloc(sizeof(struct noeuda));

    _copier(_val, &(n->valeur));
    n->droite = NULL;
    n->gauche = NULL;

    return n;
    
}

arb creer_arbre(void *_val_racine, void(*_copier)(void*, void**), void(*_detruire)(void**)) {
    arb a = (arb)malloc(sizeof(struct arbre));

    a->racine = _creer_noeud(_val_racine, _copier);
    a->copier = _copier;
    a->detruire = _detruire;

    return a;

}

void ajouter_arbre(void* _val_d, void* _val_g, arb a){
    _creer_noeud(a->racine->droite, a->copier);
    _creer_noeud(a->racine->gauche, a->copier);

}


