//
// Created by ubuntu-nico on 11/10/18.
//

#include "bit.h"


bit* creer_bit(){
    bit* b = (bit*)malloc(sizeof(bit));
    b->valeur = 0;
    b->taille = 0;
    return b;

}
