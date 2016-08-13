
#ifndef  _ESTRUCTURAS_H_
#define  _ESTRUCTURAS_H_


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

struct nodoarbol
{
	int caracter;
	char codificacion[MAX];
	struct nodoarbol * HijoI;
	struct nodoarbol * HijoD;
};


struct nodopila
{
	struct nodopila * sig;
	struct nodoarbol* nodopadre;
};

typedef struct
{
	int tam;
	struct nodopila *tope;
}Pila;

#endif