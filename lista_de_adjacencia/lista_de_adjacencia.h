#include <stdio.h>
#include <stdlib.h>

#define NAO_PONDERADA_E_NAO_DIRECIONADA 0
#define PONDERADA_E_NAO_DIRECIONADA 1
#define NAO_PONDERADA_E_DIRECIONADA 2
#define DIRECIONADA_E_PONDERADA 3

/********************************************** ESTRUTURAS *********************************************************/

typedef struct grafo{
    int qtd_nos; 
    struct no **adj;
} Grafo;

typedef struct no{
    int valor; 
    struct no *prox;
} No;

/********************************************** FUNÇÕES *********************************************************/

Grafo* criaGrafo(int qtd_nos);
No* criaNo(int valor);

void adicionaNo(Grafo* grafo);
void adicionaAresta(Grafo* grafo, int x, int y);

void removeNo(Grafo* grafo, int x, int y);
void removeAresta(Grafo* grafo, int x, int y);

void printaGrafo(Grafo* grafo);