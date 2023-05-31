#include "./lista_de_adjacencia/lista_de_adjacencia.h"
#include "./bfs/bfs.h"
#include "./dfs/dfs.h"


void main() {
    Graph* g = newGraph(9);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);

    add_edge(g, 1, 0);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 1, 5);

    add_edge(g, 2, 0);
    add_edge(g, 2, 6);

    add_edge(g, 3, 1);
    add_edge(g, 4, 1);

    add_edge(g, 5, 1);
    add_edge(g, 5, 7);

    add_edge(g, 6, 2);
    add_edge(g, 6, 8);

    add_edge(g, 7, 5);

    add_edge(g, 8, 6);

    print_graph(g);

    depth_first_search(g);
}