#ifndef HEAPQ_H
#define HEAPQ_H

struct noeud {
	void* val;
	struct noeud* suivant;
};

typedef struct noeud* ndh;

struct heap_liste{
    int taille;
    ndh tete;
    void(*copier)(void*, void**);
    void(*detruire)(void**);
    int(*comparer)(void*, void*);
};

typedef struct heap_liste* heapq;

heapq creer_heap(void(* _copier)(void*, void**), void(* _detruire)(void**), int(*_comparer)(void*, void*));
void ajouter_heap(void* _val, heapq h);
void* extraire_min(heapq h);
void free_heap(heapq* h);
int taille(heapq h);

#endif //HEAPQ_H
