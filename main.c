#include "read.h"
#include "Pilas.h"

int main (int argc, char *argv[])
{
	FILE * doc;
	FILE * descomprimido;
	
	int aux;
	
	Pila *pila;
	struct nodoarbol* Raiz;
	
	if (argc != 3)
	{
		printf("Use %s <doc_comprimido> <doc_descomprimido>",argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
	
		pila = CreaPila();
		Raiz = (struct nodoarbol*)malloc(sizeof(struct nodoarbol));
	
		doc= fopen(argv[1] ,"rb");
		descomprimido = fopen(argv[2],"w+");
		
		
		Arma_Arbol(Raiz,doc ,pila);
		Raiz = Raiz->HijoI;
		
		Decodifica(doc,descomprimido,Raiz);
		Imprime_Arbol(Raiz);
		
		fclose(doc);
		fclose(descomprimido);
	
	}
	
	
	return 0;
}
