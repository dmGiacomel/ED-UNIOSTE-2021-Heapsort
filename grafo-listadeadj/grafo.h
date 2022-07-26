#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

// numero maximo de vertices do grafo
#define MAXNUMVERTICES 100
// numero maximo de arestas do grafo
#define MAXNUMARESTAS 4500

// definindo o tipo de valor dos vértices (inteiros)
typedef int tipoValorVertice;
// definindo o tipo de valor dos pesos das arestas
typedef int tipoPeso;

// estrutura do tipo de item (um item dessa estrutura tem os
// valores de vertices e peso)
typedef struct tipoItem{
    tipoValorVertice vertice;
    tipoPeso peso;
} tipoItem;

// estrutura do tipo de célula, que possui um tipo de ponteiro
typedef struct tipoCelula *tipoApontador;

// a estrutura tipoCelula possui um item e um apontador para
// a proxima celula
struct tipoCelula{
    tipoItem item;
    tipoApontador prox;
} tipoCelula;

// estrutura de lista, que tem um apontador para primeiro e 
// ultimo item
typedef struct tipoLista{
    tipoApontador primeiro, ultimo;
} tipoLista;

// estrutura de grafo, que possui uma lista de adjacencia do
// tamanho do número de vertices, possui uma variavel que 
// armazena o numero de vertices e uma variavel que armazena
// o numero de arestas
typedef struct tipoGrafo{
    tipoLista adj[MAXNUMVERTICES + 1];
    tipoValorVertice numVertices;
    short numArestas;
} tipoGrafo;



// *********** descrição das funções seguintes ***********
// FLVazia = cria uma lista vazia,
// insere = insere um elemento tipoItem na lista
// retira = procura o elemento passado como parametro e o exclui
//          da lista
// ********************************************************
void FLVazia(tipoLista *aLista);
void insere(tipoItem *x, tipoLista *aLista);
void retira(tipoApontador aux, tipoLista *aLista, tipoItem *x);



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
void FGVazio(tipoGrafo *grafo);
void insereAresta(tipoValorVertice *V1, tipoValorVertice *V2, tipoPeso *peso, tipoGrafo *grafo);
short existeAresta(tipoValorVertice V1, tipoValorVertice V2, tipoGrafo *grafo);
short listaAdjVazia(tipoValorVertice *vertice, tipoGrafo *grafo);
tipoApontador primeiroListaAdj(tipoValorVertice *vertice, tipoGrafo *grafo);
void proxAdj(tipoValorVertice *vertice, tipoGrafo *grafo, tipoValorVertice *adj, tipoPeso *peso, tipoApontador *prox, short *fimListaAdj);
void retiraAresta(tipoValorVertice *V1, tipoValorVertice *V2, tipoPeso *peso, tipoGrafo *grafo);
void liberaGrafo(tipoGrafo *grafo);
void imprimeGrafo(tipoGrafo *grafo);

