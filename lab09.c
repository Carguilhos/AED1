/*                       Labirinto

Prof. Valério Rosset – UNIFESP

1 DEFINIÇÃO DO PROBLEMA

Segundo a mitologia grega, o Labirinto de Creta foi construído para prender o Minotauro,
personagem mitológico com corpo humano e cabeça de touro. Teseu, filho do rei
Egeu, se apresentou para adentrar o Labirinto e matar o monstro. Após adentrar um
salão cheio de pilhas de ossos no qual Minotauro estava, Teseu conseguiu matá-lo.
Agora, Teseu precisa da sua ajuda para voltar ao salão inicial e escapar do Labirinto.
Considere que o Labirinto de Creta é composto por vários salões e que eles estão
conectados por caminhos diferentes. No entanto, todos os caminhos possuem obstáculos
que possibilitam que Teseu atravesse somente em um sentido.

Por exemplo, a figura 1.1 representa um possível labirinto. Nesse exemplo, Teseu se
encontra no salão número 0 e precisa chegar ao salão número 6. Note que os caminhos
possuem somente um sentido. Ou seja, Teseu pode ir do salão 0 diretamente
para o salão 1, pois existe um caminho nesse sentido. No entanto, Teseu não pode ir
do salão 1 para o salão 0 diretamente, pois não existe caminho nesse sentido.

TAREFA A

Desenvolva um algoritmo em linguagem C - utilizando grafos - que seja capaz de
informar a Teseu quantos caminhos existem para ele escapar do labirinto. Para isso,
seu algoritmo deverá utilizar busca em profundidade (DFS). Note que laços (5 -> 2
-> 3 -> 5) não são considerados parte do caminho. Ou seja, os caminhos não podem
possuir nós duplicados. Por exemplo, considerando o labirinto da figura 1.1, só existem
3 caminhos possíveis:

 0 -> 1 -> 5 -> 4 -> 6
 0 -> 2 -> 1 -> 5 -> 4 -> 6
 0 -> 2 -> 3 -> 5 -> 4 -> 6

ENTRADA

A entrada contém um único conjunto de teste, que deve ser lido do dispositivo de
entrada padrão (normalmente o teclado). O conjunto de teste é composto por L + 2,
1 <= L <= 100 linhas.

1. A primeira linha contém dois inteiros V, 2 <= V <= 100 e E, 1 <= E <= 100. V
representa o número de salões existentes no labirinto (o número de vértices do
grafo) e E representa o número de caminhos (o número de arestas do grafo).

2. Em cada uma das L linhas seguintes são informados o salão de origem e o salão
de destino de um caminho.

3. A última linha contém dois inteiros, I e F, onde I é o salão no qual Teseu se
encontra e F é o salão para o qual Teseu deseja ir para sair do labirinto.
Para as operações de entrada, considere a sintaxe:
scanf("%d %d", &v1, &v2);

SAÍDA

Como saída padrão, seu programa deverá imprimir o número de caminhos existentes
para Teseu escapar do labirinto.

Para as operações de saída, considere a sintaxe:

printf("%d\n", v);

EXEMPLO 1 - FIGURA 1.1
                         Entrada Saída
                         7 13    3
                         0 1
                         0 2
                         1 5
                         2 1
                         2 3
                         3 0
                         3 5
                         4 0
                         4 1
                         4 3
                         4 6
                         5 2
                         5 4
                         0 6

EXEMPLO 1 - FIGURA 1.2

                         Entrada Saída
                         7 13    7
                         0 1
                         0 2
                         1 5
                         2 1
                         2 3
                         3 0
                         3 5
                         4 0
                         4 1
                         4 3
                         4 6
                         5 2
                         5 4
                         4 5

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

/* Programa: Laboratório #9 - lab9.c
 
   Autor: Carlos Guilherme Moraes
 
   Versao: 1.0 - 06/09/2019 */

// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>
#define MAXVERTICES 50

// ########################## TAD X.h ######################################

typedef struct {
	int Adj[MAXVERTICES][MAXVERTICES];
	int NVertices;
	int NArestas;
	int v[MAXVERTICES];

} TGrafo;

void inicia_grafo(TGrafo *A)
{
	int i, j;
	for (i = 0; i < MAXVERTICES; i++) {
		for (j = 0; j < MAXVERTICES; j++) {
			A->Adj[i][j] = 0;
		}
	}
}

void zera_vetor(TGrafo *A)
{
	int i;
	for (i = 0; i < MAXVERTICES; i++) {
		A->v[i] = 0;
	}
}

void insere_aresta(TGrafo *A, int V1, int V2) { A->Adj[V1][V2] = 1; }

int busca_caminho(TGrafo *A, int I, int F, int caminhos)
{
	int j, aux = 0;
	for (j = 0; j < A->NVertices; j++) {
		if (j == F && A->Adj[I][j] == 1) {
			caminhos++;
		} else if (A->Adj[I][j] == 1 && A->v[j] == 0) {
			A->v[j]  = 1;
			caminhos = busca_caminho(A, j, F, caminhos);
			A->v[j]  = 0;
		}
	}
	return caminhos;
}

// ###################### Funcoes e Procedimentos do programa ##############

// ############################ Principal ###################################

int main()
{
	int i, V1, V2, I, F, caminhos = 0;
	TGrafo grafoPrincipal;
	inicia_grafo(&grafoPrincipal);
	scanf("%d %d", &grafoPrincipal.NVertices, &grafoPrincipal.NArestas);

	for (i = 0; i < grafoPrincipal.NArestas; i++) {
		scanf("%d %d", &V1, &V2);
		insere_aresta(&grafoPrincipal, V1, V2);
	}
	scanf("%d %d", &I, &F);
	zera_vetor(&grafoPrincipal);
	grafoPrincipal.v[I] = 1;
	caminhos	    = busca_caminho(&grafoPrincipal, I, F, caminhos);

	printf("%d\n", caminhos);
	return 0;
}
