#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "utils.h"
#include "arbre.h"
#include "heapq.h"
#include "couple.h"

void occurrences_ASCII(char *chaine, int* tab);
arb* arbre_huffman(int *occurrences);

#endif //HUFFMAN_H