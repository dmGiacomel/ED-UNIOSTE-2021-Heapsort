//---------------------------------Classe NODE --------------------------------------------------

//----Cada nó armazena um dado do tipo datatype e aponta para um nó anterior e para um próximo nó
//----Pode ser usado para estruturas duplamente encadeadas ou apenas simplesmente encadeadas, 
//----utilizando apenas os métodos que operam sobre *next ou apenas os métodos que operam sobre *prev

//----classe simples, com getters e setters para todos os atributos e três construtores, que inicializam
//----nenhum, um ou os três atributos da classe por parâmetro

//----IFNDEF para prevenir múltiplos includes

//________OBS: classes que utilizam template não podem ter assinaturas e definições em arquivos diferentes
//------------------------------------------------------------------------------------------------
#ifndef NODE_H
#define NODE_H

//*******************************************************************************
//------------DECLARACAO DA CLASSE, METODOS E ATRIBUTOS------------------------
//*******************************************************************************
template <typename datatype> 
class Node{

private: 
    datatype data;
    Node<datatype> *next;
    Node<datatype> *prev;

public:
    Node();
    Node(datatype data);
    Node(datatype data, Node<datatype> *prev, Node<datatype> *next);
    ~Node();

    datatype getData();
    void setData(datatype data);
    Node<datatype>* getNext();
    void setNext (Node<datatype> *next);
    Node<datatype>* getPrev();
    void setPrev (Node<datatype> *prev);
};


//*************************************************************************
//-----------DEFINICAO DOS METODOS DA CLASSE-------------------------------
//*************************************************************************


//construtor padrao, seta o dado como zero e os ponteiros como nulos
template <typename datatype> 
Node<datatype>::Node(){
    data = (datatype)0;
    next = nullptr;
    prev = nullptr;
}

//construtor que seta o dado como o dado recebido por paramentro
template <typename datatype> 
Node<datatype>::Node(datatype data){
    this->data = data;
    next = nullptr;
    prev = nullptr;
}

//construtor que seta os três atributos por parâmetro
template <typename datatype> 
Node<datatype>::Node(datatype data, Node<datatype> *prev, Node<datatype> *next){
    this->data = data;
    this->next = next;
    this->prev = prev;
}

//destrutor padrão
template <typename datatype>
Node<datatype>::~Node(){
    next = nullptr;
    prev = nullptr;
}

//retorna o valor do campo dado
template <typename datatype>
datatype Node<datatype>::getData(){
    return data;
}

//seta o valor do campo dado por parâmetro
template <typename datatype>
void Node<datatype>::setData(datatype data){
    this->data = data;
}

//retorna o ponteiro next
template <typename datatype>
Node<datatype>* Node<datatype>::getNext(){
    return next;
}

//seta o ponteiro next por parametro
template <typename datatype> 
void Node<datatype>::setNext(Node<datatype> *next){
    this->next = next;
}

//retorna o ponteiro prev
template <typename datatype> 
Node<datatype>* Node<datatype>::getPrev(){
    return prev;
}

//seta o ponteiro prev por parametro
template <typename datatype> 
void Node<datatype>::setPrev(Node<datatype> *next){
    this->prev = prev;
}

#endif