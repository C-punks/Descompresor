#include "read.h"



void Arma_Arbol(struct nodoarbol* arbol, FILE *archivo ,Pila *pila)
{
	int aux;
	struct nodoarbol* tmp;
	int flag,flag2=0;
		
	Push(pila,arbol);
	
	tmp = arbol;
	
	while (  flag2 != 2 )
	{		
			aux = fgetc(archivo);

			if (aux == ' ')
				flag2++;

			flag = 0;
			
			if (aux == 92 && tmp->HijoI == NULL)
			{
				if (tmp != arbol)
					agrega_hijo(tmp,aux,'0');
				if (tmp == arbol)
					agrega_hijo(tmp,aux,'2');
				tmp = tmp->HijoI;
				Push( pila ,tmp);
			}
			if (aux != 92 && tmp->HijoI == NULL )
			{
				agrega_hijo(tmp,aux,'0');
				tmp = Tope(pila);
				Pop(pila);
				flag = 1;
			}
			if (aux == 92 && tmp->HijoI != NULL)
			{
				agrega_hijo(tmp,aux,'1');
				tmp = tmp->HijoD;
				Push( pila ,tmp);
			}
			if (aux != 92 && tmp->HijoI != NULL  && flag == 0 )
			{
				agrega_hijo(tmp,aux,'1');
				
					tmp = Tope(pila);
					Pop(pila);
			}
	}
	tmp = arbol;
	arbol = arbol->HijoI;
	free(tmp);
}


void agrega_hijo(struct nodoarbol* nodopadre,int carac , char cod)
{
	struct nodoarbol *nuevo;
	
	nuevo = (struct nodoarbol*)malloc(sizeof(struct nodoarbol));
	
	nuevo -> caracter = carac ;
	strcat(nuevo->codificacion,nodopadre->codificacion);
	nuevo->HijoI =NULL;
	nuevo->HijoD =NULL;
	if (cod == '1')
	{
		strcat(nuevo->codificacion,"1");
		nodopadre->HijoD = nuevo;
	}
	if (cod == '0')
	{
		strcat(nuevo->codificacion,"0");
		nodopadre->HijoI = nuevo;
	}
	if (cod == '2')
	{
		strcat(nuevo->codificacion,"");
		nodopadre->HijoI = nuevo;
	}
	
	
}

void Imprime_Arbol(struct nodoarbol * Arbol)
{
	if (Arbol == NULL) return;
	
	if (Arbol->caracter == 32 )
			printf("[Space]\t\t---> cod :\t\t%s \n",Arbol->codificacion);
	else		
		if (Arbol->caracter == 10 )
			printf("[Enter]\t\t---> cod :\t\t%s \n",Arbol->codificacion);
		else
			printf("[%c]\t\t---> cod :\t\t%s \n", Arbol->caracter,Arbol->codificacion);
	
	Imprime_Arbol(Arbol->HijoI);
	Imprime_Arbol(Arbol->HijoD);
}

void Decodifica(FILE * entrada,FILE *salida,struct nodoarbol * arbol)
{
	int bit,i;
	int uno = 1 << 7;
	int recorre;
	struct nodoarbol *aux;
		
	aux = arbol;
	//recorre = fgetc(entrada);
	
	while (!feof(entrada))
	{
		recorre = fgetc(entrada);

		for (i=0;i<8;i++){
      		
      		bit = recorre & uno;
			recorre = recorre << 1;
			
      		if (bit==0){
				
				aux = aux->HijoI;
				
				if (aux->caracter != 92 )
				{
					//fprintf(salida,"%c",aux->caracter);
					fputc(aux->caracter,salida);
					aux = arbol;
        		}
			}else
			{
				aux = aux->HijoD;
				
				if (aux->caracter != 92)
				{
					fputc(aux->caracter,salida);
					//fprintf(salida,"%c",aux->caracter);
					aux = arbol;
        		}
      		}
    	}
	}

    //recorre = fgetc(entrada);
    
}

