#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct st_lista
{
    float numero;
    struct st_lista *prox;
}lista;

float remover(lista **cabeca);/*retira o primeiro item na lista e retorna seu valor*/
void inserir(lista **cabeca, float c);/*acrescenta o item no comeco da lsta*/
int tamanho(lista *cabeca);/*retorna quantidade de itens na lista*/
void exibir(lista *cabeca);/*mostra os itens na lista*/

int main(void)
{
    char peg;
    /*loop no programa*/
    /*saira quando o usuario colocar Y*/
    do
    {
        /*calculo();*/
        printf("Deseja Continuar?\n");
        printf("y-sim\n");
        printf("n-não\n");
        do
        {
            scanf("%c", &peg);
        }while(peg=='\n' || (peg!='y' && peg!='n'));
    }while(peg=='y');

    return EXIT_SUCCESS;
}

void calculo(void)
{
    int qnd;
    char vetor[MAX], *P;
    float n1, n2, n3;
    lista *cabca=NULL;

    printf("\nBem-vindo a Calculadora Polonesa \n");
    printf("Realizar as seguintes operacoes:\n");
    printf("Soma + \n");
    printf("Subtracao - \n");
    printf("Multiplicacao *");
    printf("Divisao / \n")

    do
    {

    }while
}

void inserir(lista **cabeca, float c)
{
    lista *pp=*cabeca;
    pp=malloc(sizeof(lista));
    pp->numero=c;
    pp->prox=NULL;
    if(cabeca == NULL)
    {
        pp->prox=NULL;
        *cabeca=pp;
    }
    else
    {        
        pp->prox=*cabeca;
        *cabeca=pp;
    }
    return;
}


float remover(lista **cabeca)
{

    float valor=0;
    lista *primeiro=*cabeca;

    *cabeca=primeiro->prox;
    valor=primeiro->numero;
    free(primeiro);
    return valor;
}

int tamanho(lista *cabeca)
{
    lista *pp=cabeca;
    int cont=0;
    while(pp!=NULL)
    {
        cont++;
        pp=pp->prox;
    }
    return cont;
}

void exibir(lista *cabeca)
{
    lista *cd=cabeca;

    printf("\nResultado da operacao: ");
    while(cd!=NULL)
    {
        printf("%.2f\n", cd->numero);
        cd=cd->prox;
    }

    return;
}

