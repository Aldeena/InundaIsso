#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int x;
   int y;
   struct node* next;
} Lista;

Lista* criar (void);

Lista* inserir (Lista *lista, int X, int Y);

void imprimir (Lista *lista);

Lista *remover (Lista *l, int X, int Y);

void liberar (Lista *l);

