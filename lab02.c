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