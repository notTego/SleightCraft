# Copyright 2021 Vladimir Marin

# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -g

# define targets
#TARGETS=my_octave

build: tema1

tema1: file.c
	$(CC) $(CFLAGS) file.c commands.c misc.c errors.c hash.c -o tema1

pack:
	zip -FSr 312CA_VladimirMarin_Tema2.zip README Makefile *.c *.h

clean:
	rm -f tema1
	rm -f *.o

.PHONY: pack clean

