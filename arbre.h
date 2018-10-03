#ifndef ARBRE_H
#define ARBRE_H

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
void ajouter_arbre(void* _val_d, void* _val_g, arb a);
void changer_val_racine(void* _val, arb a);
void detruire_arbre(arb* a);

#endif //ARBRE_H
