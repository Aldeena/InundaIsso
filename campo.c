#include "campo.h"
#include "lista.h"

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
            if(i == 0)
                c.matriz[i][j] = 8;
            else if(j == 0)
                c.matriz[i][j] = 8;
            else if(j == c.col-1 || i == c.lin-1)
                c.matriz[i][j] = 8;
            else
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
            if(j == c.col-1 || i == c.lin-1)
                printf(" ");
            else if(i == 0)
                printf("%d ", j);
            else if(j == 0)
                printf("%d ", i);
            else
                printf("%d ", c.matriz[i][j]);
        }
        printf("\n");
    }
}
