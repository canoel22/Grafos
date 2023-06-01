//algoritimo de busca em profundidade

#include "dfs.h"

/********************************************** FUNÇÕES *********************************************************/

void visitaDFS(Grafo *grafo, int u, int *d, int *f, int *pi, enum Cor *cor){
    tempo += 1;
    d[u] = tempo;
    cor[u] = Cinza;

    for (No *no = grafo->adj[u]; no != NULL; no = no->prox) {
        int v = no->valor;

        if (cor[v] == Branco) {
            pi[v] = u;
            dfs_visit(grafo, v, d, f, pi, cor);
        }
    }

    tempo += 1;
    f[u] = tempo;
    cor[u] = Preto;
}

void dfs(Grafo* grafo) {
    int d[grafo->qtd_nos];
    int f[grafo->qtd_nos];
    int pi[grafo->qtd_nos];
    enum Cor cor[grafo->qtd_nos];

    for (int i = 0; i < grafo->qtd_nos; i++) { //define inicialmente a cor dos nós como branca
        cor[i] = Branco;
        pi[i] = -1;
    }

    tempo = 0;

    for (int u = 0; u < grafo->qtd_nos; u++) { //visita os nós
        if (cor[u] == Branco)
            dfs_visit(grafo, u, d, f, pi, cor);
    }


    for (int i = 0; i < grafo->qtd_nos; i++) { //printa
        printf("d[%d] = %d\n", i, d[i]);
    }

    for (int i = 0; i < grafo->qtd_nos; i++) {
        printf("f[%d] = %d\n", i, f[i]);
    }
}
