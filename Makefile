CFLAGS = -Wall -ggdb3

sudoku: sudoku.c
	gcc $(CFLAGS) sudoku.c -o $@
