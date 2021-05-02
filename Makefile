all:
	gcc -o flood main.c campo.h color.c fila.c fila.h

clean:
	rm flood