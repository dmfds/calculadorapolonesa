#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef struct st_dados
{
    int numero;
    struct st_dados *prox;
}dados;

int main(void)
{
    do{

    }while()
    return EXIT_SUCCESS;
}

void inserir(lista **cabeca, int n1)
{
    lista *pl=*cabeca;
    lista *plant=NULL;
    while(pl!=NULL)
    {
        plant=pl;
        pl=pl->prox;
    }
    pl=malloc(sizeof(lista));
    pl->c=n1;
    pl->prox=NULL;
    if(plant!=NULL)
        plant->prox=pl;
    else
        *cabeca=pl;
}

