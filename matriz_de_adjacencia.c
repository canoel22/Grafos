#include <stdio.h>
#include <stdlib.h>

#define NAO_PONDERADA_E_NAO_DIRECIONADA 0
#define PONDERADA_E_NAO_DIRECIONADA 1
#define NAO_PONDERADA_E_DIRECIONADA 2
#define DIRECIONADA_E_PONDERADA 3

/********************************************** FUNÇÕES *********************************************************/

void cria_matriz(int nos, int matriz[nos][nos]){
    for (int i=0; i<nos; i++){
        for (int j=0; j<nos; j++){
            matriz[i][j]=0;
        }
    }
}

void insere_matriz(int tipo, int nos, int arestas, int matriz[nos][nos], int matriz_ponderada[nos][nos]){
    int i, j, peso;

    for (int x=1; x<=arestas; x++){
        scanf("%d %d", &i, &j);
        //printf ("%d", arestas);

        if (tipo == NAO_PONDERADA_E_NAO_DIRECIONADA){
            matriz[i-1][j-1] += 1;
            matriz[j-1][i-1] += 1;

        }else if (tipo == PONDERADA_E_NAO_DIRECIONADA){
            matriz[i-1][j-1] += 1;
            matriz[j-1][i-1] += 1;

            scanf("%d", &peso);
            matriz_ponderada[i-1][j-1] += 1;
            matriz_ponderada[j-1][i-1] += 1;

        }else if (tipo == NAO_PONDERADA_E_DIRECIONADA){
            matriz[i-1][j-1] += 1;

        }else if (tipo == DIRECIONADA_E_PONDERADA){
            matriz[i-1][j-1] += 1;

            scanf("%d", &peso);
            matriz_ponderada[i-1][j-1] += 1;
            
        }
    }
}

int grau_especifico(int nos, int matriz[nos][nos], int i){
    int especifico=0;
    for (int j=0; j<nos; j++){
            especifico += matriz[i][j];
        }
    return especifico;
}

void regular(int nos, int matriz[nos][nos]){ //ajeitar pra comparar com os restantes
    int flag=0;
    for (int i=1; i<nos; i++){
        if (grau_especifico(nos, matriz, i-1) != grau_especifico(nos, matriz, i)){
            flag=1;        
        }
    }
    if (flag==1) {
        printf("\n* O grafo é irregular");
    }else{
        printf("\n* O grafo é regular");
    }
}

void completo(int nos, int matriz[nos][nos]){ //testar a adjacencia com os outros nós
    int x, completa = 1;
    for(int i = 0; i < nos; i++){
        x = grau_especifico(nos, matriz, i);
        if(x < nos){
            completa = 0;
            break;
        }
    }
    
    if(completa != 0)
        printf("\n* O grafo é completo");
    else
        printf("\n* O grafo incompleto");
}


void grau_no(int nos, int matriz[nos][nos]){
    int grau=0;

    printf ("\nGraus dos nós:\n");
    for (int i=0; i<nos; i++){
        grau = grau_especifico(nos, matriz, i);
        printf("g(%d) = %d\n", i+1, grau);
    }
    
}

void grau_max(int nos, int matriz[nos][nos]){
    int max = grau_especifico(nos, matriz, 0);

    for (int i=1; i<nos; i++){
        int grau = grau_especifico(nos, matriz, i);
        if (grau > max){
            max = grau;
        }
    }

    printf("\n\n* Grau máximo: %d", max);
}

void grau_min(int nos, int matriz[nos][nos]){
    int min = grau_especifico(nos, matriz, 0);

    for (int i=1; i<nos; i++){
        int grau = grau_especifico(nos, matriz, i);
        if (grau < min){
            min = grau;
        }
    }

    printf("\n* Grau mínimo: %d\n", min);

}

void printa_matriz(int nos, int matriz[nos][nos]){
    for (int i=0; i<nos; i++){
        for (int j=0; j<nos; j++){
            printf ("%d", matriz[i][j]);
        }
        printf("\n");
    }
}

void loop(int nos, int matriz[nos][nos] ){
    int qtd_loops=0;
    printf("\n");

    for (int i=0; i<nos; i++){
        if(matriz[i][i]!=0){
            printf("\n* O vértice %d tem um loop", i+1);
            qtd_loops++;
        }
    }
    printf("\n* Quantidade de loops: %d\n\n", qtd_loops);
}

void vertice_isolado(int nos, int matriz[nos][nos]){
    int qtd_isolados=0;

    for (int i=0; i<nos; i++){
        int soma=0;
        for (int j=0; j<nos; j++){
            soma += matriz[i][j];
        }
        if (soma == 0){
            printf("\n* O vértice %d é isolado", i+1);
            qtd_isolados++;
        }
    }
    printf("\n* Quantidade de vértices isolados: %d\n", qtd_isolados);
}

void aresta_paralela(int nos, int matriz[nos][nos]){
    int qtd_paralelas=0;

    for (int i=0; i<nos; i++) {
        for (int j=0; j<nos; j++) {
            if (matriz[i][j] > 1 && i!=j) {
                printf("\n* O vértice %d tem aresta paralela", i+1);
                qtd_paralelas++;
            }
        }
    }
    printf("\n* Quantidade de arestas paralelas: %d", qtd_paralelas/2);
}


int main(){
    int nos, arestas, tipo;

    scanf("%d %d %d", &nos, &arestas, &tipo);
    int matriz[nos][nos];
    int matriz_ponderada[nos][nos];

    cria_matriz(nos, matriz);
    insere_matriz(tipo, nos, arestas, matriz, matriz_ponderada);
    printa_matriz(nos, matriz);
    grau_no(nos, matriz);
    vertice_isolado(nos, matriz);
    aresta_paralela(nos, matriz);
    loop(nos, matriz);
    completo(nos, matriz);
    regular(nos, matriz);
    grau_max(nos,matriz);
    grau_min(nos, matriz);
}