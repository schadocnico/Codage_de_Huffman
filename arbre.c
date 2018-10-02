#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

arb creer_arbre(void(*_copier)(void*, void**), void(*_detruire)(void**)) {
    arb a = (arb)malloc(sizeof(struct arbre));
    a->tete = NULL;
    a->copier = _copier;
    a->detruire = _detruire;
    return a;
}
