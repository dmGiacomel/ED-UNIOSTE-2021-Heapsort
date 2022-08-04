#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "node.h"
#include "list.h"

#define vertice int

typedef struct graph{
    int V;
    int A;
    list *adj;
} graph;

graph* graphInit(int V);

void graphInserirAresta(graph *G, vertice v, vertice w);

void graphExcluirAresta(graph *G, vertice v, vertice w);

void reachR(graph *G, vertice v, int *visited);

bool graphReach(graph *G, vertice s, vertice t);

list* buscaProfundidade(graph *G, vertice v);

list* buscaLargura(graph *G, vertice s);

void graphImprime(graph *G);

void graphDeleta(graph *G);