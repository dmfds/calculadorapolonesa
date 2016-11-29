#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct st_lista
{
    float numero;
    struct st_lista *prox;
}lista;

float remover(lista **cabeca);
void inserir(lista **cabeca, int num1);
int tamanho(lista *cabeca);

int main(void)
{
    float num1, num2;
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
                printf("%d\n",num2-num1);
                inserir(&cabeca,num2-num1);
                break;

            case '/':
                num1=remover(&cabeca);
                num2=remover(&cabeca);
                if(num1==0)
                    printf("Divisao por zero\n");
                printf("%d\n",num2/num1);
                inserir(&cabeca,num2/num1);
                break;

            case '*':
                num1=remover(&cabeca);
                num2=remover(&cabeca);
                printf("%d\n",num1*num2);
                inserir(&cabeca,num1*num2);
                break;

            default:
                inserir(&cabeca,num1);
        }
    }while(*y!='y');

    return EXIT_SUCCESS;
}

void inserir(lista **cabeca, int num1)
{
    lista *pl=*cabeca;
    lista *plant=NULL;
    while(pl!=NULL)
    {
        plant=pl;
        pl=pl->prox;
    }
    pl=malloc(sizeof(lista));
    pl->numero=num1;
    pl->prox=NULL;
    if(plant!=NULL)
        plant->prox=pl;
    else
        *cabeca=pl;
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

