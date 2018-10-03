#include "utils.h"
#include "heapq.h"

struct noeud {
	void* val;
	struct noeud* suivant;
};

typedef struct noeud* nd;

/* ----- Methode de Noeud -----*/
nd _creer_noeud(void* _val, void(* _copier(void*, void**))) {
	nd n = (nd)malloc(sizeof(struct noeud));

	_copier(_val, &(n->val));
	n->suivant = NULL;
	
	return n;

}

/*----- Methode de heap liste -----*/

heap creer_heap(void(* _copier)(void*, void**), void(* _detruire)(void**), int(*_comparer)(void*, void*)) {
	heap h = (heap)malloc( sizeof(struct heap_liste) );

	h->taille = 0;
	h->tete = NULL;
	h->copier = _copier;
	h->detruire = _detruire;
	h->comparer = _comparer;

	return h;

}

void ajouter_heap(void* _val, heap h) {
	nd tete = h->tete;
	nd tmp = h->tete;
	nd prec = NULL;

	nd n = _creer_noeud(_val, h->copier);

	if(h->tete == NULL) {
		h->tete = n;
	} else {
		while(comparer((h->tete)->val,n->val) < 1) {
			prec = tmp;
			tmp = (h->tete)->suivant;
			h->tete = (h->tete)->suivant;
		}

		h->tete = n;
		(h->tete)->suivant = tmp->suivant;
		prec->suivant = n;
		h->tete = tete;
	}

	(h->taille)++;

}

void* extraire_min(heap h) {
	nd tmp = (h->tete)->suivant;

	void* val = (h->tete)->val;
	h->tete->suivant = NULL;
	
	h->tete = tmp;

	(h->taille)--;

	return val;

}

int taille(heap h){
	return h->taille;
}
		
