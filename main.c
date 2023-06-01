#include "./lista_de_adjacencia/lista_de_adjacencia.h"
#include "./dfs/dfs.h"
#include "./bfs/bfs.h"



void main() {
    Grafo* grafo = criaGrafo(9);

    adicionaAresta(grafo, 0, 1);
    adicionaAresta(grafo, 0, 2);

    adicionaAresta(grafo, 1, 0);
    adicionaAresta(grafo, 1, 3);
    adicionaAresta(grafo, 1, 4);
    adicionaAresta(grafo, 1, 5);

    adicionaAresta(grafo, 2, 0);
    adicionaAresta(grafo, 2, 6);

    adicionaAresta(grafo, 3, 1);
    adicionaAresta(grafo, 4, 1);

    adicionaAresta(grafo, 5, 1);
    adicionaAresta(grafo, 5, 7);

    adicionaAresta(grafo, 6, 2);
    adicionaAresta(grafo, 6, 8);

    adicionaAresta(grafo, 7, 5);

    adicionaAresta(grafo, 8, 6);

    printaGrafo(grafo);

    dfs(grafo); 
}