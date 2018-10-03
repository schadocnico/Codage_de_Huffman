#include "utils.h"
#include "arbre.h"


nda _creer_noeuda(void *_val, void(*_copier)(void*, void**)) {
    nda n = (nda)malloc(sizeof(struct noeuda));

    _copier(_val, &(n->valeur));
    n->droite = NULL;
    n->gauche = NULL;

    return n;
    
}

void _detruire_noeuda(nda* n, void(*_detruire)(void**)) {
    if ((*n) != NULL) {
        _detruire_noeuda(&((*n)->droite), _detruire);
        _detruire_noeuda(&((*n)->gauche), _detruire);

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

/* On ajoute les valeurs par deux (arbre binaie complet) que a la racine, si les fils ne sont pas vide; on supprimes tout ses sous_fils */
void ajouter_arbre(void* _val_d, void* _val_g, arb a) {
    if (a->racine == NULL) return;

    if (a->racine->gauche != NULL)
        _detruire_noeuda(&(a->racine->gauche), a->detruire);
    if (a->racine->droite != NULL)
        _detruire_noeuda(&(a->racine->droite), a->detruire);

    a->racine->droite = _creer_noeuda(_val_d, a->copier);
    a->racine->gauche = _creer_noeuda(_val_g, a->copier);

}

void changer_val_racine(void* _val, arb a) {
    a->copier(_val, &(a->racine->valeur));
}

void detruire_arbre(arb* a) {
    _detruire_noeuda(&((*a)->racine), (*a)->detruire);

    free(*a);
    *a = NULL;
}


