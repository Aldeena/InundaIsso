#include "campo.h"

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
void verificaVizinho(Campo* c, int x, int y)
{
    if((x < c->lin-1 && y < c->col-1) && (x > 0 && y > 0))
    {
        int aux = c->matriz[x][y];
        if(verificaNodeL(c->vizinhos, x, y))
            c->vizinhos = inserir(c->vizinhos, x, y);

        if(c->matriz[x+1][y] == aux)
        {
            verificaVizinho(c, x+1, y);
        }
        if(c->matriz[x][y+1] == aux)
        {
            verificaVizinho(c, x, y+1);
        }
    }
}
int melhorCandidato(Campo c)
{
    int elemInundado = c.matriz[1][1];
    for(Queue *i = c.inundado; i != NULL; i = i->next)
    {
        if((i->x < c.lin && i->y < c.col) && (i->x >= 0 && i->y >= 0))
        {
            if(c.matriz[i->x+1][i->y] != elemInundado)
                verificaVizinho(&c, i->x+1, i->y);

            else if (verificaNodeQ(c.inundado, i->x+1, i->y))
                c.inundado = enqueue(c.inundado, i->x+1, i->y);

            if(c.matriz[i->x-1][i->y] != elemInundado)
                verificaVizinho(&c, i->x-1, i->y);

            else if (verificaNodeQ(c.inundado, i->x-1, i->y))
                c.inundado = enqueue(c.inundado, i->x-1, i->y);

            if(c.matriz[i->x][i->y+1] != elemInundado)
                verificaVizinho(&c, i->x, i->y+1);

            else if (verificaNodeQ(c.inundado, i->x, i->y+1))
                c.inundado = enqueue(c.inundado, i->x, i->y+1);

            if(c.matriz[i->x][i->y-1] != elemInundado)
                verificaVizinho(&c, i->x, i->y-1);

            else if (verificaNodeQ(c.inundado, i->x, i->y-1))
                c.inundado = enqueue(c.inundado, i->x, i->y-1);
        }
    }
    int vetor[6] = {-1};
    Lista *i = c.vizinhos;
    while(i != NULL)
    {
        if(c.matriz[i->x][i->y] == 0)
            vetor[0]++;
        else if(c.matriz[i->x][i->y] == 1)
            vetor[1]++;
        else if(c.matriz[i->x][i->y] == 2)
            vetor[2]++;
        else if(c.matriz[i->x][i->y] == 3)
            vetor[3]++;
        else if(c.matriz[i->x][i->y] == 4)
            vetor[4]++;
        else if(c.matriz[i->x][i->y] == 5)
            vetor[5]++;
        i = remover(i, i->x, i->y);
    }

    int aux = -1;
    int indice = -1;
    for(int i = 0; i <= 5; i++)
    {
        if(vetor[i] > aux)
        {
            aux = vetor[i];
            indice = i;
        }
    }
    printf("Candidato %d\n", indice);
    return indice;
    /* A ideia seria comparar o elemento, olhando através dos índices que seriam armazenados dentro da fila,
       daí existiria um contador que veria qual o que mais se repete, e uma variável que armazenaria qual o elemento que mais se repete,
       então seria retornado esse elemento. O problema fica em ver o vizinho do vizinho, porque a escolha ideal não é só o que mais se repete ao redor
       dos preenchidos, e sim o que mais se estende num contexto geral, ou seja, prevendo o que vai ser preenchido através dessa escolha.

       Talvez a solução seria criar duas filas, uma com os elementos preenchidos, e outra, já cheia, com os elementos a serem preenchidos ainda.
       E essa comparação se daria através da fila dos elementos que ainda precisam preencher. Mas eu ainda não consegui pensar num algoritmo bom
       o suficiente para executar essa ideia.*/
}
void resolveJogo(Campo c, int passos)
{
    int x = 1, y = 1;
    c.inundado = enqueue(c.inundado, x, y);

    while(passos < 14)
    {
        printf("Passo %d\n", passos);
        trocaElemento(c, x, y, melhorCandidato(c));
        imprimeCampo(c);
        printf("\n\n");

        if(!verificaJogo(c))
            break;

        else
            passos++;
    }

}
int jogar(Campo c, int passos)
{
    imprimeCampo(c);
    resolveJogo(c, passos);
    /*int elem = 0;
    int x = 1, y = 1;
    while(passos < 11)
    {
        if(!verificaJogo(c))
            return 0;
        printf("Passo %d insira o numero que quer trocar: ", passos+1);
        scanf("%d", &elem);
        trocaElemento(c, x, y, elem);
        //resolveJogo(c)
        imprimeCampo(c);
        printf("\n\n");
        passos++;
    }*/
    return verificaJogo(c);
}

int main()
{
    int lin = 8;
    int col = 8;
    Campo c = montaCampo(lin, col);
    if(jogar(c, 1))
        printf("Perdeu!\n");
    else
        printf("Ganhou!!\n");
    return 0;
}
