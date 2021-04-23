#include "campo.h"

Campo montaCampo(int lin, int col)
{
    Campo c;
    c.lin = lin;
    c.col = col;
    c.matriz = malloc(lin*sizeof(int*));
    for(int i = 0; i < lin; i++)
        c.matriz[i] = malloc(col * sizeof(int));

    srand(time(NULL));
    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < col; j++)
        {
            c.matriz[i][j] = rand()%6;
        }
    }
    return c;
}

void imprimeCampo(Campo c)
{
    for(int i = 0; i < c.lin; i++)
    {
        for(int j = 0; j < c.col; j++)
        {
            printf("%d ", c.matriz[i][j]);
        }
        printf("\n");
    }
}
