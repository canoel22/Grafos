#include "lista_de_adjacencia.h"

/********************************************** aloca um nó *********************************************************/

void aloca(int nos, No** lista_adjacente){
    for (int i=1; i<=nos; i++){
        lista_adjacente[i] = (No*) malloc(sizeof (No));
        lista_adjacente[i]->valor = i;
        lista_adjacente[i]->prox = NULL;
    }
}

void insere_lista(){

}

void printa(){

}

int main(){
    int nos, arestas, tipo;

    scanf("%d %d %d", &nos, &arestas, &tipo);
    No *lista_adjacente[nos];

    aloca(nos, lista_adjacente);
    insere();
    printa(lista_adjacente);
} 