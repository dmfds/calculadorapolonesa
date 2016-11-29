#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct st_lista
{
    float numero;
    struct st_lista *prox;
}lista;

float remover(lista **cabeca);
void inserir(lista **cabeca, float c);
int tamanho(lista *cabeca);

int main(void)
{
    char peg;
 

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

