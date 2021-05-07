#include "campo.h"

void trocaElemento(Campo c, int x, int y, int elem) //Função responsável pela inundação nos elementos
{
    int aux = c.matriz[x][y];
    if((x < c.lin && y < c.col) && (x >= 0 && y >= 0)) //Condição de parada da rescursividade
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
int verificaJogo(Campo c) //Aqui verificamos se o jogo foi vencido ou não
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
void verificaVizinho(Campo* c, int x, int y) //Nessa função, procuramos saber os vizinhos dos vizinhos
{
    if((x < c->lin-1 && y < c->col-1) && (x > 0 && y > 0))
    {
        int aux = c->matriz[x][y];
        if(verificaNodeL(c->vizinhos, x, y))
            c->vizinhos = inserir(c->vizinhos, x, y);

        if(c->matriz[x+1][y] == aux) //Verificação a direita e embaixo apenas, pois a esquerda e acima, já é feita pela função melhorCandidato
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
    for(Queue *i = c.inundado; i != NULL; i = i->next) //Aqui procuramos sempre alcançar os elementos inundados mais externos, ou seja, que possuem elementos diferentes do último melhor elemento
    {
        if((i->x < c.lin && i->y < c.col) && (i->x >= 0 && i->y >= 0))
        {
            if(c.matriz[i->x+1][i->y] != elemInundado) //Se ele não for inundado, chamamos a verifica vizinho para ver se ele possui elementos iguais
                verificaVizinho(&c, i->x+1, i->y);     //em suas proximidades

            else if (verificaNodeQ(c.inundado, i->x+1, i->y))   //Se ele for igual ao elemento de inundação, então ele não precisa ser verificado
                c.inundado = enqueue(c.inundado, i->x+1, i->y); //é incluído diretamente na fila de inundados

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
    int vetor[8] = {-1}; //Vetor de contador
    Lista *i = c.vizinhos;
    while(i != NULL) //Aqui verificamos quantas vezes o mesmo elemento se repetiu na lista de vizinhos
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
        else if(c.matriz[i->x][i->y] == 6)
            vetor[6]++;
        else if(c.matriz[i->x][i->y] == 7)
            vetor[7]++;
        i = remover(i, i->x, i->y); //função remover da lista já  faz com que passe para próximo node da lista
    }

    int aux = -1;
    int indice = -1;
    for(int i = 0; i <= 7; i++)
    {
        if(vetor[i] > aux) //Priorizamos aquele que verificado antes, ou seja, do menor elemento, para o maior
        {
            aux = vetor[i];
            indice = i;
        }
    }
    printf("Candidato %d\n", indice);
    return indice;
}
void resolveJogo(Campo c, int passos)
{
    int x = 1, y = 1;
    c.inundado = enqueue(c.inundado, x, y);

    while(passos < 64) //Primeira condição para ganhar o jogo
    {
        printf("Passo %d\n", passos);
        trocaElemento(c, x, y, melhorCandidato(c));
        imprimeCampo(c);
        printf("\n\n");

        if(!verificaJogo(c)) //Se ele venceu, o laço se quebra, voltando para a função jogar
            break;

        else
            passos++;
    }

}
int jogar(Campo c, int passos)
{
    imprimeCampo(c);
    resolveJogo(c, passos); //Resolução autônoma do jogo
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
    return verificaJogo(c); //Venceu ou não o jogo
}

int main()
{
    int lin = 28; // Linha e Coluna possuem dois valores de sacrifício, um que servia como índice para ajudar no direcionamento do usuário no jogo base
    int col = 28; // Enquanto a outra ajudava a evitar que fossem acessadas, posições indevidas de memória.
    Campo c = montaCampo(lin, col);
    if(jogar(c, 1))
        printf("Perdeu!\n");
    else
        printf("Ganhou!!\n");
    return 0;
}
