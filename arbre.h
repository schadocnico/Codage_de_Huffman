#ifndef ARBRE_H
#define ARBRE_H

#include "bit.h"

struct noeuda {
    void* valeur;
    struct noeuda *droite;
    struct noeuda *gauche;
};

typedef struct noeuda* nda;

struct arbre {
    nda racine;
    void(*copier)(void*, void**);
    void(*detruire)(void**);
};

typedef struct arbre* arb;

arb creer_arbre(void *_val_racine, void(*_copier)(void*, void**), void(*_detruire)(void**));
arb fusionner_arbre(arb* a_droite, arb* a_gauche, void(*_addition)(void*, void*, void**));
void changer_val_racine(void* _val, arb a);
void* val_racine(arb a);
void detruire_arbre(arb* a);
void _afficher_noeud_tout(nda n, void(*_afficher)(void*));
bit* chemin_tout_element(arb a, int(*_val_to_int)(void*));

#endif //ARBRE_H
