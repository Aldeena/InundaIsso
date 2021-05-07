#include "fila.h"

/*Função para criar uma fila vazia (não criar nenhum nó, só devolver NULL)!*/
Queue* create_queue () {
   return NULL;
}

/*Função para liberar uma fila nó por nó!*/
void free_queue (Queue *q) {

   Queue* aux;
   while(q != NULL)
   {
       aux = q->next;
       free(q);
       q = aux;
   }
}

/*Função para enfileirar um elemento (inserir na cauda da lista encadeada)!*/
Queue* enqueue (Queue *q, int X, int Y) {

    Queue* novo = (Queue*)malloc(sizeof(Queue));

    if(q == NULL)
    {
        novo->x = X;
        novo->y = Y;
        novo->next = NULL;
        q = novo;
    }


    else {
        Queue* aux = NULL;

        novo->x = X;
        novo->y = Y;
        novo->next = NULL;

        aux = q;

        while (aux->next != NULL) {
            aux = aux->next;
        }

        aux->next = novo;
    }

   return q;
}

/*Função para desenfileirar um elemento (remover da cabeça da lista encadeada)!*/
Queue* dequeue (Queue *q) {

    Queue* aux = q;

   if(empty_queue(q))
   {
       printf("Fila vazia!");
       exit(1);
   }

   q = q->next;
   free(aux);

   return q;
}


/*Função para testar se uma fila está vazia!*/
int empty_queue (Queue *q) {

   if (q == NULL)
    {
        return 1;
    }

    else
        return 0;
}

int verificaNodeQ(Queue *q, int x, int y)
{
    for(Queue *i = q; i != NULL; i = i->next)
    {
        if(i->x == x && i->y == y)
            return 0;
    }
    return 1;
}

