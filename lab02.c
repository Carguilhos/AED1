/*                       Ida á piscina

1 DEFINIÇÃO DO PROBLEMA

Quem não gosta de ir á piscina? Principalmente quando se é um atleta da natação.
Em São José dos Campos, uma piscina pública foi inaugurada em 2012 para atletas
da cidade usarem durante a semana em seus treinos e no fim de semana ela é aberta
a população. Nesse sentido, é preciso de um sistema que gerencie as idas dos atletas
á psicina durante a semana.

TAREFA A

Desenvolva um algoritmo em linguagem C - utilizando lista estática encadeada - que
forneça uma lista com os números de carteira dos atletas que realizaram a reserva
da piscina naquele dia. Além disso, seu algoritmo também deve fornecer quantos
usuários de cada ano realizaram a reserva da piscina.
Para determinar o ano de inscrição de cada atleta, considere que o número da carteira
muda com o ano em que foi solicitada a inscrição . Por exemplo, todos os atletas que
entraram em 2013 possuem uma carteira de 5 dígitos que inicia com 2. Os atletas que
entraram em 2014, possuem uma carteira de 5 dígitos que inicia com 3. Os atletas
que entraram em 2015 possuem uma carteira de 5 dígitos que inicia com 4, assim por
diante.

ENTRADA

A entrada contém um único conjunto de teste, que deve ser lido do dispositivo de
entrada padrão (normalmente o teclado). O conjunto de teste é composto por P + 1
linhas, 1  P  100.

1. A primeira linha contém um valor inteiro P, 1  P  100, que representa a
quantidade de movimentações (reservas e utilizações) que serão realizadas.

2. Em cada uma das P linhas seguintes são dadas as informações. Cada linha
contém um valor inteiro - ’1’ para reservar ou ’2’ para utilizar seguida de um
espaço e o número da carteira (N), 10000  N  90000.

Para as operações de entrada, considere a sintaxe:

scanf("%d",&variavel);
scanf("%d %d",&variavel1, &variavel2);

SAÍDA

Como saída padrão, seu programa deve imprimir uma lista com os números da carteira
dos atletas que estão na lista de reserva. Quando um atleta entra na lista de reserva
(1) seu número da carteira deve ser inserido na lista e quando um atleta utiliza a piscina,
sai da lista de reserva (S) seu número da carteira. A lista deve estar ordenada
com base nos números das carteiras. Quando ocorrer uma entrada (1) ou uma saída
(2) a lista deve ser impressa. Além disso, as seguintes mensagens também devem
aparecer:

1. Tentativa de reserva se a lista estiver cheia: "Dia cheio".

2. Tentativa de utilização de um número da carteira que não está na lista: "Não foi
reservado".

Ao final da execução, você deverá imprimir quantos atletas de cada ano realizaram a
reserva a piscina naquele dia. Para as operações de saída, considere a sintaxe:

printf("Instrucao de saidann");
printf("%d ", itemLista);
printf("%d: %d", ano, quantidade);

                         Entrada Saída
                         14      65436
                         1 65436 65436 76396
                         1 76396 65398 65436 76396
                         1 65398 18679 65398 65436 76396
                         1 18679 18679 27657 65398 65436 76396
                         1 27657 18679 27657 56478 65398 65436 76396
                         1 56478 18679 27657 56478 65398 65436 76396 87635
                         1 87635 18679 27657 56478 65398 65436 65478 76396 87635
                         1 65478 18679 27657 56478 65398 65436 65478 76389 76396 87635
                         1 76389 18679 27657 56478 65398 65436 65478 76389 76396 87349 87635
                         1 87349 Dia cheio
                         1 59674 18679 27657 56478 65398 65436 65478 76389 76396 87349 87635
                         2 27657 18679 56478 65398 65436 65478 76389 76396 87349 87635
                         2 76396 18679 56478 65398 65436 65478 76389 87349 87635
                         2 65439 Não foi reservado
                                 18679 56478 65398 65436 65478 76389 87349 87635
                                 2012: 1
                                 2013: 1
                                 2014: 0
                                 2015: 0
                                 2016: 1
                                 2017: 3
                                 2018: 2
                                 2019: 2

                         Entrada Saída
                         3       Não foi reservado
                         2 12956
                         1 87698 87698
                         2 87698
                                 2012: 0
                                 2013: 0
                                 2014: 0
                                 2015: 0
                                 2016: 0
                                 2017: 0
                                 2018: 0
                                 2019: 1
                                 
OBSERVAÇÕES

 O enunciado da definição do problema é fictício e foi criado para o propósito
desse exercício.

 É fundamental que o programa imprima apenas o valor de saída.

 Os exercícios devem ser postados no site http://judge.sjc.unifesp.br.

 Cada aluno deverá postar apenas um exercício dentro da data limite.

 A resolução submetida deve utilizar a estrutura de dados definida no enunciado
do exercício.

 Os plágios serão penalizados. Como não será possível saber quem copiou,
todos os casos envolvidos receberão punições iguais, portanto, não divulgue
seu código.*/

// #########################################################################

/* Programa: Laboratório #2 - lab2.c
 
   Autor: Carlos Guilherme Moraes
   
   Versao: 1.0 - 17/07/2019
*/

// ##################### Bibliotecas Externas ##############################
 
#include<stdio.h>
#define N 10
 
 // ########################## TAD X.h ######################################
 
struct info {
  int valor;
  int prox;
};
typedef struct info tipoInfo;
 
struct listaEE {
  int tamanhoLista;
  int primeiro;
  int ultimo;
  int posLivre[N];
  tipoInfo elemento[N];
};
typedef struct listaEE
  tipoListaEE;
 
