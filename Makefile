CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -std=c99
LDFLAGS=
EXEC=main

all: $(EXEC)

main: main.o huffman.o arbre.o utils.h heapq.o
	$(CC) -o $@ $^ $(LDFLAGS)


%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o
	rm main

mrproper: clean
	rm -rf $(EXEC)
