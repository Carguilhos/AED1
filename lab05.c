/*                       A-DO-LE-TA

Prof. Valério Rosset - UNIFESP

1 DEFINIÇÃO DO PROBLEMA

Aqui no Brasil uma brincadeira muito comum em grupos de crianças é Adoleta. É uma
brincadeira que veio da França e que tem muitas versões brasileiras dependendo da
região. Uma das versões, se encontra abaixo:

A do le ta,
Le com i,
Le com a,
Le café com chocola,
A do le ta,
Puxa o rabo da panela,
Quem saiu foi ela,
O padeiro já passou,
Quantos pães ele deixou?
(Retirado de: Consciência fonológica: coletânea de atividades orais para a sala de
aula, 2017)

TAREFA A

Nesse contexto, desenvolva um programa em linguagem C - utilizando lista circular
- que simule uma parte da brincadeira do Adoleta. Seu programa deve receber a
quantidade de crianças (até 10) e em seguida permitir a inserção dos números que
representem essas crianças, começando em 0 em diante, sempre de forma sequêncial.

Seguindo a ultima frase da brincadeira (Quantos pães ele deixou?), o programa deve
permitir a inserção do número de pães (até 100) e remover contando á partir do
primeiro elemento da lista (o número 0), o elemento que o número de pães irá representar,
considerando que o número de pães sempre deve ser superior á 10 e que
depois que acabarem os elementos da lista a contagem volta ao começo da lista novamente

ENTRADA

A entrada contém um conjunto de teste, que deve ser lido do dispositivo de entrada
padrão (normalmente o teclado). O conjunto de teste é composto por 3 linhas.

1. A primeira linha contém um valor inteiro L, 3 <= L <= 10, que representa a quantidade
de crianças que farão parte da brincadeira.

2. A linha seguinte contém a númeração das crianças (C), começando em 0, 0 <=
C <= 9. Separadas por espaço.

3. E a próxima linha de entrada será a quantidade de pães (P), 11 <= P <= 100.

Para as operações de entrada, considere a sintaxe:

scanf("%d",&variavel);
scanf("%d",&lista);
scanf("%d",&variavel);

SAÍDA

Como saída padrão, seu programa deve imprimir as seguintes informações:

1. Assim que os números das crianças forem inseridos na lista, esta deve ser impressa.
Dessa forma é possível conferir se todos os números foram inseridos
corretamente. As numerações das crinças devem ser exibidas em uma única
linha separadas por espaço.

2. Após a remoção do número que representa uma das crinças, deve ser exibida a
mensagem: "Passadas na lista: VÁRIÁVEL". Que representa quantas vezes a
lista foi percorrida de forma inteira.

3. Por último, deve ser impressa a lista com todos os elementos iniciais, menos
aquele que foi removido pela brincadeira.
Para as operações de saída, considere a sintaxe:

printf("%d", lista);
printf("Passadas na lista: %d", variável);
printf("%d", lista);

                         Entrada             Saída
                         7                   0 1 2 3 4 5 6
                         0 1 2 3 4 5 6       Passadas na lista: 1
                         13                  0 1 2 3 4 6

                         Entrada             Saída
                         10                  0 1 2 3 4 5 6 7 8 9
                         0 1 2 3 4 5 6 7 8 9 Passadas na lista: 3
                         35                  0 1 2 3 5 6 7 8 9

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
