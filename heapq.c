#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "heapq.h"

/* ----- Methode de Noeud -----*/
ndh _creer_noeudh(void* _val, void(* _copier)(void*, void**)) {
	ndh n = (ndh)malloc(sizeof(struct noeud));

	_copier(_val, &(n->val));
	n->suivant = NULL;
	
	return n;

}

void _detruire_tout_noeudh(ndh* n, void(* _detruire)(void**)) {
    if ((*n)!=NULL) {
        if ((*n)->suivant != NULL)
            _detruire_tout_noeudh(&((*n)->suivant), _detruire);
        _detruire(&((*n)->val));
        free(*n);
        *n = NULL;
    }
}


/*----- Methode de heap liste -----*/

heapq creer_heap(void(* _copier)(void*, void**), void(* _detruire)(void**), int(*_comparer)(void*, void*)) {
	heapq h = (heapq)malloc( sizeof(struct heap_liste) );

	h->taille = 0;
	h->tete = NULL;
	h->copier = _copier;
	h->detruire = _detruire;
	h->comparer = _comparer;

	return h;

}

void ajouter_heap(void* _val, heapq h) {
	
	ndh n = _creer_noeudh(_val, h->copier);

	if(h->tete == NULL) {
		h->tete = n;

	} else if(h->comparer(_val, h->tete->val) <= 0){
		n->suivant = h->tete;
		h->tete = n;

	} else {
		ndh tmp = h->tete->suivant;
		ndh prec = h->tete;

		while(tmp != NULL && h->comparer(_val, tmp->val) > 0) {
			prec = tmp;
			tmp = tmp->suivant;
		}

		prec->suivant = n;
		n->suivant = tmp;
	}

	(h->taille)++;

}

void* extraire_min(heapq h) {
	ndh tmp = (h->tete)->suivant;

	void* val = (h->tete)->val;
	h->tete->suivant = NULL;
	free(h->tete);
	
	h->tete = tmp;

	(h->taille)--;

	return val;

}

void free_heap(heapq* h){
	if((*h)->tete != NULL)
		_detruire_tout_noeudh(&((*h)->tete), (*h)->detruire);
	free(*h);
	*h = NULL;
}

int taille(heapq h){
	return h->taille;
}
		
