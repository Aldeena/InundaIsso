#ifndef CAMPO_H_INCLUDED
#define CAMPO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int **matriz;
    int lin;
    int col;
}Campo;

Campo montaCampo(int lin, int col);

void imprimeCampo(Campo c);

#endif // CAMPO_H_INCLUDED
