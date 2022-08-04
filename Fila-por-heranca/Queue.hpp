//---------------------------------Classe QUEUE --------------------------------------------------

//----Utiliza os atributos e métodos herdados da classe List.
//----implementa apenas o método dequeue, enqueue e printQueue, 
//----que na prática são removeFirst, append e printList


//----------ATENCAO COM O PRINTQUEUE - pode não funcionar pra todo tipo de dado.
//________OBS: classes que utilizam template não podem ter assinaturas e definições em arquivos diferentes
//------------------------------------------------------------------------------------------------

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "List.hpp"

//*******************************************************************************
//------------DECLARACAO DA CLASSE, METODOS E ATRIBUTOS------------------------
//*******************************************************************************
template <typename datatype> 
class Queue : private List<datatype>{
 
    public:
    Queue();
    ~Queue();
    void enQueue(datatype data);
    datatype deQueue();
    void printQueue();
};

//construtor padrao vazio. chama o construtor da superclasse list
template <typename datatype>
Queue<datatype>::Queue(){}

//destrutor padrao vazio. chama o destrutor da superclasse list
template <typename datatype>
Queue<datatype>::~Queue(){}

//mesmo que append de List
template <typename datatype>
void Queue<datatype>::enQueue(datatype data){
    List<datatype>::append(data);
}

//mesmo que removeFirst de List
template <typename datatype>
datatype Queue<datatype>::deQueue(){
    return List<datatype>::removeFirst();
}

//mesmo que printList de List
template <typename datatype>
void Queue<datatype>::printQueue(){
    List<datatype>::printList();
}

#endif