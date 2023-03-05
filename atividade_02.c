#include <stdio.h>
#include <stdlib.h>

// define o maximo e elementos nos exercicios de pilhas
#define MAX_ELEMENTOS 10
// define qual exercicio sera executado
#define ex01

// ESTRUTURA DE DADOS - ATIVIDADE 2 - PILHAS

#ifdef ex01
/* 1) Usando o conceito de pilha, carregue uma pilha com 10 elementos do tipo real
 e imprima posteriormente a saída destes elementos. */

// Estrutura de dados da pilha
typedef struct
{
    float elemento[MAX_ELEMENTOS];
    int topo;
} Pilha;

// Inicia a pilha com o topo como indice -1;
void pilha_iniciar(Pilha *p)
{
    p->topo = -1;
}

// verifica se a pilha esta vazia
int pilha_vazia(Pilha *p)
{
    if (p->topo == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// verifica se a pilha esta cheia
int pilha_cheia(Pilha *p)
{
    if (p->topo == MAX_ELEMENTOS - 1)
    { // verifica se indice do vetor é o ultimo do mesmo.
        return 1;
    }
    else
    {
        return 0;
    }
}

// Inseri um elemento na pilha

void pilha_push(Pilha *p)
{
    if (pilha_cheia(p) == 1)
    {
        printf("\nA ERRO: PILHA ESTA CHEIA.\n");
    }
    else if (p->topo == -1)
    {

        for (int i = 0; i < MAX_ELEMENTOS; i++)
        {
            p->topo++;
            printf("\n -----Digite o elemento numero %d da pilha. Ex: 10.25 -----\n", i + 1);
            scanf("%f", &(*p).elemento[p->topo]);
        }
    }
    else
    {

        p->topo++;
        printf("\n -----Digite o elemento numero %d da pilha. Ex: 10.25 -----\n", p->topo + 1);
        scanf("%f", &(*p).elemento[p->topo]);
    }
}

// remove um elemento da pilha

float pilha_pop(Pilha *p)
{

    float aux;
    if (pilha_vazia(p) == 1)
    {
        printf("\nERRO: PILHA ESTA VAZIA\n");
    }
    else
    {
        aux = p->elemento[p->topo];
        p->topo--;
        return aux;
    }
}

// Imprime os elementos da pilha a partir do topo

void imprimir_pilha(Pilha *p)
{
    if (pilha_vazia(p) != 1)
    {
        int count = 0;
        printf("\n======== PILHA ========\n");
        for (int i = p->topo; i >= 0; i--)
        {
            if (count == 0)
            {
                printf("\nTopo--> %.2f\n", p->elemento[i]);
                count++;
            }
            else
                printf("\n        %.2f\n", p->elemento[i]);
        }
        printf("\n======== FIM DA PILHA ========\n");
    }
    else
    {
        printf("\nPILHA VAZIA\n");
    }
}

int main()
{

    printf("\n =========== ESTRUTURA DE DADOS - ATIVIDADE 2 - PILHAS ============ \n");
    printf("\n Usando o conceito de pilha, carregue uma pilha com 10 elementos \n");
    printf("\n do tipo real e imprima posteriormente a saida destes elementos. \n");
    printf("\n ================================================================== \n");

    // Alocar memoria para a pilha

    Pilha *p = malloc(sizeof(Pilha));
    if (p)
    {
        pilha_iniciar(p);
    }
    else
    {
        printf("\nERRO ao alocar memoria.\n");
    }

    // MENU
    int opcao;
    float aux;

    do
    {
        printf("\n==== Digite uma opcao ====\n");
        printf("\n 1 - Empilhar\n 2 - Remover\n 3 - Imprimir Pilha\n 0 - Sair\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            system("cls");
            pilha_push(p);
            break;
        case 2:
            system("cls");
            aux = pilha_pop(p);
            if (pilha_vazia(p) != 1)
                printf("\nRemovido do topo da pilha -> %.2f\n", aux);
            break;
        case 3:
            system("cls");
            imprimir_pilha(p);

            break;
        case 0:
            system("cls");
            printf("\nFim do Programa.\n");
            exit(0);
            break;

        default:
            system("cls");
            printf("\nOpcao indefinida\n");
            break;
        }

    } while (opcao != 0);
    free(p);

    return 0;
}
#endif // ex03

//===============================================================================

#ifdef ex02

/* 2) Implemente um algoritmo usando  pilha
 que faça a conversão de um número da base decimal para a base binária. */

// Pilha Dinamica
typedef struct no
{
    int bin;
    struct no *proximo;
} Pilha;

Pilha *push(Pilha *topo, int x)
{

    Pilha *novo = malloc(sizeof(Pilha));

    if (novo)
    {
        novo->bin = x;
        novo->proximo = topo;
        return novo;
    }
    else
        printf("\nERRO ao alocar memoria.\n");
}

void imprimir_pilha(Pilha *topo)
{
    while (topo)
    {
        printf("%d ", topo->bin);
        topo = topo->proximo;
    }
}

void converte(int numerador, Pilha *topo)
{
    int resto;

    while (1)
    {

        if (numerador == 0)
            break;

        resto = numerador % 2;
        numerador = numerador / 2;
        topo = push(topo, resto);
    }

    // imprimindo a pilha
    printf("\n---- Resultado da Conversao -----\n");
    imprimir_pilha(topo);
}

int main()
{

    printf("\n ==============ESTRUTURA DE DADOS - ATIVIDADE 2 - PILHAS =====================\n");
    printf("\n Implemente um algoritmo usando  pilha \n");
    printf("\n fazendo a conversao de um numero da base decimal para a base binaria. \n\n");
    printf("\n ============================================================================ \n");

    Pilha *topo = NULL;

    int opcao, decimal_user;

    do
    {

        printf("\n\n==== Digite uma opcao ====\n");
        printf("\n 1 - Decimal para Binario\n 2 - Sair\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            system("cls");
            printf("\nDigite um numero DECIMAL:.\n");
            scanf("%d", &decimal_user);

            converte(decimal_user, topo);

            break;
        case 2:
            free(topo);
            printf("\nFIM DO PROGRAMA\n");
            exit(0);
            break;

        default:
            printf("\nOPCAO INVALIDA.\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}

#endif // ex02

//===============================================================================

