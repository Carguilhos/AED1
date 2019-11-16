/* Programa: Laboratório #3 - lab3.c
 
   Autor: Carlos Guilherme Moraes
 
   Versao: 1.0 - 17/07/2019
*/
 
// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>
#define N 100

// ########################## TAD X.h ######################################

struct elemento
{
    int codigo;
    int quantidade;
    float preco;
    float lucro;
    struct elemento *prox;
};
 
typedef struct elemento
    tipoElemento;
 
struct listaDE
{
    tipoElemento *primeiro;
    tipoElemento *ultimo;
    int tamanhoLista;
};
 
typedef struct listaDE
    tipoLDE;
 
void inicializaLista(tipoLDE *listaAux)
{
    listaAux->primeiro = NULL;
    listaAux->ultimo = NULL;
    listaAux->tamanhoLista = 0;
}
 
void insereElementoFinal(tipoLDE *listaAux, int codigo, int quantidade, int preco)
{
    int i;
    tipoElemento *novoElem = malloc(sizeof(tipoElemento));
    tipoElemento *aux = listaAux->primeiro;
    novoElem->codigo = codigo;
    novoElem->quantidade = quantidade;
    novoElem->preco = preco;
    novoElem->lucro = 0;
    if (listaAux->tamanhoLista == 0)
    {
        novoElem->prox = NULL;
        listaAux->primeiro = novoElem;
        listaAux->ultimo = novoElem;
        listaAux->tamanhoLista++;
    }
    else if (preco >= listaAux->primeiro->preco)
    {
        novoElem->prox = aux;
        listaAux->primeiro = novoElem;
        listaAux->tamanhoLista++;
        return;
    }
    else if (preco < listaAux->ultimo->preco)
    {
        listaAux->ultimo->prox = novoElem;
        listaAux->ultimo = novoElem;
        listaAux->tamanhoLista++;
        return;
    }
    else
    {
        for (i = 0; i < listaAux->tamanhoLista - 1; i++)
        {
            if (novoElem->preco >= aux->prox->preco)
            {
                novoElem->prox = aux->prox;
                aux->prox = novoElem;
                listaAux->tamanhoLista++;
                return;
            }
            aux = aux->prox;
        }
    }
}

// ###################### Funcoes e Procedimentos do programa ##############

int procurarElemento(tipoLDE *listaAux, int codigo)
{
    int i;
    tipoElemento *aux = listaAux->primeiro;
    for (i = 0; i < listaAux->tamanhoLista; i++)
    {
        if(codigo == aux->codigo)
        {
            printf("O jogo já está cadastrado\n");
            return 0;
        }
        aux = aux->prox;
    }
    return 1;
}
 
void adicionarQuantidade(tipoLDE *listaAux, int codigo, int quantidade)
{
    int i;
    tipoElemento *aux = listaAux->primeiro;
    for (i = 0; i < listaAux->tamanhoLista; i++)
    {
        if (codigo == aux->codigo)
        {
            aux->quantidade = aux->quantidade + quantidade;
            return;
        }
        aux = aux->prox;
    }
    printf("Não há\n");
}
 
void alugar(tipoLDE *listaAux, int codigo)
{
    int i, lucro;
    tipoElemento *aux = listaAux->primeiro;
    for (i = 0; i < listaAux->tamanhoLista; i++)
    {
        if (codigo == aux->codigo)
        {
            if (aux->quantidade != 0)
            {
                aux->lucro = aux->lucro+aux->preco;
                aux->quantidade--;
                return;
            }
            else
            {
                printf("Não há\n");
                return;
            }
        }
        aux = aux->prox;
    }
    printf("Não há\n");
}
 
void excluirElemento(tipoLDE *listaAux, int codigo)
{
    int i;
    tipoElemento *aux = listaAux->primeiro;
    if (codigo == aux->codigo)
    {
        listaAux->primeiro = aux->prox;
        listaAux->tamanhoLista--;
        free(aux);
        return;
    }
    else
    {
        for (i = 0; i < listaAux->tamanhoLista; i++)
        {
            if (codigo == aux->prox->codigo)
            {
                aux->prox = aux->prox->prox;
                listaAux->tamanhoLista--;
                free(aux->prox);
                return;
            }
        }
    }
    printf("Não há\n");
}
 
void imprimirElemento(tipoLDE *listaAux, int codigo)
{
    int i;
    tipoElemento *aux = listaAux->primeiro;
    for (i=0; i< listaAux->tamanhoLista; i++)
    {
        printf("%d %f \n", aux->codigo, aux->lucro);
        aux = aux->prox;
    }
}

// ############################ Principal ###################################

int main()
{
    tipoLDE listaPrincipal;
    int i, aux, movimentacoes, acao, codigo, quantidade;
    float preco;
    inicializaLista(&listaPrincipal);
    scanf("%d ", &movimentacoes);
    for (i = 0; i < movimentacoes; i++)
    {
        scanf("%d ", &acao);
        if (acao == 1)
        {
            scanf("%d %d %f", &codigo, &quantidade, &preco);
            aux = procurarElemento(&listaPrincipal, codigo);
            if (aux)
            {
                insereElementoFinal(&listaPrincipal, codigo, quantidade, preco);
            }
        }
        else if (acao == 2)
        {
            scanf("%d %d", &codigo, &quantidade);
            adicionarQuantidade(&listaPrincipal, codigo, quantidade);
        }
        else if (acao == 3)
        {
            scanf("%d", &codigo);
            alugar(&listaPrincipal, codigo);
        }
        else
        {
            scanf("%d", &codigo);
            excluirElemento(&listaPrincipal, codigo);
        }
    }
    imprimirElemento(&listaPrincipal, codigo);
    return 0;
}