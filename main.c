#include "campo.h"
#include "lista.h"

void trocaElemento(Campo c, int x, int y, int elem)
{
    int aux = c.matriz[x][y];
    if((x < c.lin && y < c.col) && (x >= 0 && y >= 0))
    {
        c.matriz[x][y] = elem;
        if(c.matriz[x+1][y] == aux)
            trocaElemento(c, x+1, y, elem);
        if(c.matriz[x-1][y] == aux)
            trocaElemento(c, x-1, y, elem);
        if(c.matriz[x][y+1] == aux)
            trocaElemento(c, x, y+1, elem);
        if(c.matriz[x][y-1] == aux)
            trocaElemento(c, x, y-1, elem);
    }
}
int verificaJogo(Campo c, int elem)
{
    for(int i = 1; i < c.lin-1; i++)
    {
        for(int j = 1; j < c.col-1; j++)
        {
            if(c.matriz[i][j] != elem)
                return 1;
        }
    }
    return 0;
}
int melhorCandidato(Campo c)
{

}
void resolveJogo(Campo c)
{
    int x = 1, y = 1;
    trocaElemento(c, x, y, melhorCandidato(c));
}
int jogar(Campo c, int passos)
{
    int passos = 0;
    int x = 1, y = 1;
    int elem = 0;
    imprimeCampo(c);
    while(passos < 11)
    {
        if(!verificaJogo(c, 7))
            return 0;
        printf("Passo %d insira o numero que quer trocar: ", passos+1);
        scanf("%d", &elem);
        resolveJogo(c)
        imprimeCampo(c);
        printf("\n\n");
        passos++;
    }
    return verificaJogo(c, 7);
}

int main()
{
    int lin = 7;
    int col = 7;
    Campo c = montaCampo(lin, col);
    resolveJogo(c);
    if(jogar(c, 10))
        printf("Se Fodeu!\n");
    else
        printf("Ganhou!!\n");
    return 0;
}
