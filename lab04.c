/* Programa: Laboratório #4 - lab4.c
 
   Autor: Carlos Guilherme Moraes
 
   Versao: 1.0 - 17/07/2019
*/
 
// ##################### Bibliotecas Externas ##############################
 
#include <stdio.h>
#include <stdlib.h>
 
// ########################## TAD X.h ######################################
 
struct elemento {
    int valores;
    struct elemento *prox;
    struct elemento *ant;
};
 
typedef struct elemento tipoElemento;
 
struct estruturaLDDE {
    tipoElemento *primeiro;
    tipoElemento *ultimo;
    int tamanhoLista;
};
 
typedef struct estruturaLDDE tipoLDDE;
 
void inicializaLista(tipoLDDE *listaAux)
{
 
    listaAux->primeiro     = NULL;
    listaAux->ultimo       = NULL;
    listaAux->tamanhoLista = 0;
}
 
void insereElementoFinal(tipoLDDE *listaAux, int valor)
{
    tipoElemento *novo = (tipoElemento *)malloc(sizeof(tipoElemento));
    novo->valores      = valor;
    if (listaAux->tamanhoLista == 0) {
        novo->prox     = NULL;
        novo->ant      = NULL;
        listaAux->primeiro = novo;
        listaAux->ultimo   = novo;
    } else {
        novo->prox         = NULL;
        novo->ant          = listaAux->ultimo;
        listaAux->ultimo->prox = novo;
        listaAux->ultimo       = novo;
    }
    listaAux->tamanhoLista++;
}
 
// ###################### Funcoes e Procedimentos do programa ##############
 
void imprimirLista(tipoLDDE *listaAux)
{
    int i;
    tipoElemento *aux = listaAux->primeiro;
    for (i = 0; i < listaAux->tamanhoLista; i++) {
        printf("%d ", aux->valores);
        aux = aux->prox;
    }
    printf("\n");
}
 
void insereElemento(tipoLDDE *listaAux)
{
    int i, posicao;
    tipoElemento *novo = (tipoElemento *)malloc(sizeof(tipoElemento));
    tipoElemento *aux  = listaAux->primeiro;
    scanf("%d %d", &novo->valores, &posicao);
    if (posicao == 0 && listaAux->tamanhoLista != 0) {
        novo->prox        = listaAux->primeiro;
        novo->ant        = NULL;
        listaAux->primeiro->ant = novo;
        listaAux->primeiro      = novo;
        listaAux->tamanhoLista++;
        return;
    } else if(listaAux->tamanhoLista == 0){
        listaAux->primeiro = novo;
        listaAux->ultimo = novo;
        novo->prox = NULL;
        novo->ant = NULL;
        listaAux->tamanhoLista++;
        return;
    }
     else {
        for (i = 0; i < posicao; i++) {
            if (i == posicao - 1) {
                novo->prox = aux->prox;
                novo->ant  = aux;
                aux->prox  = novo;
                listaAux->tamanhoLista++;
                if (novo->prox == NULL) {
                    listaAux->ultimo = novo;
                    return;
                } else {
                    novo->prox->ant = novo;
                    return;
                }
            }
            aux = aux->prox;
        }
    }
}
 
int removeElemento(tipoLDDE *listaAux, tipoElemento *aux)
{
    tipoElemento *aux2;
    if (listaAux->tamanhoLista == 3) {
        free(aux->ant);
        free(aux);
        free(aux->prox);
        listaAux->tamanhoLista = 0;
        listaAux->primeiro     = NULL;
        listaAux->ultimo       = NULL;
        return 1;
    } else if (aux->ant == listaAux->primeiro) {
        aux = aux->prox->prox;
        free(aux->ant->ant->ant);
        free(aux->ant->ant);
        free(aux->ant);
        aux->ant           = NULL;
        listaAux->primeiro     = aux;
        listaAux->tamanhoLista = listaAux->tamanhoLista - 3;
    } else {
        aux->ant->ant->prox = aux->prox->prox;
        if (aux->prox->prox == NULL) {
            listaAux->ultimo = aux->ant->ant;
            free(aux->ant);
            free(aux);
            free(aux->prox);
            listaAux->tamanhoLista = listaAux->tamanhoLista - 3;
            return 1;
        } else {
            aux2 = aux->ant->ant;
            aux  = aux->prox->prox;
            free(aux->ant->ant->ant);
            free(aux->ant->ant);
            free(aux->ant);
            aux->ant           = aux2;
            listaAux->tamanhoLista = listaAux->tamanhoLista - 3;
            return 0;
        }
    }
}
 
int removeTripla(tipoLDDE *listaAux)
{
    int i, tamanho, cont;
    tamanho          = listaAux->tamanhoLista;
    tipoElemento *aux = listaAux->primeiro->prox, *aux2;
    for (i = 0; i < tamanho; i++) {
        if (listaAux->tamanhoLista < 3){
            return 2;
        } else if (aux->ant->valores + aux->valores + aux->prox->valores ==
            12 &&
            aux->prox != NULL && aux->ant != NULL) {
            aux2 = aux->prox->prox;
            cont = removeElemento(listaAux, aux);
            if (cont == 1) {
                return 1;
            } else if (aux2->prox == listaAux->ultimo ||
                   aux2->prox == NULL) {
                return 2;
            } else {
                aux = aux2;
            }
        } else if (listaAux->tamanhoLista<3 || aux->prox == listaAux->ultimo || aux->prox == NULL) {
            return 2;
        }
        aux = aux->prox;
    }
    return 0;
}
 
// ############################ Principal ###################################
 
int main()
{
    tipoLDDE listaPrincipal;
    int i, valor, cont;
    inicializaLista(&listaPrincipal);
    for (i = 0; i < 10; i++) {
        scanf("%d", &valor);
        insereElementoFinal(&listaPrincipal, valor);
    }
    imprimirLista(&listaPrincipal);
    for (i = 0; i < 5; i++) {
        insereElemento(&listaPrincipal);
        cont = removeTripla(&listaPrincipal);
        if (cont == 1 && i == 4) {
            printf("Eba, você ganhou!\n");
        } else if (cont == 2 && i == 4) {
            imprimirLista(&listaPrincipal);
            printf("Ih, não foi dessa vez\n");
        } else {
            imprimirLista(&listaPrincipal);
        }
    }
    return 0;
}