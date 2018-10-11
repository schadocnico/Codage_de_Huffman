//
// Created by ubuntu-nico on 11/10/18.
//

#ifndef CODAGE_DE_HUFFMAN_BIT_H
#define CODAGE_DE_HUFFMAN_BIT_H

#include "utils.h"

struct bit{
    unsigned int taille : 4;
    unsigned int valeur : 8;
};

typedef struct bit bit;

bit* creer_bit();

#endif //CODAGE_DE_HUFFMAN_BIT_H
