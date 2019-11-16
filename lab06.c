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