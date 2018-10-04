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
arb fusionner_arbre(arb* a_droite, arb* a_gauche, void(*_addition)(void*, void*, void**));
void changer_val_racine(void* _val, arb a);
void* val_racine(arb a);
void detruire_arbre(arb* a);
void** rechercher_tout(arb a, char *c);

#endif //ARBRE_H
