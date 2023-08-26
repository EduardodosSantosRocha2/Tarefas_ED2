#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED
typedef int bool;
typedef int TIPOPESO;

typedef struct adjacencia {
    char rotulo[30];
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
}LADJACENCIA;

typedef struct vertice {
    LADJACENCIA *cab;
}VERTICE;

typedef struct grafo {

    int vertices;
    int arestas;
    VERTICE *adj;
}GRAFO;

GRAFO *criaGrafo (int v);

LADJACENCIA *criaAdj(int v, int peso, char rotulovertice[]);

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p, char rotulovertice[]);

void imprime(GRAFO *gr);

//void busca_em_largura (GRAFO *g, Vertex *r);

#endif // FUN_H_INCLUDED
