/*                       Que 12 é esse?

Prof. Valério Rosset – UNIFESP, Unidade Pq. Tecnológico, sala 05
E-mail: vrosset@unifesp.br

1 DEFINIÇÃO DO PROBLEMA

Inspirados em 12 É DEMAIS, você deve aplicar seus conhecimentos de Algoritmos e
Estrutura de Dados, e desenvolver um programa com o objetivo de formar o número
12. Dessa forma, o usuário deve formar triplas de números que juntas somem 12. Seu
programa deve funcionar assim:

 Inicialmente, uma sequência de 10 números inteiros entre 0 e 9 é fornecida ao
jogador. Por exemplo: 1 2 3 4 5 6 7 8 9 0

 Em seguida, o jogador terá 5 jogadas. Em cada jogada, o jogador fornece um
número para ser inserido na lista e a posição da lista na qual o número deverá
ser inserido. Por exemplo: 9 1

 Após a inserção, a lista é atualizada com o novo valor. Observe que os elementos
da lista são deslocados para a direita para que a inserção ocorra na posição
desejada: 1 9 2 3 4 5 6 7 8 9 0

 Observe que agora existe uma tripla que soma 12: 1 9 2 3 4 5 6 7 8 9 0

 Agora, todos os elementos que formam a tripla de soma 12 são removidos da
lista: 3 4 5 6 7 8 9 0

 O objetivo é remover todos os elementos da lista em 5 jogadas.

TAREFA A

Desenvolva um algoritmo em linguagem C - utilizando lista dinâmica duplamente
encadeada - que insira uma lista com a sequência inicial, ao qual será fornecida. Após
cada jogada, seu algoritmo deverá imprimir a lista atualizada após as verificações de
triplas e as remoções necessárias. Ao final da execução, seu algoritmo deve informar
se foi possivel remover todas as triplas de 12 ou se não. De forma que só possível
ganhar se todos os elementos da lista forem eliminados.

Seu algoritmo deve ser capaz de realizar as seguintes operações:

 Inserção: Seu algoritmo deve permitir a inserção dos 10 primeiros números
para o jogo começe e dos números em suas devidas posições de acordo com a
jogada desejada. Note que a posição é calculada a partir do primeiro elemento
da lista. Esse primeiro elemento representa o primeiro número da sequência
inicial, ao qual a posição é 0.

 Remoção: Seu algoritmo deve permitir a remoção de elementos de acordo com
as triplas formadas.

 Análise: Após cada jogada, seu algoritmo deverá buscar por triplas de soma 12
e realizar as devidas remoções. Note que uma jogada não implica necessariamente
em remoção.

ENTRADA

A entrada contém um único conjunto de teste, que deve ser lido do dispositivo de
entrada padrão (normalmente o teclado). O conjunto de teste é composto por 6 linhas.

1. A primeira linha contém uma sequência de 10 números iniciais, esses números
devem ser de 0 a 9.

2. Em cada uma das 5 linhas seguintes são dadas as informações da jogada. Cada
linha contém um valor inteiro X, 1  X  9, que representa o número a ser
inserido, seguido de um espaço e a posição desejada de inserção. Note que a
primeira posição da lista é a posição 0.

Para as operações de entrada, considere a sintaxe:

scanf("%d, &itemdalista);
scanf("%d %d",&variavel1, &variavel2);

Obs: Lembrando que são 10 elementos de entrada na lista.

SAÍDA

Como saída padrão, seu programa deve imprimir a cada jogada a lista atual. Ao final
das jogadas, seu programa deverá imprimir se o jogador ganhou ou perdeu.
As mensagens de vitória ou derrota são:

1. Ganhou: "Eba, você ganhou!".

2. Perdeu: "Ih, não foi dessa vez".

Para as operações de saída, considere a sintaxe:

printf("%d ", itemdalista);
printf("Mensagem de vitória ou derrota");

                         Entrada             Saída
                         1 2 3 4 5 6 7 8 9   0 1 2 3 4 5 6 7 8 9 0
                         9 1                 6 7 8 9 0
                         3 1                 6 3 7 8 9 0
                         2 1                 6 8 9 0
                         2 3                 6 7 8 9 2 0
                         1 1                 6 1 7 8 9 2 0
                                             Ih, não foi dessa vez

                         Entrada             Saída
                         9 9 1 4 5 7 1 5 1 1 9 9 1 4 5 7 1 5 1 1
                         2 3                 9 4 5 7 1 5 1 1
                         3 3                 9 7 1 5 1 1
                         4 3                 9 5 1 1
                         6 2                 9 1
                         2 1                 Eba, você ganhou!
                         
OBSERVAÇÕES

 DICA: ao final das impressões de todos os elementos da lista, há um "espaço".

 É fundamental que o programa imprima apenas o valor de saída.

 Os exercícios devem ser postados no site http://judge.sjc.unifesp.br.

 Cada aluno deverá postar apenas um exercício dentro da data limite.

 A resolução submetida deve utilizar a estrutura de dados definida no enunciado
do exercício.

 Os plágios serão penalizados. Como não será possível saber quem copiou,
todos os casos envolvidos receberão punições iguais, portanto, não divulgue
seu código.*/

// #########################################################################

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
