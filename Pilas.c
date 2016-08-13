#include "Pilas.h"

Pila *CreaPila()
{
	Pila *p;
	p= (Pila*)malloc(sizeof(Pila));
	p->tam = 0;
	p->tope = NULL;
	
	return p;
	
}
void Push(Pila *p, struct nodoarbol * nodo)
{
	struct nodopila *nuevo;
	
	nuevo = (struct nodopila*)malloc(sizeof(struct nodopila));
	
	nuevo->nodopadre = nodo;
	
	if (p->tam == 0)
	{
		nuevo->sig = NULL;
		p->tope = nuevo;
	}
	else
	{
		nuevo->sig = p->tope;
		p->tope = nuevo;
	}
	p->tam++;
}

void Pop(Pila *p)
{
	struct nodopila * aux;
	
	if (p->tam == 0)
	{
		printf("La pila esta vacía !!");
	}
	else
	{
		aux = p->tope;
		p->tope = aux->sig;
		free(aux);
		p->tam --;
	}
}


struct nodoarbol* Tope(Pila *p)
{
	if (p->tam == 0)
	{
		printf("Pila vacia !!");
	}
	else
	{
		return p->tope->nodopadre;
	}
}