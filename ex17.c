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

