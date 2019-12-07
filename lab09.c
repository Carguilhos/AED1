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