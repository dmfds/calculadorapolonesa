#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef struct st_lista
{
    int numero;
    struct st_lista *prox;
}lista;

int  remover(lista **cabeca, lista *r);
void inserir(lista **cabeca, int n1);

int main(void)
{
    int num1, num2;
    char y[MAX];

    printf("Calculadora polonesa\n");
    printf("Se desejar sair da calculadora digite 'y'\n");

    do{
        printf(": ");
        fgets(y,MAX,stdin);
        switch(*y)
        {
            case '+':
                num1=remover(&cabeca);
                num2=remover(&cabeca);
                printf("%d\n",num1+num2);
                inserir(&cabeca,num1+num2);
                break;
            
            case '-':
                num1=remover(&cabeca);
                num2=remover(&cabeca);
                printf("%d\n",num1-num2);
                inserir(&cabeca,num1-num2);
                break;

        }
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
    pl->numero=n1;
    pl->prox=NULL;
    if(plant!=NULL)
        plant->prox=pl;
    else
        *cabeca=pl;
}


int  remover(lista **cabeca, lista *r)
{
    lista *pl=*cabeca;
    lista *plant=NULL;
    if(r==NULL)
        return;
    while(pl!=NULL && pl!=r)
    {
        plant=pl;
        pl=pl->prox;
    }
    if(pl==NULL)
        return;
    if(plant!=NULL)
        plant->prox=pl->prox;
    else
        *cabeca=pl->prox;
    free(pl);
    return;
}

