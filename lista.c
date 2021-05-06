#include "lista.h"

/*Função para criar uma lista encadeada vazia!*/
Lista* criar (void) {
   return NULL;
}

/*Função para inserir um elemento na cabeça de uma lista encadeada!*/
Lista* inserir (Lista *lista, int X, int Y) {
   Lista *novo =(Lista*)malloc(sizeof(Lista));
   novo->x = X;
   novo->y = Y;
   novo->next = lista;
   return novo;
}

/*Função para imprimir uma lista encadeada!*/
/*void imprimir (Lista *lista) {
   Lista *v;
   for (v = lista; v != NULL; v = v->next) {
      printf("Valor: %d\n", v->info);
   }
}*/

/*Função para remover um elemento da lista encadeada em qq posição!*/
Lista *remover (Lista *l, int X, int Y) {
   Lista *prev = NULL, *aux = l;
   while ( (aux != NULL) && (aux->x != X) && (aux->y != Y) ) {
      prev = aux;
      aux = aux->next;
   }
   if (aux == NULL) {
      return l;
   }
   else if (prev == NULL) {
      l = l->next;
   }
   else {
      prev->next = aux->next;
   }
   free (aux);
   return l;
}

/*Função para desalocar uma lista encadeda!*/
void liberar (Lista *l) {
  Lista *aux;
  while (l != NULL) {
    aux = l->next;
    free(l);
    l = aux;
  }
}
