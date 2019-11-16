/*                       TRABALHO NO ESCRITÓRIO

Prof. Valério Rosset - UNIFESP

1 DEFINIÇÃO DO PROBLEMA

Você trabalha em uma empresa como desenvolvedor e precisa organizar suas tarefas
e assim decidiu desenvolver uma fila de tarefas. Algumas tarefas são periódicas, ou
seja, você deve realizar toda semana. Assim, você decidiu incluir uma opção para
mover uma tarefa concluída de volta para o final da fila.

TAREFA A

Desenvolva um algoritmo em linguagem C - utilizando fila estática circular - que
forneça uma fila com as tarefas. Ao final da execução, seu algoritmo deverá imprimir
a fila de tarefas.

Seu algoritmo deve ser capaz de realizar as seguintes operações:

 Inserção: Seu algoritmo deve permitir a inserção de tarefas. Note que a única
informação inserida na fila é o código da tarefa. Como a estrutura utilizada é fila,
a inserção ocorre sempre no final da fila.

 Remoção: Seu algoritmo deve permitir a remoção de tarefas. Como a estrutura
utilizada é fila, a remoção ocorre sempre no inicio da fila.

 Conclusão: Seu algoritmo deve permitir a conclusão de tarefas. Nesse caso, o
elemento do início da fila deverá ser deslocado para o final da fila.

ENTRADA

A entrada contém um único conjunto de teste, que deve ser lido do dispositivo de
entrada padrão (normalmente o teclado). O conjunto de teste é composto por L + 1,
1 <= L <= 100 linhas.

1. A primeira linha contém o número de operações que será realizado L.

2. Em cada uma das L linhas seguintes são dadas as informações da operação.
São permitidas 3 operações:

a) Inserção de Tarefas (1): Nesse caso, a linha é composta por 2 inteiros
separados por um espaço. O primeiro valor OP identifica a operação, no
caso 1. O segundo valor V, 1 <= V <= 100, indica o código da tarefa. Ou
seja, o valor que será inserido na fila.

b) Remoção de Tarefas (2): Nesse caso, a linha é composta por 1 inteiro OP
que identifica a operação, no caso 2.

c) Conclusão de Tarefas (3): Nesse caso, a linha é composta por 1 inteiro OP
que identifica a operação, no caso 3.
Para as operações de entrada, considere a sintaxe:
scanf("%d",&variavel);

SAÍDA

Como saída padrão, seu programa deverá imprimir a fila ao final da execução. Além
disso, caso a fila esteja vazia e ocorra alguma tentativa de remoção ou conclusão de
tarefas, seu programa deverá imprimir a mensagem: "A fila está vazia".

Para as operações de saída, considere a sintaxe:

printf("%d ", itemdafila);

EXEMPLO 1

OBSERVAÇÃO: Nesse exemplo, para demonstrar o funcionamento do algoritmo, a fila
é exibida após cada operação. Contudo, seu algoritmo deverá imprimir a fila somente
ao final da execução, como nos exemplos 2 e 3.

                         Entrada Saída
                         6       1
                         1 1     2 1
                         1 2     3 2 1
                         1 3     3 2
                         2       2 3
                         3       2
                         2

EXEMPLOS 2 E 3

                         Entrada Saída
                         6       2
                         1 1
                         1 2
                         1 3
                         2
                         3
                         2
                         
                         Entrada Saída
                         5       A fila está vazia
                         2       2 1
                         1 1
                         1 2
                         3
                         3
                         
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

/* Programa: Laboratório #6 - lab6.c
 
   Autor: Carlos Guilherme Moraes
 
   Versao: 1.0 - 17/07/2019
*/
 
// ##################### Bibliotecas Externas ##############################
 
#include <stdio.h>
#include <stdlib.h>
#define tamanhoMAX 10
 
// ########################## TAD X.h ######################################
 
struct filaCircular {
    int primeiro;
    int ultimo;
    int elementos[tamanhoMAX];
};
typedef struct filaCircular tipoFC;
 
void inicializaFila(tipoFC *filaAux)
{
  int i;
    filaAux->primeiro = -1;
    filaAux->ultimo   = -1;
    for (i = 0; i < tamanhoMAX; i++)
        filaAux->elementos[i] = 0;
}
 
int filaVazia(tipoFC *filaAux)
{
    if ((filaAux->primeiro == filaAux->ultimo) && (filaAux->ultimo == -1))
    return 1;
    else
        return 0;
}
 
int filaCheia(tipoFC *filaAux)
{
    if (((filaAux->ultimo + 1) % tamanhoMAX) == filaAux->primeiro)
        return 1;
    else
        return 0;
}
 
// ###################### Funcoes e Procedimentos do programa ##############
 
void insereElementoInicial(tipoFC *filaAux, int codigo, int cont)
{
    int i;
    if (cont != 1) {
        if ((filaAux->primeiro == filaAux->ultimo) &&
            filaAux->primeiro != 0) {
            filaAux->primeiro     = 0;
            filaAux->ultimo       = 0;
            filaAux->elementos[0] = codigo;
        } else {
            filaAux->ultimo++;
            filaAux->elementos[filaAux->ultimo] = codigo;
        }
    }
}
 
int removeElemento(tipoFC *filaAux, int cont)
{
    if (cont != 1 && filaAux->ultimo>=filaAux->primeiro){
        filaAux->primeiro++;
        return 1;
    }
    printf("A fila está vazia\n");
    return 0;
}
 
int conclusaoFila(tipoFC *filaAux, int cont)
{
    if (cont != 1 && filaAux->ultimo>=filaAux->primeiro) {
        filaAux->elementos[filaAux->ultimo+1] = filaAux->elementos[filaAux->primeiro];
        filaAux->primeiro++;
        filaAux->ultimo++;
    return 1;
    }
  printf("A fila está vazia\n");
  return 0;
}
 
void imprimeFila(tipoFC *filaAux)
{
    int i;
    for (i = filaAux->ultimo; i >= filaAux->primeiro; i--) {
        printf("%d ", filaAux->elementos[i]);
    }
    printf("\n");
}
 
// ############################ Principal ###################################
 
int main()
{
    tipoFC filaPrincipal;
    int i, numero, operacao, codigo, cont;
    inicializaFila(&filaPrincipal);
    scanf("%d", &numero);
    for (i = 0; i < numero; i++) {
        scanf("%d", &operacao);
        if (operacao == 1) {
            scanf("%d", &codigo);
            cont = filaCheia(&filaPrincipal);
            insereElementoInicial(&filaPrincipal, codigo, cont);
        } else if (operacao == 2) {
            cont = filaVazia(&filaPrincipal);
            cont = removeElemento(&filaPrincipal, cont);
        } else {
            cont = filaVazia(&filaPrincipal);
            cont = conclusaoFila(&filaPrincipal, cont);
        }
    }
    if (cont != 0){
        imprimeFila(&filaPrincipal);
    }
    return 0;
}
