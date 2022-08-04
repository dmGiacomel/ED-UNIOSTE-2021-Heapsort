#include "node.h"

// aloca um novo nodo, atribuindo os valores correspondentes
link newNode(vertice w, link next){
    link a = (struct nodeGraph*) malloc(sizeof(struct nodeGraph));
    a->w = w;
    a->next = next;
    return a;
}
