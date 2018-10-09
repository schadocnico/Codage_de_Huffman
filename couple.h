#ifndef COUPLE_H
#define COUPLE_H

struct couple{
    void *val1;
    void *val2;
    void(*copier_val1)(void*, void**);
    void(*detruire_val1)(void**);
    void(*copier_val2)(void*, void**);
    void(*detruire_val2)(void**);
};

typedef struct couple *couple;

couple creer_couple(void *_val1, void *_val2, void(* _copier_val1)(void*, void**), void(* _detruire_val1)(void**), 
void(* _copier_val2)(void*, void**), void(* _detruire_val2)(void**));
void detruire_couple(couple* c);

#endif