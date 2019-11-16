/* Programa: Laboratório #5 - lab5.c
 
   Autor: Carlos Guilherme Moraes
 
   Versao: 1.0 - 17/07/2019
*/
 
// ##################### Bibliotecas Externas ##############################
 
#include <stdio.h>
#include <stdlib.h>
 
// ########################## TAD X.h ######################################
 
struct elemento {
    int criancas;
    struct elemento *prox;
    struct elemento *ant;
};
 
typedef struct elemento tipoElemento;
 
struct estruturaLCDDE {
    tipoElemento *primeiro;
    int tamanhoLista;
};
 
typedef struct estruturaLCDDE tipoLCDDE;
 
void inicializaLista(tipoLCDDE *listaAux)
{
 
    listaAux->primeiro     = NULL;
    listaAux->tamanhoLista = 0;
}
 
void insereElementoFinal(tipoLCDDE *listaAux, int criancas)
{
    tipoElemento *novo = (tipoElemento *)malloc(sizeof(tipoElemento));
    tipoElemento *aux  = listaAux->primeiro;
    novo->criancas     = criancas;
    if (listaAux->tamanhoLista == 0) {
        novo->prox     = novo;
        novo->ant      = novo;
        listaAux->primeiro = novo;
    } else {
        novo->prox              = listaAux->primeiro;
        novo->ant              = listaAux->primeiro->ant;
        listaAux->primeiro->ant->prox = novo;
        listaAux->primeiro->ant       = novo;
    }
    listaAux->tamanhoLista++;
}
 
// ###################### Funcoes e Procedimentos do programa ##############
 
void removeCrianca(tipoLCDDE *listaAux, int paes, int quant)
{
    int i;
    tipoElemento *aux = listaAux->primeiro->ant;
    printf("Passadas na lista: %d\n", paes / quant);
    paes = paes % quant;
    for (i = 0; i <= paes; i++) {
        if (i == paes) {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
            listaAux->tamanhoLista--;
            if (i == 1) {
                listaAux->primeiro = aux->prox;
            }
            free(aux);
            return;
        }
        aux = aux->prox;
    }
}
 
void imprimeLista(tipoLCDDE *listaAux)
{
    int i;
    tipoElemento *aux = listaAux->primeiro;
    for (i = 0; i < listaAux->tamanhoLista; i++) {
        printf("%d ", aux->criancas);
        aux = aux->prox;
    }
    printf("\n");
}
 
// ############################ Principal ###################################
 
int main()
{
    tipoLCDDE listaPrincipal;
    int i, quant, paes, criancas;
    inicializaLista(&listaPrincipal);
    scanf("%d", &quant);
    if(quant < 3 || quant > 10){
        return 0;
    }
    for (i = 0; i < quant; i++) {
        scanf("%d", &criancas);
        if(criancas < 0 || criancas > 9){
            return 0;
        }
        insereElementoFinal(&listaPrincipal, criancas);
    }
    imprimeLista(&listaPrincipal);
    scanf("%d", &paes);
    if(paes < 11 || paes > 100){
        return 0;
    }
    removeCrianca(&listaPrincipal, paes, quant);
    imprimeLista(&listaPrincipal);
    return 0;
}