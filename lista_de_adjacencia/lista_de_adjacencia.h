#include <stdio.h>
#include <stdlib.h>

#define NAO_PONDERADA_E_NAO_DIRECIONADA 0
#define PONDERADA_E_NAO_DIRECIONADA 1
#define NAO_PONDERADA_E_DIRECIONADA 2
#define DIRECIONADA_E_PONDERADA 3

/********************************************** ESTRUTURAS *********************************************************/

typedef struct grafo{
    int qtd; 
    struct no *raiz;
} Grafo;

typedef struct no{
    int valor; 
    struct no *prox;
} No;