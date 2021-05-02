#include "campo.h"
#include "fila.h"

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
int verificaJogo(Campo c)
{
    int elem = c.matriz[1][1];
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
    /*Queue* aux = NULL;
    int elem = c.matriz[1][1];
    for(int i = 0; i != NULL; i++)
    {
        aux.x = c.fila.x;
        aux.y = c.fila.y

        if((x < c.lin && y < c.col) && (x >= 0 && y >= 0))
        {
            if(c.matriz[x+1][y] == aux)
                trocaElemento(c, x+1, y, elem);
            if(c.matriz[x-1][y] == aux)
                trocaElemento(c, x-1, y, elem);
            if(c.matriz[x][y+1] == aux)
                trocaElemento(c, x, y+1, elem);
            if(c.matriz[x][y-1] == aux)
                trocaElemento(c, x, y-1, elem);
        }
    }*/

    /* A ideia seria comparar o elemento, olhando através dos índices que seriam armazenados dentro da fila,
       daí existiria um contador que veria qual o que mais se repete, e uma variável que armazenaria qual o elemento que mais se repete,
       então seria retornado esse elemento. O problema fica em ver o vizinho do vizinho, porque a escolha ideal não é só o que mais se repete ao redor
       dos preenchidos, e sim o que mais se estende num contexto geral, ou seja, prevendo o que vai ser preenchido através dessa escolha.

       Talvez a solução seria criar duas filas, uma com os elementos preenchidos, e outra, já cheia, com os elementos a serem preenchidos ainda.
       E essa comparação se daria através da fila dos elementos que ainda precisam preencher. Mas eu ainda não consegui pensar num algoritmo bom
       o suficiente para executar essa ideia.*/
}
void resolveJogo(Campo c)
{
    int x = 1, y = 1;
    c.jogando = enqueue(c.fila, x, y);

        while(passos < 11)
    {
        if(!verificaJogo(c))
            return 0;
        printf("Passo %d insira o numero que quer trocar: ", passos+1);
        scanf("%d", &elem);
        trocaElemento(c, x, y, melhorCandidato(c));
        imprimeCampo(c);
        printf("\n\n");
        passos++;
    }

}
int jogar(Campo c, int passos)
{
    imprimeCampo(c);
/*    while(passos < 11)
    {
        if(!verificaJogo(c, 7))
            return 0;
        printf("Passo %d insira o numero que quer trocar: ", passos+1);
        scanf("%d", &elem);
        resolveJogo(c)
        imprimeCampo(c);
        printf("\n\n");
        passos++;
    }*/
    return verificaJogo(c);
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
