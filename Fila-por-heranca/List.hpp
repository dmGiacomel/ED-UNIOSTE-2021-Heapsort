//---------------------------------Classe LIST --------------------------------------------------

//----Cada lista tem um ponteiro para o nó inicial, um ponteiro para o nó final e um campo tamanho

//----classe com getters, setters e métodos espécíficos de manipulação de lista
//----construtor padrao e destrutor padrao
//----nem todos os métodos foram definidos e declarados ainda, apenas os necessários para as finalidades do trabalho 

//----IFNDEF para prevenir múltiplos includes

//CUIDADO AO UTILIZAR O PRINT- pode não funcionar pra todo tipo de dado.

//________OBS: classes que utilizam template não podem ter assinaturas e definições em arquivos diferentes
//------------------------------------------------------------------------------------------------

#ifndef LIST_H
#define LIST_H
#include "Node.hpp"
#include <iostream>

//*******************************************************************************
//------------DECLARACAO DA CLASSE, METODOS E ATRIBUTOS------------------------
//*******************************************************************************
template <typename datatype> 
class List{

private: 
    Node <datatype> *first;
    Node <datatype> *last;
    unsigned long long int size;

public:
    List();
    ~List();
 
    datatype getFirst();
    datatype getLast();
    unsigned long long int getSize();

    datatype getElementByPosition(unsigned long long int position);
    bool elementExists(datatype data);
    void setFirst(Node<datatype> *node);
    void setLast(Node<datatype> *node);
    void append(datatype data);
    void insertFirst(datatype data);

    datatype removeFirst();

    void printList();

};



//*************************************************************************
//-----------DEFINICAO DOS METODOS DA CLASSE-------------------------------
//*************************************************************************

//construtor padrao. inicializa uma lista vazia
template <typename datatype>
List<datatype>::List(){
    first = nullptr;
    last = nullptr;
    size = 0;
}

//destrutor padrao. desaloca todos os nós
template <typename datatype>
List<datatype>::~List(){
    Node <datatype> *aux = first;

    while (aux != nullptr){
        first = first->getNext();
        delete(first);
        aux = first;
    }
}

//seta o campo first para o ponteiro para nó recebido
template <typename datatype>
void List<datatype>::setFirst(Node<datatype> *node){
    first = node;
}

//seta o campo last para o ponteiro para nó recebido
template <typename datatype>
void List<datatype>::setLast(Node<datatype> *node){
    last = node;
}

//retorna o valor do campo size
template <typename datatype>
unsigned long long int List<datatype>::getSize(){
    return size;
}

//insere data no início da lista
template <typename datatype>
void List<datatype>::insertFirst(datatype data){

    Node<datatype> *aux;
    aux = new Node<datatype>(data);

    aux->setNext(first);
    first = aux;
    if(last == nullptr){
        last = aux;
    }

    size++;
}

//insere data no fim da lista
template <typename datatype>
void List<datatype>::append(datatype data){
   
    Node<datatype> *aux; 
    aux = new Node<datatype>(data);
    aux->setNext(nullptr);

    if(size > 0){
        last->setNext(aux);
        last = aux;
    }else{
        last = aux;
        first = aux;
    }
    
    size++;
}

//remove o item à esquerda da lista e retorna o valor do item removido
template <typename datatype>
datatype List<datatype>::removeFirst(){

    datatype data{0};
    Node<datatype> *aux;

    if(first != nullptr){
        data = first->getData();
        aux = first;
        first = first->getNext();
        delete(aux);
        size--;

        if(first == nullptr){
            last = nullptr;
        }
    }else{
        std::cout << "Empty List! Returning default <datatype> 0 value...\n";
    }

    return data;
}

//printa a lista usando cout
//CUIDADO AO UTILIZAR - pode não funcionar pra todo tipo de dado.
template <typename datatype>
void List<datatype>::printList(){

    Node<datatype> *aux = first;
    unsigned long long int cont{0};

    if(size == 0){
        std::cout << "[]" << std::endl;
    }else{
        std::cout << "[";
        while(cont < size - 1){
            std::cout << aux->getData() << ", "; 
            aux = aux->getNext();
            cont++;
        }
        std::cout << aux->getData() << "]" << std::endl; 
    }
}
#endif