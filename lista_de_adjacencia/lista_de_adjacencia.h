#ifndef _lista_de_adjacencia_h
#define _lista_de_adjacencia_h

#include <stdio.h>
#include <stdlib.h>

/********************************************** ESTRUTURAS *********************************************************/

typedef struct _no{
    int valor; 
    struct _no *prox;
} No;

typedef struct grafo{
    int qtd_nos; 
    No **adj;
} Grafo;

/********************************************** FUNÇÕES *********************************************************/

Grafo* criaGrafo(int qtd_nos);
No* criaNo(int valor);

void adicionaNo(Grafo* grafo);
void adicionaAresta(Grafo* grafo, int x, int y);

void removeNo(Grafo* grafo, int x, int y);
void removeAresta(Grafo* grafo, int x, int y);

void printaGrafo(Grafo* grafo);

#endif