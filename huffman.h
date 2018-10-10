#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "utils.h"
#include "arbre.h"
#include "heapq.h"
#include "couple.h"

int* occurence_ASCII(char *chaine);
arb* arbre_huffman(char *chaine);


#endif //HUFFMAN_H