#ifndef __dfs_h
#define __dfs_h

#include <stdio.h>
#include <stdbool.h>
#include "../lista_de_adjacencia/lista_de_adjacencia.h"

static int tempo;

enum Cor {
    Preto = 'p', Cinza = 'c', Branco = 'b'
};

/********************************************** FUNÇÕES *********************************************************/
void dfs(Grafo *g);
void visitaDFS(Grafo *grafo, int u, int *d, int *f, int *pi, enum Cor *cor);


#endif