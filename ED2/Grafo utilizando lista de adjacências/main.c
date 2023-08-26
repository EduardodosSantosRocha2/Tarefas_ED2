#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#include "Fun.h"




int main()
{


	GRAFO * grafo = gerarGrafo(5);
	//1
	criaAresta(grafo, 1, 2, 2,"1");
	criaAresta(grafo, 1, 3, 40,"1");
	criaAresta(grafo, 1, 4, 4,"1");
	//2
	criaAresta(grafo, 2, 1, 12,"2");
	criaAresta(grafo, 2, 3, 12,"2");
	//3
	criaAresta(grafo, 3, 1, 40,"3");
	criaAresta(grafo, 3,2, 40,"3");
	//4
	criaAresta(grafo, 4, 1, 40,"4");





    imprimeGrafo(grafo);
}
