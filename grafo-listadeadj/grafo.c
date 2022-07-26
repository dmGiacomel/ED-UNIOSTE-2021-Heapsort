#include "grafo.h"
#define FALSE 0
#define TRUE 1


void FLVazia(tipoLista *aLista){
    aLista = malloc(sizeof(tipoLista)*MAXNUMVERTICES);
    if(aLista != NULL){
        for(int i = 0; i < MAXNUMVERTICES; i++){
            aLista->primeiro->item.peso = 0;
            aLista->primeiro->item.vertice = NULL;
        }
    }
}

void insere(tipoItem *x, tipoLista *aLista){
    tipoApontador novo;
    novo = malloc(sizeof(tipoApontador));
    if(novo == NULL){
        return;
    }
    else{
        novo->prox = aLista->primeiro->prox;
        novo->prox->item.peso = x->peso;
        novo->prox->item.vertice = x->vertice;
        aLista->primeiro = novo;
    }
}

void retira(tipoApontador aux, tipoLista *aLista, tipoItem *x){
    // ainda precisa implementar essa, jesus cristo
}

void FGVazio(tipoGrafo *grafo){
    long i; // variavel pra iteração
    for(i = 0; i < grafo->numVertices; i++){
        FLVazia(&grafo->adj[i]); // cria uma lista de adjacencia vazia
    }
}

void insereAresta(tipoValorVertice *V1, tipoValorVertice *V2, tipoPeso *peso, tipoGrafo *grafo){
    tipoItem x;
    x.vertice = *V2;
    x.peso = *peso;
    insere(&x, &grafo->adj[*V1]);
}

short existeAresta(tipoValorVertice V1, tipoValorVertice V2, tipoGrafo *grafo){
    tipoApontador aux;
    short encontrouAresta = FALSE;
    aux = grafo->adj[V1].primeiro->prox;
    while(aux != NULL && encontrouAresta == FALSE){
        if(V2 == aux->item.vertice){
            encontrouAresta = TRUE;
        }
        aux = aux->prox;
    }

    return encontrouAresta;
}

short listaAdjVazia(tipoValorVertice *vertice, tipoGrafo *grafo){
    return(grafo->adj[*vertice].primeiro == grafo->adj[*vertice].ultimo);
}

tipoApontador primeiroListaAdj(tipoValorVertice *vertice, tipoGrafo *grafo){
    return (grafo->adj[*vertice].primeiro->prox);
}

void proxAdj(tipoValorVertice *vertice, tipoGrafo *grafo, tipoValorVertice *adj, tipoPeso *peso, tipoApontador *prox, short *fimListaAdj){
    // returna adj e peso do item apontado por prox
    *adj = (*prox)->item.vertice;
    *peso = (*prox)->item.peso;
    *prox = (*prox)->prox;
    if(*prox == NULL)
        *fimListaAdj = TRUE;
}

void retiraAresta(tipoValorVertice *V1, tipoValorVertice *V2, tipoPeso *peso, tipoGrafo *grafo){
    tipoApontador auxAnterior, aux;
    short encontrouAresta = FALSE;
    tipoItem x;
    auxAnterior = grafo->adj[*V1].primeiro;
    aux = grafo->adj[*V1].primeiro->prox;
    while(aux != NULL && encontrouAresta == FALSE){
        if(*V2 == aux->item.vertice){
            retira(auxAnterior, &grafo->adj[*V1], &x);
            grafo->numArestas--;
            encontrouAresta = TRUE;
        }
        auxAnterior = aux;
        aux = aux->prox;
    }
}

void liberaGrafo(tipoGrafo *grafo){
    tipoApontador auxAnterior, aux;
    for(int i = 0; i < grafo->numVertices; i++){
        aux = grafo->adj[i].primeiro->prox;
        free(grafo->adj[i].primeiro); // libera celula cabeça
        grafo->adj[i].primeiro = NULL;
        while(aux != NULL){
            auxAnterior = aux;
            aux = aux->prox;
            free(auxAnterior);
        }
    }
    grafo->numVertices = 0;
}

void imprimeGrafo(tipoGrafo *grafo){
    int i;
    tipoApontador aux;
    for(i = 0; i < grafo->numVertices; i++){
        printf("vertice %d: ", i);
        if(!vazia(grafo->adj[i])){
            aux = grafo->adj[i].primeiro->prox;
            while(aux != NULL){
                printf("%d(%d)", aux->item.vertice, aux->item.peso);
                aux = aux->prox;
            }
        }
        printf("\n");
    }
}

