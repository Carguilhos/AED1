/*                       Locadora de jogos

1 DEFINIÇÃO DO PROBLEMA

Com a popularização da internet e de plataformas como Netflix, diversas empresas de
vídeo locadoras foram fechando suas portas. Entretanto, nesse mesmo ramo, surgiu o
aluguel de jogos de console, como Xbox ou PS4. Dessa forma você deve desenvolver
um sistema para gerenciar o estoque e locação dos jogos de uma locadora.

TAREFA A

Desenvolva um programa em linguagem C - utilizando lista dinâmica encadeada -
que forneça uma lista com os jogos cadastrados na locadora ordenados pelo preço da
locação. Ao final da execução, seu algoritmo deve informar o lucro obtido pela locação
de cada um dos jogos cadastrados.
O programa deve ser capaz de realizar as operações descritas abaixo:

 Inserir na lista (cadastrar): O programa deve permitir a inserção ordenada de
forma decrescente de jogos de acordo com o lucro informado de cada locação.

 Adição de quantidade ou devolução do jogo: O programa deve permitir a adição
de uma quantidade maior aos jogos disponíveis para locação e a mesma operação
permite a devolução de jogos que foram alugados para a lista.

 Aluguel: O programa deve permitir o aluguel de qualquer jogo cadastrado na
lista.

 Remoção: O programa deve permitir a remoção de qualquer jogo cadastrado.

 Contabilização: O programa deve contabilizar o lucro obtido pelo aluguel dos
jogos, de forma individual, por cada jogo.

ENTRADA

A entrada contém um único conjunto de teste, que deve ser lido do dispositivo de
entrada padrão (normalmente o teclado). O conjunto de teste é composto por L + 1
linhas, 1  L  100.

1. A primeira linha contém um valor inteiro L, 1  L  100, que representa a
quantidade de movimentações (cadastros, locações, adicições ou devoluções e
remoções) que serão realizadas.

2. Em cada uma das L linhas seguintes são dadas as informações. Cada linha
contém um valor inteiro J, 1  J  4, que representa a operação desejada,
seguida de um espaço e o restante das informações necessárias para cada
operação:

A opção 1 permite ao usuário inserir um jogo no cadastro. As informações que
vem em seguida são:

 Código do jogo (int)

 Quantidade de exemplares (int)

 Preço da locação (float)

A opção 2 permite aumentar a quantidade disponível para locação de um determinado
jogo, sendo esse aumento pode ocorrer porque o jogo foi devolvido
ou porque novos exemplares foram comprados para o acervo da locadora. As
informações que vem em seguida são:

 Código do jogo (int)

 Quantidade adicionada (int)
A opção 3 significa que houve uma locação do do jogo, então ele é removido da
lista. As informações que vem em seguida são:

 Código do jogo (int)
A opção 4 permite excluir um jogo do cadastro. As informações que vem em
seguida são:

 Código do jogo (int)

Para as operações de entrada, considere a sintaxe:

Opção 1:
scanf("%d %d %d %f",&variavel, &codigo, &quantidade, &preço);

Opção 2:
scanf("%d %d %d",&variavel, &codigo, &quantidade);

Opção 3:
scanf("%d %d",&variavel, &codigo);

Opção 4:
scanf("%d %d",&variavel, &codigo);

SAÍDA

Como saída padrão, seu programa deve imprimir uma lista com o valor total da locação
de cada jogo cadastrado na lista. Note que quando um jogo é removido do cadastro,
nenhuma informação sobre ele deve ser impressa no final. A saída deve estar ordenada
pelo preço individual de cada produto, e não pelo valor total de locações. Além
disso, as seguintes mensagens também devem aparecer:

1. Tentativa de cadastro de um jogo já existente na lista: "O jogo já está cadastrado".

2. Tentativa de remoção de um jogo que não existe na lista: "Não há".

3. Tentativa de locação de um jogo que não existe na lista: "Não há".

4. Tentativa de compra de um jogo com quantidade 0: "Não há".

5. Tentativa de alteração da quantidade ou devolução de um jogo que não existe
na lista: "Não há".

Ao final da execução, você deverá imprimir o lucro obtido pela locação de cada um
dos jogos.

Para as operações de saída, considere a sintaxe:

printf("%d %f nn", id, lucrototal);

Obs: Lembrando que no final a saída é ordenada pelo preço de aluguel de cada jogo
e não pelo valor total do lucro de locação que deve aparecer na saída.

                         Entrada Saída
                         7       O jogo já está cadastrado
                         1 1 1 4 3 4.000000
                         1 1 1 3 1 4.000000
                         1 2 1 3 2 3.000000
                         1 3 1 4
                         3 1
                         3 2
                         3 3


                         Entrada Saída
                         8       O jogo já está cadastrado
                         1 1 5 5 1 20.000000
                         2 1 1
                         1 1 5 5
                         3 1
                         3 1
                         3 1
                         3 1
                         2 1 1
                         
OBSERVAÇÕES

 O tamanho da lista é 100.

 É fundamental que o programa imprima apenas o valor de saída.

 Os exercícios devem ser postados no site http://judge.sjc.unifesp.br.

 Cada aluno deverá postar apenas um exercício dentro da data limite.

 A resolução submetida deve utilizar a estrutura de dados definida no enunciado
do exercício.

 Os plágios serão penalizados. Como não será possível saber quem copiou,
todos os casos envolvidos receberão punições iguais, portanto, não divulgue
seu código.*/

// #########################################################################

/* Programa: Laboratório #3 - lab3.c
 
   Autor: Carlos Guilherme Moraes
 
   Versao: 1.0 - 17/07/2019
*/
 
