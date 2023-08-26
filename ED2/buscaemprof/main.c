

#include <stdio.h>
#include <malloc.h>

#define MAX_VERTICES 6 // M�XIMO DE V�RTICES DO GRAFO, SE FOR ALTERAR O GRAFO PRECISA ALTERAR ESTA VARI�VEL TAMB�M
#define MAX_ARESTAS (MAX_VERTICES * (MAX_VERTICES-1)) // CALCULA O N�MERO M�XIMO DE ARESTAS QUE O GRAFO PODER� TER

// Estrutura que define cada V�rtice do Grafo
typedef struct NO{
	char id;
	int nroVizinhos;
	struct NO* vizinhos[MAX_ARESTAS];
	bool visitado;
}*VERTICE;

// Cria V�rtice e retorna
VERTICE criaVertice(char id){
	VERTICE novoVertice = (VERTICE) malloc( sizeof(NO) ); // Aloca um novo V�rtice
	novoVertice->id = id;
	novoVertice->nroVizinhos = 0;
	novoVertice->visitado = false;
	for (int i = 0; i < MAX_ARESTAS; i++){
		novoVertice->vizinhos[i] = NULL;
	}
	return novoVertice;
}

// Liga os v�rtices passados como par�metro
bool ligaVertices(VERTICE v1, VERTICE v2){
	int aux = 0;
	while(v1->vizinhos[aux] != NULL){ // Busca a primeira posi��o 'vazia'(NULL) dos vizinhos
		aux++;
	}
	v1->vizinhos[aux] = v2; // Adiciona o novo vizinho a lista de vizinhos
	aux = 0;
	while(v2->vizinhos[aux] != NULL){ // Busca a primeira posi��o 'vazia'(NULL) dos vizinhos
		aux++;
	}
	v2->vizinhos[aux] = v1; // Adiciona o novo vizinho a lista de vizinhos
	v1->nroVizinhos++; // Incrementa o n�mero de vizinhos
	v2->nroVizinhos++; // Incrementa o n�mero de vizinhos
}

/*
*	Busca em Profundidade - DFS - Depht First Search
*	Percorre primeiro todos os vizinhos que foram ligados primeiro ao v�rtice
*
*/
int buscaEmProfundidade(VERTICE inicio, VERTICE destino, int visitados){
	inicio->visitado = true; // Marca o V�rtice que est� passando inicio como j� visitado
	if( inicio == destino ) return visitados; // Se for o buscado (destino) retorna ele

	int aux = 0;
	while( inicio->vizinhos[aux] != NULL ){ // Enquanto existe vizinhos a serem visitados
		if( inicio->vizinhos[aux]->visitado == false ){ // Se o vizinho ainda n�o foi visitado
			// Chama recursivamente passando novo vizinho como ini�cio, ou seja, ir� percorrer todos os vizinhos dele, e assim, sucessivamente
			int resposta = buscaEmProfundidade(inicio->vizinhos[aux], destino, visitados+1);
			// Se o retorno for maior que -1 ent�o � porque encontrou, sendo assim, j� retorna a resposta
			if( resposta != -1 ) return resposta;
		}
		aux++; // Incrementa 1 na lista de vizinhos
	}

	return -1; // N�o encontrou o v�rtice
}

