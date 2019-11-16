/* Programa: Laboratório #7 - lab7.c
 
   Autor: Carlos Guilherme Moraes
 
   Versao: 1.0 - 17/07/2019 
*/
 
// ##################### Bibliotecas Externas ##############################
 
#include <stdio.h>
#include <stdlib.h>
 
// ########################## TAD X.h ######################################
 
struct elemento {
    int carro;
    struct elemento *ant;
};
typedef struct elemento tipoElemento;
 
struct pilha {
    int tamanhoPilha;
    tipoElemento *topo;
};
typedef struct pilha tipoPilha;
 
void inicializaPilha(tipoPilha *pilhaAux)
{
    pilhaAux->topo     = NULL;
    pilhaAux->tamanhoPilha = 0;
}
 
// ###################### Funcoes e Procedimentos do programa ##############
 
void insereElementoFinal(tipoPilha *pilhaAux)
{
    tipoElemento *novo = (tipoElemento *)malloc(sizeof(tipoElemento));
    scanf("%d", &novo->carro);
    if (pilhaAux->tamanhoPilha == 0) {
        novo->ant = NULL;
    } else {
        novo->ant = pilhaAux->topo;
    }
    pilhaAux->topo = novo;
    pilhaAux->tamanhoPilha++;
}
 
void removeElementoFinal(tipoPilha *pilhaAux)
{
    tipoElemento *aux = pilhaAux->topo;
    int carro;
    scanf("%d", &carro);
    if (carro == pilhaAux->topo->carro) {
        pilhaAux->topo = aux->ant;
        free(aux);
        pilhaAux->tamanhoPilha--;
        return;
    } else {
        printf("Não foi possível remover esse carro agora\n");
        return;
    }
}
 
void imprimePilha(tipoPilha *pilhaAux)
{
    tipoElemento *aux = pilhaAux->topo;
    int i;
    while (aux != NULL) {
        printf("%d ", aux->carro);
        aux = aux->ant;
    }
  printf("\n");
}
 
// ############################ Principal ###################################
 
int main()
{
    tipoPilha pilhaPrincipal;
    int i, operacoes, acao;
    inicializaPilha(&pilhaPrincipal);
    scanf("%d", &operacoes);
    for (i = 0; i < operacoes; i++) {
        scanf("%d", &acao);
        if (acao == 1) {
            insereElementoFinal(&pilhaPrincipal);
            imprimePilha(&pilhaPrincipal);
        } else {
            removeElementoFinal(&pilhaPrincipal);
            imprimePilha(&pilhaPrincipal);
        }
    }
    return 0;
}