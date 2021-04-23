#include "campo.h"

void vizinho(Campo c, int x, int y, int elem)
{
    int aux = c.matriz[x][y];
    c.matriz[x][y] = elem;
    if((x < c.lin && y < c.col) || (x >= 0 && y >= 0))
    {
        if(c.matriz[x+1][y] == aux)
            vizinho(c, x+1, y, elem);
        if(c.matriz[x][y+1] == aux)
            vizinho(c, x, y+1, elem);
        if(c.matriz[x-1][y] == aux)
            vizinho(c, x-1, y, elem);
        if(c.matriz[x][y-1] == aux)
            vizinho(c, x, y-1, elem);
    }
}
void trocaElemento(Campo c, int x, int y, int elem)
{
   vizinho(c, x, y, elem);
}
int verificaJogo(Campo c, int elem)
{
    for(int i = 0; i < c.lin; i++)
    {
        for(int j = 0; j < c.col; j++)
        {
            if(c.matriz[i][j] != elem)
                return 1;
        }
    }
    return 0;
}
int jogar(Campo c)
{
    int passos = 0;
    int x, y;
    imprimeCampo(c);
    while(passos < 10)
    {
        printf("Insira coordenada da forma x y: ");
        scanf("%d %d", &x, &y);
        trocaElemento(c, x, y, 7);
        imprimeCampo(c);
        printf("\n\n");
        passos++;
    }
    return verificaJogo(c, 7);
}
int main()
{
    int lin = 5;
    int col = 5;
    Campo c = montaCampo(lin, col);
    if(jogar(c))
        printf("Se Fodeu!\n");
    else
        printf("Ganhou!!\n");
    return 0;
}
