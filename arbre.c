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
    nda* n_droite = &((*a_droite)->racine);
    nda* n_gauche = &((*a_gauche)->racine);

    void *add;

    _addition((*n_droite)->valeur, (*n_gauche)->valeur, &add);


    arb a = creer_arbre(add, (*a_droite)->copier, (*a_droite)->detruire);

    a->racine->droite = *n_droite;
    a->racine->gauche = *n_gauche;

    (*a_droite)->detruire(&add);


    (*a_droite)->racine = NULL;
    (*a_gauche)->racine = NULL;
    

    free(*a_droite);
    free(*a_gauche);

    *a_droite = NULL;
    *a_gauche = NULL;

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

void afficher_arbre(arb a, void(*_afficher)(void*)){
    printf("[");
    _afficher(a->racine->valeur);
    printf("]\n");
}

void _afficher_noeud_tout(nda n, void(*_afficher)(void*)){
    _afficher(n->valeur);
    printf(" -> [ G(");


    if (n->gauche != NULL){
        _afficher_noeud_tout(n->gauche, _afficher);
    }

    printf(") ; D(");

    if (n->droite != NULL){
        _afficher_noeud_tout(n->droite, _afficher);
    }
    printf(") ] ");
    
    
}

void _chemin_tout_element(nda n, char** tab, char *c, int(*_val_to_int)(void*)){ //OPTIMISATION
    int taille = (int)strlen(c);
    if (n->droite != NULL && n->gauche != NULL){
        c[taille] = '0';
        c[taille+1] = '\0';
        _chemin_tout_element(n->gauche, tab, c, _val_to_int);

        c[taille] = '1';
        _chemin_tout_element(n->droite, tab, c, _val_to_int);
    } else {
        tab[_val_to_int(n->valeur)] = calloc(10, sizeof(char));
        strcpy(tab[_val_to_int(n->valeur)], c);
    }

}

char** chemin_tout_element(arb a, int(*_val_to_int)(void*)){
    char** tab = calloc(256, sizeof(char*));
    char b[8] = {0};

    _chemin_tout_element(a->racine, tab, b, _val_to_int);

    return tab;

}

