#include "grafo.h"

static int cnt;


// inicializa o grafo, alocando espaço na memória e alocando as listas de adjacencia dos vértices
graph* graphInit(int V){
    graph *G = (graph*) malloc(sizeof(graph));
    G->V = V;
    G->A = 0;
    G->adj = (list*) malloc(sizeof(list) * V);
    for(int i = 0; i < V; i++)
        initList(&G->adj[i]);

    return G;
}

// insere uma aresta entre dois vértices informados
void graphInserirAresta(graph *G, vertice v, vertice w){

    // caso um dos vértices seja maior do que a qtd de vértices do grafo, retorna com erro
    if(v >= G->V){
        printf("Erro: indicou um vertice maior que o tamanho do grafo\n");
        return;
    }
    else if(w >= G->V){
        printf("Erro: indicou um vertice maior que o tamanho do grafo\n");
        return;
    }
    // se os vertices forem iguais, retorna erro
    else if(v == w){
        printf("Grafos não direcionados não podem possuir self-loop\n");
        return;
    }


    // verifica se a aresta já não existe
    for(node *a = G->adj[v].first; a != NULL; a = a->next){
        if(a->data == w){
            return;
        }
    }
    insertRight(w, &G->adj[v]);

    // verifica se a aresta já não existe
    for(node *a = G->adj[w].first; a != NULL; a = a->next){
        if(a->data == v){
            return;
        }
    }
    insertRight(v, &G->adj[w]);
    G->A++;
}

// exclui uma aresta entre dois vértices informados
void graphExcluirAresta(graph *G, vertice v, vertice w){

    // se v > do que a qtd de vertices do grafo
    if(v >= G->V){
        printf("Erro: indicou um vertice maior que o tamanho do grafo\n");
        return;
    }
    else if(w >= G->V){
        printf("Erro: indicou um vertice maior que o tamanho do grafo\n");
        return; 
    }

    removeSpec(w, &G->adj[v]);
    removeSpec(v, &G->adj[w]);

    G->A--;
}

// código para recursão para verificar se um vertice alcança outro vértice
void reachR(graph *G, vertice v, int *visited){
    visited = (int*) malloc(sizeof(int) * G->V);
    visited[v] = 1;
    for(node *a = G->adj[v].first; a != NULL; a = a->next){
        if(visited[a->data] == 0){
            free(visited), reachR(G, a->data, visited);
        }
    }
}

// função que verifica se um vértice s alcança outro vértice t
bool graphReach(graph *G, vertice s, vertice t){
    int *visited;
    visited = (int*) malloc(sizeof(int) * G->V);
    for(int i = 0; i < G->V; i++){
        visited[i] = 0;
    }
    reachR(G, s, visited);
    if(visited[t] == 0){
        free(visited); 
        return false;
    }
    else{
        free(visited);
        return true;
    }
}


// realiza busca em largura a partir de um vértice v até os demais vértices do grafo
list* buscaLargura(graph *G, vertice v){
    list *queue, *visitados;
    node *aux;
    
    queue = initList(queue);
    visitados = initList(visitados);

    if(G->A < 1){
        printf("Arestas insuficientes.\n");
        return visitados;
    }

    insertRight(v, queue);
    while(!emptyList(*queue)){
        int visitado = removeLeft(queue);
        if(searchList(visitado, *visitados) == NULL)
            insertRight(visitado, visitados);
        for(node *a = G->adj[visitado].first; a != NULL; a = a->next){
            if((searchList(a->data, *queue) == NULL) && (searchList(a->data, *visitados) == NULL)){
                insertRight(a->data, queue);
            }
        }
    }

    deleteList(queue);
    return visitados;
}


// realiza busca em profundidade a partir do vértice v
list* buscaProfundidade(graph *G, vertice v){
    list *stack, *visitados;
    node *aux;

    stack = initList(stack);
    visitados = initList(visitados);
    
    // testa se há arestas suficientes
    if(G->A < 1){
        printf("Arestas insuficientes.\n");
        return visitados;
    }

    if(G->A < 1){
        printf("Arestas insuficientes.\n");
        return visitados;
    }


    insertRight(v, stack);
    while(!emptyList(*stack)){
        int visitado = removeRight(stack);
        if(searchList(visitado, *visitados) == NULL)
            insertRight(visitado, visitados);
        for(node *a = G->adj[visitado].first; a != NULL; a = a->next){
            if(/*(searchList(a->data, *stack) == NULL) &&*/ (searchList(a->data, *visitados) == NULL)){
                insertRight(a->data, stack);
            }
        }
    }

    deleteList(stack);
    return visitados;

}

// imprime o grafo e suas listas de adjacencia
void graphImprime(graph *G){
    printf("G->V = %d\n", G->V);
    printf("G->A = %d\n", G->A);
    for(int i = 0; i < G->V; i++){
        printf("V%d:: ", i);
        printList(G->adj[i]);
        printf("\n");
    }
}

// desaloca o espaço de memória ocupado pelo grafo e suas listas
void graphDeleta(graph *G){
    for(int i = 0; i < G->V; i++){
        deleteList(&G->adj[i]);
    }
    free(G->adj);
    free(G);
}