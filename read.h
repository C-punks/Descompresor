#include "estructuras.h"
#include "Pilas.h"

#ifndef _READ_H_
#define _READ_H_

void Arma_Arbol(struct nodoarbol* arbol, FILE *archivo ,Pila *pila);
void agrega_hijo(struct nodoarbol* nodopadre,int carac , char cod);
void Imprime_Arbol(struct nodoarbol * Arbol);
void Decodifica(FILE * entrada,FILE *salida,struct nodoarbol * arbol);

#endif