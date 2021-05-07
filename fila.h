#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
  int x;
  int y;
  struct queue *next;
} Queue;

Queue* create_queue ();

void free_queue (Queue *q);

Queue* enqueue (Queue *q, int X, int Y);

Queue* dequeue (Queue *q);

int front (Queue *q);

int empty_queue (Queue *q);

int verificaNodeQ(Queue *q, int x, int y);



#endif // FILA_H_INCLUDED
