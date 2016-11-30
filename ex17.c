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
    printf("Divisao / \n");

    printf("Para realizar as operacoes digite primeiro os numeros e depois  os operadores e por ultimo = \n");
    printf("EX\n");
    printf("2 <enter> 2 <enter> +<enter> =<enter>\n");
    printf("Será 2+2=4\n");
    printf("Vamos comecar!!!\n");
   
    do
    {
        fgets(vetor, MAX, stdin);
        if((p=strchr(vetor, '\n'))) *p='\0';
         
        /*comando opercao SOMA*/
        if((!strcmp(vetor, "+")))
        {
            qnd=tamanho(cabeca);
            if(qnd==1)
            {
                printf("Nao possivel realizar a operacao\n");
                return;
            }
            else
            {
                n1=remover(&cabeca);
                n2=remover(&cabeca);
                n3=n1+n2;
                inserir(&cabeca, n3);
            }
        }

        /*comando opercao SUBTRACAO*/
        else if((!strcmp(vetor, "-")))
        {
            qnd=tamanho(cabeca); /*se qnd de itens=1, resultado sera seu valor negativo*/
            if(qnd==1)
            {
                n1=remover(&cabeca);
                n1*=-1;
                inserir(&cabeca, n1);
            } /*qnd de elementos!=1*/
            else
            {
                n1=remover(&cabeca);
                n2=remover(&cabeca);
                n3=n2-n1;
                inserir(&cabeca,n3);
            }
        }

        /*comando operacao MULTIPLICAO*/
        else if((!strcmp(vetor, "*")))
        {
            qnd=tamanho(cabeca);
            if(qnd==1)
            {
                printf("Nao foi possivel realizar a operacao\n");
                return;
            }
            else
            {
                n1=remover(&cabeca);
                n2=remover(&cabeca);
                n3=n1*n2;
                inserir(&cabeca,n3);
            }
        }

        /*comando operacao DIVISAO*/
        else if((!strcmp(vetor, "/")))
        {
            qnd=tamanho(cabeca);
            if(qnd==1)
            {
                printf("Nao foi possivel realizar a operacao\n");
                return;
            }
            else
            {
                n1=remover(&cabeca);
                n2=remover(&cabeca);
                n3=n2/n1;
                inserir(&cabeca,n3);
            }
        }
        
        else if((!strcmp(vetor, "=")))
        {
            if(cabeca!=NULL)
            {
                exibir(cabeca);
                return;
            }
            else
                return;
        }

        /*Se string apresentar numeros, insere na lista*/
        else
            inserir(&cabeca, atof(vetor));

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