/*
*	Busca em Largura - BFS - Breadth First Search
*	Implementada com o conceito de fila, por�m utilizando um array simples
*	Assim ela n�o exclu� o 'v�rtice' do array, apenas pula uma posi��o para a frente
*	Percorre todos os v�rtices por n�vel
*/
int buscaEmLargura(VERTICE inicio, VERTICE destino){
	int iniFila = 0; // Vari�vel que controla a posi��o do inicio da fila, � utilizada para controlar o WHILE
	int tamFila = 1; // Vari�vel que controla o tamanho da fila

	VERTICE FILA[MAX_VERTICES]; // Fila que ir� guardar os v�rtices a serem comparados
	for (int i = 0; i < MAX_VERTICES; i++){ // Como a lista n�o � din�mica, ela precisa ser 'limpa' primeiro
		FILA[i] = NULL;
	}
	FILA[iniFila] = inicio; // Posi��o [0] da fila recebe o v�rtice de in�cio

	// Enquanto n�o terminar a fila fa�a
	while( iniFila < tamFila ){
		// Se o elemento que est� para 'sair' da fila for o buscado (destino) ent�o retorna iniFila, que foi a dist�ncia percorrida para encontrar
		if( FILA[iniFila] == destino ) return iniFila;

		/*
		*	Para todos os vizinhos do v�rtice que est� para 'sair' da fila:
		*	Marca todos como visitado, para n�o coloca-los na fila novamente,
		*	e ent�o os coloca na fila, e aumenta o tamanho da fila
		*/
		for (int i = 0; i < FILA[iniFila]->nroVizinhos; i++){
			if( FILA[iniFila]->vizinhos[i]->visitado == false ){
				FILA[iniFila]->vizinhos[i]->visitado = true;
				FILA[tamFila] = FILA[iniFila]->vizinhos[i];
				tamFila++;
			}
		}
		iniFila++; // Incrementa 1 no inicio da fila, como se tivesse exclu�do o primeiro que entrou na fila (FIFO - First In First Out)
	}
	return -1;
}

int main(){

	// Grafo conjunto de v�rtices independentes
	VERTICE A = criaVertice('A');
	VERTICE B = criaVertice('B');
	VERTICE C = criaVertice('C');
	VERTICE D = criaVertice('D');
	VERTICE E = criaVertice('E');
	VERTICE F = criaVertice('F');

	// Liga todos os v�rtices de acordo com o GRAFO apresentado na introdu��o
	ligaVertices(A, B);
	ligaVertices(A, C);
	ligaVertices(B, D);
	ligaVertices(C, D);
	ligaVertices(B, E);
	ligaVertices(D, E);
	ligaVertices(E, F);
	ligaVertices(D, F);

	// Realiza a busca em profundidade
	int res = buscaEmProfundidade(A, F, 0);
	if( res != -1 )
		printf("DFS - Encontrou. Distancia: %d.\n", res);
	else
		printf("DFS - N�o encontrou.\n");

	// 'Zera' todos os atributos 'visitado' de todos os v�rtices para 'false'
	A->visitado = false;
	B->visitado = false;
	C->visitado = false;
	D->visitado = false;
	E->visitado = false;
	F->visitado = false;

	// Realiza a busca em largura
	res = buscaEmLargura(A, F);
	if( res != -1 )
		printf("BFS - Encontrou. Distancia: %d.\n", res);
	else
		printf("BFS - N�o encontrou.\n");

    // Grafo conjunto de v�rtices em um array
	VERTICE GRAFO[MAX_VERTICES];
	GRAFO[0] = criaVertice('A');
	GRAFO[1] = criaVertice('B');
	GRAFO[2] = criaVertice('C');
	GRAFO[3] = criaVertice('D');
	GRAFO[4] = criaVertice('E');
	GRAFO[5] = criaVertice('F');

	// Liga todos os v�rtices de acordo com o GRAFO apresentado na introdu��o
	ligaVertices(GRAFO[0], GRAFO[1]);
	ligaVertices(GRAFO[0], GRAFO[2]);
	ligaVertices(GRAFO[1], GRAFO[3]);
	ligaVertices(GRAFO[2], GRAFO[3]);
	ligaVertices(GRAFO[1], GRAFO[4]);
	ligaVertices(GRAFO[3], GRAFO[4]);
	ligaVertices(GRAFO[4], GRAFO[5]);
	ligaVertices(GRAFO[3], GRAFO[5]);

	// Realiza a busca em profundidade
	res = buscaEmProfundidade(GRAFO[0], GRAFO[5], 0);
	if( res != -1 )
		printf("DFS - Encontrou. Distancia: %d.\n", res);
	else
		printf("DFS - N�o encontrou.\n");

	// 'Zera' todos os atributos 'visitado' de todos os v�rtices para 'false'
	for (int i = 0; i < MAX_VERTICES; i++){
		GRAFO[i]->visitado = false;
	}

	// Realiza a busca em largura
	res = buscaEmLargura(GRAFO[0], GRAFO[5]);
	if( res != -1 )
		printf("BFS - Encontrou. Distancia: %d.\n", res);
	else
		printf("BFS - N�o encontrou.\n");

	return 0;
}
