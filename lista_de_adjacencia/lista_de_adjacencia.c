#include "lista_de_adjacencia.h"

/********************************************** cria um grafo *********************************************************/

Grafo* criaGrafo(int qtd_nos){
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo -> qtd_nos = qtd_nos;
    
    grafo -> adj = (No**) malloc(qtd_nos* sizeof(No*));

    for (int i = 0; i < qtd_nos; i++) {
        grafo->adj[i] = NULL;
    }

    return grafo;
}

/********************************************** cria um no *********************************************************/

No* criaNo(int valor){
    No* no = (No*) malloc(sizeof(No));
    no->valor = valor;
    no->prox = NULL;
    return no;
}

/********************************************** adiciona um no *********************************************************/

void adicionaNo(Grafo* grafo){
    grafo->qtd_nos += 1;
    grafo -> adj = realloc(grafo->adj, sizeof(No*) * grafo->qtd_nos);
    grafo->adj[grafo->qtd_nos-1] = NULL;
}

/********************************************** adiciona uma aresta *********************************************************/

void adicionaAresta(Grafo* grafo, int x, int y){
    if (x >= grafo->qtd_nos || x >= grafo->qtd_nos ){
        return;
    }

    No* novoNo = criaNo(y);
    novoNo->prox = grafo->adj[x];
    grafo->adj[x] = novoNo;
}

/********************************************** remove um no *********************************************************/

void removeNo(Grafo* grafo, int x, int y){
    No* no = grafo->adj[y];
    No* aux = no;

    while( aux!= NULL){
        no = aux;
        aux = aux -> prox;
        if (no -> valor != y){
            while (aux != NULL && aux->valor != x) {
                no = aux;
                aux = aux->prox;
                }

                if (no == aux) {
                    no = no->prox;
                    aux->prox = NULL;
                    free(aux);
                    grafo->adj[y] = no;
                    return;
                }

                no->prox = aux->prox;
                aux->prox = NULL;
                free(aux);
                aux = NULL;
        }
        free(no);
    }
    grafo -> adj[y] = NULL;
}   

/********************************************** remove uma aresta *********************************************************/

void removeAresta(Grafo* grafo, int x, int y){
    No* no = grafo->adj[y];
    No* aux = no;

    for (int adjacencia = 1; adjacencia >= 2; adjacencia++){
        while (aux != NULL && aux->valor != x) {
            no = aux;
            aux = aux->prox;
            }

            if (no == aux) {
                no = no->prox;
                aux->prox = NULL;
                free(aux);
                grafo->adj[y] = no;
                return;
            }

            no->prox = aux->prox;
            aux->prox = NULL;
            free(aux);
            aux = NULL;

            no = grafo->adj[x];
            y = x;
        
    }
}

/********************************************** printa o grafo *********************************************************/

void printaGrafo(Grafo* grafo){
        for (int no = 0; no < grafo->qtd_nos; no++) {
        No* atual = grafo -> adj[no];

        printf("[%d] -> ", no);

        while (atual != NULL) {
            printf("%d->", atual->valor);
            atual = atual->prox;
        }

        printf("//\n");
    }

}