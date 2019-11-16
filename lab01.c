/*                       Gerenciamento de Empréstimo de Livros

1 DEFINIÇÃO DO PROBLEMA

A biblioteca do ICT permite que os usuários reservem livros que não estão disponíveis.
Assim, quando o livro ficar disponível, o usuário poderá retirá-lo. Portanto, torna-se
necessário a utilização de um sistema que gerencie as reservas realizadas pelos
usuários.

TAREFA A

Desenvolva um algoritmo em linguagem C - utilizando lista estática sequencial -
que reproduza as atividades executadas pelo sistema de gerenciamento de reservas
da biblioteca. Nessa tarefa, vamos assumir que o seu programa será utilizado para
gerenciar as reservas de apenas um usuário. Além disso, são permitidas no máximo
10 reservas por usuário.
O programa deverá imprimir uma mensagem sempre que uma nova reserva for solicitada
ou um livro for retirado. Se uma nova reserva for solicitada e a lista de reservas
estiver cheia, o programa deverá imprimir esta informação. Quando a reserva for
concluída, o programa deverá imprimir quantas reservas aquele usuário já realizou.
Quando um livro for retirado, a mensagem deverá incluir quantos livros aquele usuário
já retirou. Note que as inclusões de novas reservas ocorrem sempre ao final da lista.

ENTRADA

A entrada contém um único conjunto de teste, que deve ser lido do dispositivo de
entrada padrão (normalmente o teclado). O conjunto de teste é composto por L + 1
linhas, 1 <= L <= 100.

1. A primeira linha contém um valor inteiro L, 1 <= L <= 100, que representa a
quantidade de movimentações (reservas e retiradas) serão realizadas.

2. Em cada uma das L linhas seguintes são dadas as informações. Cada linha
contém um valor inteiro - ’1’ para reservar ou ’2’ para retirar seguida de um
espaço e o número do livro (N), 1 <= N <= 100.

Para as operações de entrada, considere a sintaxe:

scanf("%d",&variavel);
scanf("%d %d",&variavel1, &variavel2);

SAÍDA

Como saída padrão, seu programa deve imprimir as seguintes informações:

1. Reserva concluída com sucesso: "Sua reserva foi realizada".

2. Se a lista de reservas estiver cheia: "Lista de reserva cheia".

3. Se você tentar retirar um livro, mas não possuir reserva: "Voce nao possui reserva
desse livro".

4. Se você retirar um livro com sucesso: "O livro foi retirado com sucesso"
Ao final da execução, você deverá imprimir quantas reservas e quantas retiradas foram
feitas ao todo.

Para as operações de saída, considere a sintaxe:

printf("Instrucao de saida\n");
printf("Voce realizou %d reservas e %d retiradas\n", reservas, retidas);

                         Entrada Saída
                         8       Sua reserva foi realizada
                         1 2     Sua reserva foi realizada
                         1 4     Voce nao possui reserva desse livro
                         2 3     Sua reserva foi realizada
                         1 6     Sua reserva foi realizada
                         1 9     Sua reserva foi realizada
                         1 1     O livro foi retirado com sucesso
                         2 9     O livro foi retirado com sucesso
                         2 2     Voce realizou 5 reservas e 2 retiradas

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
