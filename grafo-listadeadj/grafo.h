#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


// *********** descrição das funções seguintes ***********
// FLVazia = cria uma lista vazia,
// insere = insere um elemento tipoItem na lista
// retira = procura o elemento passado como parametro e o exclui
//          da lista
// ********************************************************
// void FLVazia(tipoLista *aLista);
// void insere(tipoItem *x, tipoLista *aLista);
// void retira(tipoApontador aux, tipoLista *aLista, tipoItem *x);

// *********** descrição das funções seguintes ***********
// FGVazio => cria um grafo vazio
// insereAresta => insere uma aresta entre dois vertices no grafo
// existeAresta => verifica se existe uma aresta entre dois vertices
// listaAdjVazia => verifica se a lista de adjacencia de um vertice está vazia
// primeiroListaAdj => retorna o primeiro item da lista de adjacencia de um vertice
// proxAdj => retorna os valores do proximo item da lista de adjacencia de um vertice
// retiraAresta => exclui uma aresta entre dois vertices se essa existir
// liberaGrafo => libera o espaço de memória alocado para o grafo
// imprimeGrafo => imprime os elementos presentes no grafo 
// ********************************************************
// void FGVazio(tipoGrafo *grafo);
// void insereAresta(tipoValorVertice *V1, tipoValorVertice *V2, tipoPeso *peso, tipoGrafo *grafo);
// short existeAresta(tipoValorVertice V1, tipoValorVertice V2, tipoGrafo *grafo);
// short listaAdjVazia(tipoValorVertice *vertice, tipoGrafo *grafo);
// tipoApontador primeiroListaAdj(tipoValorVertice *vertice, tipoGrafo *grafo);
// void proxAdj(tipoValorVertice *vertice, tipoGrafo *grafo, tipoValorVertice *adj, tipoPeso *peso, tipoApontador *prox, short *fimListaAdj);
// void retiraAresta(tipoValorVertice *V1, tipoValorVertice *V2, tipoPeso *peso, tipoGrafo *grafo);
// void liberaGrafo(tipoGrafo *grafo);
// void imprimeGrafo(tipoGrafo *grafo);