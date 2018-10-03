#ifndef HEAPQ_H
#define HEAPQ_H

struct heap_liste{
    int taille;
    nd tete;
    void(*copier)(void*, void**);
    void(*detruire)(void**);
    int(*comparer)(void*, void*);
};

typedef struct heap_liste* heap;

heap creer_heap(void(* _copier)(void*, void**), void(* _detruire)(void**), int(*_comparer)(void*, void*));
void ajouter_heap(void* _val, heap h);
void* extraire_min(heap h);
int taille(heap h);

#endif //HEAPQ_H