void inicializaLista (tipoListaEE *listaAux)
{
  int i;
  listaAux->tamanhoLista =0;
  listaAux->primeiro=-1;
  listaAux->ultimo=-1;
  for (i=0; i<N; i++) {
    listaAux->elemento[i].valor=0;
    listaAux->elemento[i].prox=-1;
    listaAux-> posLivre[i]=1;
  }
}
 
void insereElementoFinal (tipoListaEE *listaAux, int posicao, int carteira, int *ano)
{
  int i;
  if (posicao!=-1) {
    listaAux->elemento[posicao].valor = carteira;
    if (listaAux->tamanhoLista==0) {
      listaAux->primeiro=posicao;
      listaAux->ultimo=posicao;
      listaAux->elemento[posicao].prox=-1;
    } else if(carteira < listaAux->elemento[listaAux->primeiro].valor) {
      listaAux->elemento[posicao].prox = listaAux->primeiro;
      listaAux->primeiro=posicao;
    } else if (carteira > listaAux->elemento[listaAux->ultimo].valor) {
      listaAux->elemento[listaAux->ultimo].prox = posicao;
      listaAux->ultimo=posicao;
      listaAux->elemento[posicao].prox=-1;
    } else {
      for(i=0; i<N; i++) {
        if(carteira > listaAux->elemento[i].valor && carteira < listaAux->elemento[listaAux->elemento[i].prox].valor) {
          listaAux->elemento[posicao].prox = listaAux->elemento[i].prox;
          listaAux->elemento[i].prox = posicao;
        }
      }
    }
  }
  listaAux->tamanhoLista++;
  listaAux->posLivre[posicao]=0;
  if(carteira > 9999 && carteira < 20000)
    (*ano)++;
  else if (carteira > 19999 && carteira < 30000)
    (*(ano+1))++;
  else if(carteira > 29999 && carteira < 40000)
    (*(ano+2))++;
  else if (carteira > 39999 && carteira < 50000)
    (*(ano+3))++;
  else if(carteira > 49999 && carteira < 60000)
    (*(ano+4))++;
  else if (carteira > 59999 && carteira < 70000)
    (*(ano+5))++;
  else if(carteira > 69999 && carteira < 80000)
    (*(ano+6))++;
  else if (carteira > 79999 && carteira < 90000)
    (*(ano+7))++;
}
 
int proxPosLivre(tipoListaEE *listaAux)
{
  int i;
  for (i=0; i<N; i++) {
    if (listaAux->posLivre[i]==1)
      return i;
  }
  printf ("Dia cheio\n");
  return -1;
}
 
// ###################### Funcoes e Procedimentos do programa ##############
 
int removeElemento (tipoListaEE *listaAux, int carteira)
{
  int i,j;
  for(i=0; i<N; i++) {
    if (listaAux->elemento[i].valor == carteira && i == listaAux->primeiro && i != listaAux->ultimo) {
      listaAux->primeiro = listaAux->elemento[listaAux->primeiro].prox;
      listaAux->posLivre[i]=1;
      return i;
    } else if (listaAux->elemento[i].valor == carteira && i == listaAux->ultimo && i != listaAux->primeiro) {
      for(j=0; j<N; j++) {
        if(listaAux->elemento[j].prox == listaAux->ultimo) {
          listaAux->ultimo = j;
          listaAux->elemento[j].prox = -1;
          listaAux->posLivre[i]=1;
          return i;
        }
      }
    } else if (listaAux->elemento[i].valor == carteira && i == listaAux->primeiro && i == listaAux->ultimo) {
      listaAux->posLivre[i]=1;
      printf("\n");
      return -1;
    } else if (listaAux->elemento[i].valor == carteira) {
      for(j=0; j<N; j++) {
        if(listaAux->elemento[j].prox == i) {
          listaAux->elemento[j].prox = listaAux->elemento[i].prox;
          listaAux->posLivre[i]=1;
          return i;
        }
      }
    }
  }
  printf("Não foi reservado\n");
  if (listaAux->primeiro == -1){
    printf("\n");
    return -1;
  } else
    return 0;
}
 
void imprimirElemento (tipoListaEE *listaAux)
{
  int i, j;
  i = listaAux->primeiro;
  for (j=0; j<N; j++) {
    if (listaAux->elemento[i].prox == -1) {
      printf("%d ", listaAux->elemento[i].valor);
      break;
    }
    printf("%d ", listaAux->elemento[i].valor);
    i = listaAux->elemento[i].prox;
  }
  printf("\n");
}
 
void imprimirAno (tipoListaEE *listaAux, int *ano)
{
  int i;
  for (i=0; i<8; i++){
      printf("%d: %d\n", 2012+i, *(ano+i));
  }
}
 
// ############################ Principal ###################################
 
int main()
{
  int i, movimentacoes, acao, carteira, posicao, ano[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  tipoListaEE listaPrincipal;
  inicializaLista(&listaPrincipal);
  scanf("%d", &movimentacoes);
  for (i = 0; i < movimentacoes; i++) {
    scanf("%d%d", &acao, &carteira);
    if(acao == 1) {
      posicao = proxPosLivre(&listaPrincipal);
      if (posicao != -1) {
        insereElementoFinal(&listaPrincipal, posicao, carteira, &ano[0]);
        imprimirElemento (&listaPrincipal);
      } else
        imprimirElemento (&listaPrincipal);
    } else {
      posicao = removeElemento (&listaPrincipal, carteira);
      if (posicao != -1) {
        imprimirElemento (&listaPrincipal);
      }
    }
  }
  imprimirAno(&listaPrincipal, &ano[0]);
  return 0;
}
