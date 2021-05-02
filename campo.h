#ifndef CAMPO_H_INCLUDED
#define CAMPO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

typedef struct
{
    char **matriz;
    int lin;
    int col;

    Queue* jogando;
    //Queue* vizinhos;
}Campo;

Campo montaCampo(int lin, int col);

void imprimeCampo(Campo c);

#endif // CAMPO_H_INCLUDED
