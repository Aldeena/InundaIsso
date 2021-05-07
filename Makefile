all:
	gcc -o flood main.c campo.h color.c fila.c fila.h lista.c lista.h

clean:
	rm flood