// ##################### Bibliotecas Externas ##############################

#include <stdio.h>
#include <stdlib.h>
#define N 100

// ########################## TAD X.h ######################################

struct elemento
{
    int codigo;
    int quantidade;
    float preco;
    float lucro;
    struct elemento *prox;
};
 
typedef struct elemento
    tipoElemento;
 
struct listaDE
{
    tipoElemento *primeiro;
    tipoElemento *ultimo;
    int tamanhoLista;
};
 
typedef struct listaDE
    tipoLDE;
 
void inicializaLista(tipoLDE *listaAux)
{
    listaAux->primeiro = NULL;
    listaAux->ultimo = NULL;
    listaAux->tamanhoLista = 0;
}
 
void insereElementoFinal(tipoLDE *listaAux, int codigo, int quantidade, int preco)
{
    int i;
    tipoElemento *novoElem = malloc(sizeof(tipoElemento));
    tipoElemento *aux = listaAux->primeiro;
    novoElem->codigo = codigo;
    novoElem->quantidade = quantidade;
    novoElem->preco = preco;
    novoElem->lucro = 0;
    if (listaAux->tamanhoLista == 0)
    {
        novoElem->prox = NULL;
        listaAux->primeiro = novoElem;
        listaAux->ultimo = novoElem;
        listaAux->tamanhoLista++;
    }
    else if (preco >= listaAux->primeiro->preco)
    {
        novoElem->prox = aux;
        listaAux->primeiro = novoElem;
        listaAux->tamanhoLista++;
        return;
    }
    else if (preco < listaAux->ultimo->preco)
    {
        listaAux->ultimo->prox = novoElem;
        listaAux->ultimo = novoElem;
        listaAux->tamanhoLista++;
        return;
    }
    else
    {
        for (i = 0; i < listaAux->tamanhoLista - 1; i++)
        {
            if (novoElem->preco >= aux->prox->preco)
            {
                novoElem->prox = aux->prox;
                aux->prox = novoElem;
                listaAux->tamanhoLista++;
                return;
            }
            aux = aux->prox;
        }
    }
}

// ###################### Funcoes e Procedimentos do programa ##############

int procurarElemento(tipoLDE *listaAux, int codigo)
{
    int i;
    tipoElemento *aux = listaAux->primeiro;
    for (i = 0; i < listaAux->tamanhoLista; i++)
    {
        if(codigo == aux->codigo)
        {
            printf("O jogo já está cadastrado\n");
            return 0;
        }
        aux = aux->prox;
    }
    return 1;
}
 
void adicionarQuantidade(tipoLDE *listaAux, int codigo, int quantidade)
{
    int i;
    tipoElemento *aux = listaAux->primeiro;
    for (i = 0; i < listaAux->tamanhoLista; i++)
    {
        if (codigo == aux->codigo)
        {
            aux->quantidade = aux->quantidade + quantidade;
            return;
        }
        aux = aux->prox;
    }
    printf("Não há\n");
}
 
void alugar(tipoLDE *listaAux, int codigo)
{
    int i, lucro;
    tipoElemento *aux = listaAux->primeiro;
    for (i = 0; i < listaAux->tamanhoLista; i++)
    {
        if (codigo == aux->codigo)
        {
            if (aux->quantidade != 0)
            {
                aux->lucro = aux->lucro+aux->preco;
                aux->quantidade--;
                return;
            }
            else
            {
                printf("Não há\n");
                return;
            }
        }
        aux = aux->prox;
    }
    printf("Não há\n");
}
 
void excluirElemento(tipoLDE *listaAux, int codigo)
{
    int i;
    tipoElemento *aux = listaAux->primeiro;
    if (codigo == aux->codigo)
    {
        listaAux->primeiro = aux->prox;
        listaAux->tamanhoLista--;
        free(aux);
        return;
    }
    else
    {
        for (i = 0; i < listaAux->tamanhoLista; i++)
        {
            if (codigo == aux->prox->codigo)
            {
                aux->prox = aux->prox->prox;
                listaAux->tamanhoLista--;
                free(aux->prox);
                return;
            }
        }
    }
    printf("Não há\n");
}
 
void imprimirElemento(tipoLDE *listaAux, int codigo)
{
    int i;
    tipoElemento *aux = listaAux->primeiro;
    for (i=0; i< listaAux->tamanhoLista; i++)
    {
        printf("%d %f \n", aux->codigo, aux->lucro);
        aux = aux->prox;
    }
}

// ############################ Principal ###################################

int main()
{
    tipoLDE listaPrincipal;
    int i, aux, movimentacoes, acao, codigo, quantidade;
    float preco;
    inicializaLista(&listaPrincipal);
    scanf("%d ", &movimentacoes);
    for (i = 0; i < movimentacoes; i++)
    {
        scanf("%d ", &acao);
        if (acao == 1)
        {
            scanf("%d %d %f", &codigo, &quantidade, &preco);
            aux = procurarElemento(&listaPrincipal, codigo);
            if (aux)
            {
                insereElementoFinal(&listaPrincipal, codigo, quantidade, preco);
            }
        }
        else if (acao == 2)
        {
            scanf("%d %d", &codigo, &quantidade);
            adicionarQuantidade(&listaPrincipal, codigo, quantidade);
        }
        else if (acao == 3)
        {
            scanf("%d", &codigo);
            alugar(&listaPrincipal, codigo);
        }
        else
        {
            scanf("%d", &codigo);
            excluirElemento(&listaPrincipal, codigo);
        }
    }
    imprimirElemento(&listaPrincipal, codigo);
    return 0;
}
