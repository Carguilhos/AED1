/*                       ESTACIONAMENTO

Prof. Valério Rosset - UNIFESP

1 DEFINIÇÃO DO PROBLEMA

Devido ao grande volume de carros circulando nas grandes cidades, muitas opções
de estacionamento também surgiram para atender a demanda. Um formato de estacionamento
muito comum é em filas, geralmente é feito de forma adaptada em um
espaço que à princípio não foi feito para estacionar carros. O objetivo desse exercício
é simular o gerenciamento de um espaço parecido com esse.

TAREFA A

Desenvolva um algoritmo em linguagem C - utilizando pilha dinâmica - que forneça
uma fila de carros estacionados. Em qualquer tentativa de mudança a pilha deve ser
impressa.

Seu algoritmo deve ser capaz de realizar as seguintes operações:

 Inserção: Seu programa deve permitir a inserção de carros. Cada carro terá
um código e esse deve ser inserido. Como a estrutura de dados é uma pilha, a
inserção e remoção ocorrem sempre na mesma extremidade.

 Remoção: Seu programa deve permitir a remoção de carros, desde que o carro
selecionado esteja na extremidade da pilha.

ENTRADA

A entrada contém um único conjunto de teste, que deve ser lido do dispositivo de
entrada padrão (normalmente o teclado). O conjunto de teste é composto por L + 1,
1 <= L <= 100 linhas.

1. A primeira linha contém o número de operações que será realizado L.

2. Em cada uma das L linhas seguintes são dadas as informações da operação.
São permitidas 2 operações:

a) Inserção de carros (1): Nesse caso, a linha é composta por 2 inteiros separados
por um espaço. O primeiro valor OP identifica a operação, no caso
1. O segundo valor V, 1 <= V <= 100, indica o código do carro. Ou seja, o
valor que será inserido na pilha.

b) Remoção de carros (2): Nesse caso, a linha é também composta por 2 inteiros
separados por um espaço. O primeiro valor OP identifica a operação,
no caso 2. O segundo valor V, 1 <= V <= 100, indica o código do carro. Ou
seja, o valor que será retirado da pilha caso esteja na extremidade.

Para as operações de entrada, considere a sintaxe:

scanf("%d, &variável);
scanf("%d %d", &variavel, &variável);

SAÍDA

Como saída padrão, seu programa deverá imprimir a pilha de carros sempre que
houver uma operação de inserção ou remoção. Além disso, caso haja uma tentativa
de remoção de um carro que não esteja na extremidade da pilha, seu programa deverá
imprimir a mensagem: "Não foi possível remover esse carro agora".

Para as operações de saída, considere a sintaxe:

printf("%d ", itemdapilha);

EXEMPLO 1
                         Entrada Saída
                         5       1
                         1 1     2 1
                         1 2     3 2 1
                         1 3     4 3 2 1
                         1 4     Não foi possível remover esse carro agora
                         2 3     4 3 2 1

EXEMPLO 2
                         Entrada Saída
                         7       2
                         1 2     4 2
                         1 4     5 4 2
                         1 5     3 5 4 2
                         1 3     5 4 2
                         2 3     8 5 4 2
                         1 8     6 8 5 4 2
                         1 6

OBSERVAÇÕES

 É fundamental que o programa imprima apenas o valor de saída.

 Os exercícios devem ser postados no site http://judge.sjc.unifesp.br.

 Cada aluno deverá postar apenas um exercício dentro da data limite.

 A resolução submetida deve utilizar a estrutura de dados definida no enunciado
do exercício.

 Os plágios serão penalizados. Como não será possível saber quem copiou,
todos os casos envolvidos receberão punições iguais, portanto, não divulgue
seu código.*/

// #########################################################################

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
