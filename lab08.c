/* Programa: Laboratório #8 - lab8.c
 
   Autor: Carlos Guilherme Moraes
 
   Versao: 1.0 - 06/09/2019
*/
 
// ##################### Bibliotecas Externas ##############################
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ########################## TAD X.h ######################################

struct noArvoreBinaria {
	char nome[100];
	char pai[100];
	char sexo;
	int nascimento;
	struct noArvoreBinaria *esq;
	struct noArvoreBinaria *dir;
};
typedef struct noArvoreBinaria tipoNoAB;

tipoNoAB *criaArvore()
{
	tipoNoAB *no = (tipoNoAB *)malloc(sizeof(tipoNoAB));
	scanf("%s %c %d", no->nome, &no->sexo, &no->nascimento);
	no->esq = NULL;
	no->dir = NULL;
	return no;
}

tipoNoAB *novoElemento()
{
	tipoNoAB *novoElemento = (tipoNoAB *)malloc(sizeof(tipoNoAB));
	scanf("%s %c %d %s", novoElemento->nome, &novoElemento->sexo,
	      &novoElemento->nascimento, novoElemento->pai);
	novoElemento->dir = NULL;
	novoElemento->esq = NULL;
	return novoElemento;
}

tipoNoAB *encontraPai(tipoNoAB *Aux, char *noPai)
{
	if (Aux != NULL) {
		if (strcmp(Aux->nome, noPai) == 0)
			return Aux;
		else {
			tipoNoAB *NovoPai = encontraPai(Aux->esq, noPai);
			if (NovoPai == NULL)
				NovoPai = encontraPai(Aux->dir, noPai);
			return NovoPai;
		}
	} else {
		return NULL;
	}
}

// ###################### Funcoes e Procedimentos do programa ##############

void removerNo(tipoNoAB *Aux)
{
	if (Aux != NULL) {
		removerNo(Aux->esq);
		removerNo(Aux->dir);
		free(Aux);
	}
}

void remover(tipoNoAB *Aux)
{
	char nome[50];
	scanf("%s", nome);
	tipoNoAB *aux2;
	aux2 = encontraPai(Aux, nome);
	tipoNoAB *pai;
	pai = encontraPai(Aux, aux2->pai);
	if (pai == NULL)
		free(Aux);
	if (strcmp(pai->esq->nome, nome) == 0)
		pai->esq = NULL;
	else
		pai->dir = NULL;
	removerNo(aux2);
}

void inserir(tipoNoAB *Aux)
{
	tipoNoAB *novoNo;
	novoNo = novoElemento();
	tipoNoAB *pai;
	pai = encontraPai(Aux, novoNo->pai);
	if (pai->esq == NULL)
		pai->esq = novoNo;
	else
		pai->dir = novoNo;
}

void imprimirPreOrdem(tipoNoAB *arvore)
{
	if (arvore != NULL) {
		printf("%s\n", arvore->nome);
		imprimirPreOrdem(arvore->esq);
		imprimirPreOrdem(arvore->dir);
	}
}

// ############################ Principal ###################################

int main()
{
	int movimentacoes, opcao, i;
	tipoNoAB *arvore = criaArvore();
	scanf("%d", &movimentacoes);
	if (movimentacoes >= 1 || movimentacoes <= 100) {
		for (i = 0; i < movimentacoes; i++) {
			scanf("%d", &opcao);
			if (opcao == 1)
				inserir(arvore);
			else if (opcao == 2)
				remover(arvore);
		}
		imprimirPreOrdem(arvore);
	}
	return 0;
}