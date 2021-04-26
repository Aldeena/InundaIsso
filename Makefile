all:
	gcc -o flood main.c campo.h color.c

clean:
	rm flood