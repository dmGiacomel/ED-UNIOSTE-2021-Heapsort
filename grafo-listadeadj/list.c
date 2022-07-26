/**
  * ListaSE.c
  * Implementa o tipo de dado lista simplesmente encadeada
  */

#include "list.h"
//=========================================================================
// Funções de lista simplesmente encadeada
//=========================================================================

//-----------------------
//Inicialização da lista
//-----------------------
void initList(lista *L)
{
  L->first = NULL;
  L->last = NULL;
  L->length = 0;
}

//---------------------
// Destruição da lista
//---------------------
void deleteList(lista *L)
{
  node *p = L->first;
  while (p)
  {
    L->first = L->first->next;
    free(p);
    p = L->first;
  }
  L->length = 0;
  L->last = NULL;
}

//---------------------
// Inserção à esquerda
//---------------------
short insertLeft(data x, lista *L)
{
  node *aux;
  aux = (node*)malloc(sizeof(node));
  if (aux == NULL)
    return 1; // retorna 1 sinalizando que não conseguiu alocar o nó e deixando 
              //a lista original intacta
  else
  {
    aux->info = x;  // insere o valor de x no nó
    aux->next = L->first; // insere o novo elemento antes do atual primeiro
    L->first = aux;   // aux passaa  ser o primerio
    if (L->last == NULL) //ajusta  o ultimo
      L->last = aux;
    L->length++; // incrementa o no de elementos
    return 0;
  }
}

//--------------------
// Inserção à direita
//--------------------
short insertRight(data x, lista *L)
{
  node *aux = (node*)malloc(sizeof(node));
  if (aux == NULL)
    return 1; // sinaliza erro se não consegue alocar o novo nó.
  else
  {
    aux->info = x;
    aux->next = NULL;
    if (L->last == NULL) // lista vazia
      L->first = L->last = aux; // first e last apontam para o mesmo nó.
    else
    {
      L->last->next = aux;
      L->last = aux;
    }
    L->length++;
    return 0;
  }
}

//----------------------------------------------------------
// verifica lista vazia.
// Obs: deve ser usada apenas após a inicialização da Lista
//----------------------------------------------------------
bool emptyList(lista L)
{
  return (L.length == 0);
}

//--------------------
// remoção à esquerda
//-------------------
data removeLeft(lista *L)
{
  node *aux = L->first; // guarda o nó a ser removido
  data Ret = aux->info; // guarda o valor de retorno da função

  L->first = L->first->next;
  free(aux);
  if (L->first == NULL)
    L->last = NULL;
  L->length--;
  return Ret;
}

//----------------------
// Remoção pela direita
//----------------------
data  removeRight(lista *L)
{
  node *aux = L->last; // guarda o nó a ser removido
  data Ret = aux->info; // guarda o valor a ser removido

  if (L->first == L->last)
  {
    free(aux);
    L->first = L->last = NULL;
  }
  else
  { 
    L->last = L->first;
    while (L->last->next != aux)
      L->last = L->last->next;
    free(aux);
    L->last->next = NULL;
  }
  L->length--;
  return Ret;
}

//---------------------------
// Função de busca sequencial
// --------------------------
node* searchList(data x, lista L)
{
  node *aux = L.first;

  while (aux && x != aux->info)
  {
    aux = aux->next;
  }
  return aux;
}

//----------------------
// Inserção por posição
//----------------------
short insertPos(data x, unsigned p, lista *L)
{
  // verificar se a posição está dentro do intervalo possível [0, L->length]
  if (p > L->length)
    return 1;
  else
  {
    // inserção na posição 0: chama inserção pela esquerda
    if (p == 0)
      return insertLeft(x, L);
    else if (p == L->length) // inserção na última posição: chama inserção à direita
      return insertRight(x, L);
    else
    {
      node *p1 = L->first, *aux;
      unsigned i = 0;
      aux = (node*)malloc(sizeof(node));
      if (!aux)
      {
        printf("Erro: não foi possível alocar memória.\n");
        return 1;
      }
      // procura o local da inserção
      while (++i < p)
      {
        p1 = p1->next;
      }
      aux->info = x;
      aux->next = p1->next;
      p1->next = aux;
      L->length++;
      return 0;
    }
  }
}

//---------------------
// Remoção por posição
//---------------------
data removePos(unsigned p, lista *L)
{
  // verifica o intervalo da posição
  if (p > L->length - 1)
    exit(1); // encerra a execução e retorna código de erro 1
  else if (p == 0) // é remoção pela esquerda
    return removeLeft(L);
  else if (p == L->length - 1)
    return removeRight(L);
  else // a remoção é de um nó interior
  {
    node *p1 = L->first, *p2 = NULL;
    data ret;
    unsigned i = 0;
    
    // procurar o local da remoção
    while (++i < p)
    {
      p1 = p1->next;
    }
    // remove
    p2 = p1->next;
    p1->next = p2->next;
    ret = p2->info;
    free(p2);
    L->length--; 
    return ret;
  }
}