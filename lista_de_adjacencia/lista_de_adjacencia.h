#include <stdio.h>
#include <stdlib.h>

/********************************************** ESTRUTURAS *********************************************************/

typedef struct _grafo{
    int qtd_nos; 
    struct _no **adj;
} Grafo;

typedef struct _no{
    int valor; 
    struct _no *prox;
} No;

/********************************************** FUNÇÕES *********************************************************/

Grafo* criaGrafo(int qtd_nos);
No* criaNo(int valor);

void adicionaNo(Grafo* grafo);
void adicionaAresta(Grafo* grafo, int x, int y);

void removeNo(Grafo* grafo, int x, int y);
void removeAresta(Grafo* grafo, int x, int y);

void printaGrafo(Grafo* grafo);