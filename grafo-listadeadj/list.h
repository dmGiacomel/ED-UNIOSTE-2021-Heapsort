/**
  * ListaSE.h
  * Implementa o tipo de dado lista simplesmente encadeada
  */
#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "data.h"

// #define o tipo de dado para o nó de lista encadeada
typedef struct node
{
  data info; // dado armazenado no nó
  struct node *next; // ponteiro para o próximo nó
} node;

// define o nó cabeça da lista
typedef struct lista
{
  node *first; // ponteiro para o 1o elemento da lista
  unsigned length; // número de elementos armazenado
  node *last; // ponteiro para o último elemento da lista
} lista;

//=========================================================================
// Funções de lista simplesmente encadeada
//=========================================================================

//-----------------------
//Inicialização da lista
//-----------------------
void initList(lista *L);

//---------------------
// Destruição da lista
//---------------------
void deleteList(lista *L);

//---------------------
// Inserção à esquerda
//---------------------
short insertLeft(data x, lista *L);

//--------------------
// Inserção à direita
//--------------------
short insertRight(data x, lista *L);

//----------------------------------------------------------
// verifica lista vazia.
// Obs: deve ser usada apenas após a inicialização da Lista
//----------------------------------------------------------
bool emptyList(lista L);

//--------------------
// remoção à esquerda
//-------------------
data removeLeft(lista *L);

//----------------------
// Remoção pela direita
//----------------------
data  removeRight(lista *L);

//---------------------------
// Função de busca sequencial
// --------------------------
node* searchList(data x, lista L);

//----------------------
// Inserção por posição
//----------------------
short insertPos(data x, unsigned p, lista *L);

//--------------------
// Remoção por posição
//---------------------
data removePos(unsigned p, lista *L);

#endif