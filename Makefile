CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -std=c99 -Wfatal-errors -Werror
LDFLAGS=
EXEC=main

all: $(EXEC)

main: main.o utils.h couple.o heapq.o huffman.o arbre.o
	$(CC) -o $@ $^ $(LDFLAGS)


%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o
	rm main

mrproper: clean
	rm -rf $(EXEC)
