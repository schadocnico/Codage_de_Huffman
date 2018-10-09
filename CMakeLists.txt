cmake_minimum_required(VERSION 3.10)
project(Codage_de_Huffman C)

set(CMAKE_C_STANDARD 11)

add_compile_options(-W -Wall -ansi -pedantic -std=c99 -Wfatal-errors -Werror -Wall -Wextra)

include_directories(.)

add_executable(Codage_de_Huffman
        arbre.c
        arbre.h
        couple.c
        couple.h
        heapq.c
        heapq.h
        huffman.c
        huffman.h
        main.c
        utils.h)
