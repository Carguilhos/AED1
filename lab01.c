/* Programa: Laboratório #1 - lab1.c
 
   Autor: Carlos Guilherme Moraes
 
   Versao: 1.0 - 06/09/2019
*/
 
// ##################### Bibliotecas Externas ##############################
 
#include<stdio.h>
 
// ########################## TAD X.h ######################################
 
struct listaES
{
    int ultimo;
    int tamanhoLista;
    int lista[10];
};
typedef struct listaES tipoListaES;
 
void inicializaLista (tipoListaES *listaAux)
{
    int i;
    listaAux->tamanhoLista=0;
    for (i=0; i<10; i++)
        listaAux->lista[i]=0;
    listaAux->ultimo=0;
}
void insereElemento (tipoListaES *listaAux, int b)
{
    listaAux->tamanhoLista++;
    listaAux->lista[listaAux->tamanhoLista-1] = b;
    listaAux->ultimo = listaAux->tamanhoLista-1;
}
 
// ###################### Funcoes e Procedimentos do programa ##############
 
void removeElemento (tipoListaES *listaAux, int b, int *retidas)
{
    int i;
    for (i=0; i<listaAux->tamanhoLista; i++)
    {
        if (listaAux->lista[i] == b)
        {
            listaAux->tamanhoLista--;
            if (listaAux->lista[i]!=listaAux->lista[listaAux->ultimo])
            {
                for (; i<listaAux->tamanhoLista; i++)
                {
                    listaAux->lista[i] = listaAux->lista[i+1];
                }
            }
            listaAux->ultimo--;
            printf("O livro foi retirado com sucesso\n");
            (*retidas)++;
            return ;
        }
    }
    printf("Voce nao possui reserva desse livro\n");
}
 
// ############################ Principal ###################################
 
int main ()
{
    int movimentacoes, i, a, b, reservas=0, retidas=0;
    tipoListaES listaPrincipal;
    inicializaLista(&listaPrincipal);
    scanf("%d", &movimentacoes);
    for(i=0; i<movimentacoes; i++)
    {
        scanf("%d %d", &a, &b);
        if (a==1)
        {
            if (listaPrincipal.tamanhoLista == 10)
                printf("Lista de reserva cheia\n");
            else
            {
                insereElemento(&listaPrincipal, b);
                printf("Sua reserva foi realizada\n");
                reservas++;
            }
        }
        else
            removeElemento(&listaPrincipal, b, &retidas);
    }
    printf("Voce realizou %d reservas e %d retiradas\n", reservas, retidas);
    return 0;
 
}