/*                       Árvore de Sucessão

Prof. Valério Rosset – UNIFESP

1 DEFINIÇÃO DO PROBLEMA

O casamento do príncipe Harry e a atriz americana Meghan Markle atraiu a atenção
do mundo todo para a Família Real Britânica. Como toda monarquia, a Família Real
Britânica possui uma linha de sucessão que determina quem será o próximo Rei ou
Rainha. A linha de sucessão ao trono era determinada por descendência, legitimidade,
gênero e religião. A lei que dava prioridade aos homens sobre as mulheres foi
abolida em 2011, mas se aplica aos nascidos antes desta data.

A ORDEM DE SUCESSÃO

Com o casamento de William e Kate e a possibilidade de seu primogênito ser uma
menina, o parlamento mudou as regras de sucessão para incluir mulheres. Logo,
ainda se primeiro bebe de Kate e William fosse uma menina, ela poderia ser rainha,
mesmo tendo irmãos mais novos.

O sistema de sucessão ao trono Britânico dava preferência aos homens e primogênitos.
Logo Charles, o filho mais velho da Rainha Elizabeth é o primeiro na linha de
sucessão.

Depois dele vem William, o filho mais velho de Charles e Diana.

Com o nascimento do Príncipe George, Príncipe Harry se tornou o quarto na linha de
sucessão.

O quinto herdeiro ao trono é o Principe Andrew, o terceiro filho de Elizabeth e Philip,
seguido de suas filhas Beatrice e Eugenie.

O oitavo na linha de sucessão é o caçula da Rainha, Edward, seguido de seu filho
Severn, que apesar de ser mais novo do que a irmã Lady Louise tem prioridade por
ser homem. Princesa Anne, a filha mais velha da Rainha parece apenas em décimo
primeiro lugar seguida de seu filho, netos e finalmente sua filha, a atleta olímpica Zara
Philips.

A partir do nascimento de George, mulheres terão o mesmo direito à sucessão do
que homens, logo, uma filha do Príncipe poderá ser a próxima Rainha da Inglaterra no
futuro.

TAREFA A

Desenvolva um algoritmo em linguagem C - utilizando árvore binária - que seja
capaz de fornecer a linha de sucessão ao trono. Seu algoritmo deve permitir 2 operações
básicas: inserção e remoção. Ao final da execução, você deverá a ordem de
sucessão.

Considere as seguintes regras:

 Cada nó possui no máximo 2 filhos. Ou seja, cada monarca possui no máximo
2 filhos. Note que na figura 1.1, a Rainha Elizabeth possui 4 filhos. No entanto,
nesse exercício cada nó possuirá no máximo 2 filhos.

 Quando um nó é removido da árvore, todos seus descendentes também são.

 Ao final da execução, você deverá imprimir a linha completa de sucessão.

ENTRADA

A entrada contém um único conjunto de teste, que deve ser lido do dispositivo de
entrada padrão (normalmente o teclado). O conjunto de teste é composto por L + 2,
1 <= L <= 100 linhas.

1. A primeira linha contém os dados pertinentes a raiz da árvore, ou seja, ao monarca
atualmente no poder.

2. A segunda linha contém o número L de operações que serão realizadas.

3. Em cada uma das L linhas seguintes são informados a operação que será realizada
e as informações necessárias:

 Operação 1 (Inserção): A linha contém primeiro o número da operação (1),
seguido pelo nome, gênero, idade e nome do pai/mãe.

 Operação 2 (Remoção): A linha contém primeiro o número da operação
(2), seguido pelo nome do monarca que será removido da árvore.

Para as operações de entrada, considere a sintaxe:

scanf("%s %c %d", nome, &sexo, &nascimento);
scanf("%s %c %d %s", nome, &sexo, &nascimento, pai);
scanf("%d",&variavel);

SAÍDA

Como saída padrão, seu programa deverá imprimir todos os nomes na linha de sucessão.
Considere que o primeiro nome na lista de sucessão é o do monarca atualmente
no poder (a raiz da árvore).

Para as operações de saída, considere a sintaxe:
printf("%s\n", nome);

EXEMPLO 1
                         
			 Entrada                     Saída
                         Elizabeth F 1926            Elizabeth
                         6 			     Charles
                         1 Charles M 1948 Elizabeth  William
                         1 Andrew M 1960 Elizabeth   George
                         1 William M 1982 Charles    Charlotte
                         1 Harry M 1984 Charles      Harry
                         1 George M 2013 William     Andrew
                         1 Charlotte F 2015 William

EXEMPLO 2

                         Entrada                     Saída
                         Elizabeth F 1926 	     Elizabeth
                         6 			     Charles
                         1 Charles M 1948 Elizabeth  William
                         1 Andrew M 1960 Elizabeth   George
                         1 William M 1982 Charles    Charlotte
                         1 Harry M 1984 Charles      Harry
                         1 Charlotte F 2010 William  Andrew
                         1 George M 2013 William

EXEMPLO 3
                         
			 Entrada                     Saída
                         Elizabeth F 1926            Elizabeth
                         6 			     Charles
                         1 Charles M 1948 Elizabeth  William
                         1 Andrew M 1960 Elizabeth   Charlotte
                         1 William M 1982 Charles    George
                         1 Harry M 1984 Charles      Harry
                         1 Charlotte F 2012 William  Andrew
                         1 George M 2013 William

EXEMPLO 4

                         Entrada                     Saída
                         Elizabeth F 1926 	     Elizabeth
                         7 			     Charles
                         1 Charles M 1948 Elizabeth  William
                         1 Andrew M 1960 Elizabeth   Charlotte
                         1 William M 1982 Charles    Harry
                         1 Harry M 1984 Charles      Andrew
                         1 George M 2013 William
                         1 Charlotte F 2015 William
                         2 George

EXEMPLO 5

                         Entrada                     Saída
                         Elizabeth F 1926            Elizabeth
                         7                           Charles
                         1 Charles M 1948 Elizabeth  Harry
                         1 Andrew M 1960 Elizabeth   Andrew
                         1 William M 1982 Charles
                         1 Harry M 1984 Charles
                         1 George M 2013 William
                         1 Charlotte F 2015 William
                         2 William

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
	char nome[20];
	char pai[20];
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
		if (strcmp(Aux->nome, noPai) == 0) {
			return Aux;
		} else {
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
	char nome[20];
	scanf("%s", nome);
	tipoNoAB *aux2;
	aux2 = encontraPai(Aux, nome);
	tipoNoAB *pai;
	pai = encontraPai(Aux, aux2->pai);
	if (pai == NULL)
		;
	else if (pai->esq != NULL && strcmp(pai->esq->nome, nome) == 0)
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
	if (pai == NULL);
	else if (pai->esq == NULL)
		pai->esq = novoNo;
	else if (pai->esq != NULL &&
		 (pai->esq->sexo == 'F' && pai->esq->nascimento < 2011 &&
		  novoNo->sexo == 'M')) {
		pai->dir = pai->esq;
		pai->esq = novoNo;
	} else
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
