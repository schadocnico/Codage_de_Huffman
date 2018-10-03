#ifndef ARBRE_H
#define ARBRE_H

typedef struct noeuda {
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

#endif //ARBRE_H
