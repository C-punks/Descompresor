#include "estructuras.h"

#ifndef  _PILAS_H_
#define  _PILAS_H_

Pila * CreaPila();
void Push(Pila *p, struct nodoarbol * nodo);
void Pop(Pila *p);
struct nodoarbol* Tope(Pila *p);

#endif