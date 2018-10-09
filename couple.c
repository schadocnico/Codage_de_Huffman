#include "utils.h"
#include "couple.h"

couple* creer_couple(void *_val1, void *_val2, void(* _copier_val1)(void*, void**), void(* _detruire_val1)(void**),
void(* _copier_val2)(void*, void**), void(* _detruire_val2)(void**)) {
    couple* c = (couple*)malloc(sizeof(couple));

    c->copier_val1 = _copier_val1;
    c->detruire_val1 = _detruire_val1;
    c->copier_val2 = _copier_val2;
    c->detruire_val2 = _detruire_val2;

    if(_val1 != NULL)
        _copier_val1(_val1, &(c->val1));
    else
        c->val1 = NULL;

    if(_val2 != NULL)
        _copier_val2(_val2, &(c->val2));
    else c->val2 = NULL;

    return c;

}

void detruire_couple(couple** c) {
        if ((*c)->val1 != NULL)
            (*c)->detruire_val1(&((*c)->val1));
        if ((*c)->val2 != NULL)
            (*c)->detruire_val2(&((*c)->val2));

        free(*c);
        *c = NULL;
}
