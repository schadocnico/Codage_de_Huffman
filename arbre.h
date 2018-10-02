#ifndef ARBRE_H
#define ARBRE_H

typedef struct noeuda {
    int cle;
    struct noeuda *droite;
    struct noeuda *gauche;
};

typedef struct noeuda* nda;

struct arbre {
    nda tete;
    void(*copier)(void*, void**);
    void(*detruire)(void**);
};

typedef struct arbre* arb;

arb creer_arbre(void(*_copier)(void*, void**), void(*_detruire)(void**));

#endif //UNTITLED_LISTE_GENERIQUE_H
