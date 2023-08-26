#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#include "Fun.h"


#define BRANCO 0 //vamos definir aqui as cores apenas para fim ditaticos
#define CINZA 1
#define PRETO 2


GRAFO *gerarGrafo (int v)
{
    int i;

    GRAFO *grafo = (GRAFO *)malloc(sizeof(GRAFO));
    grafo->vertices = v;
    grafo->arestas = 0;
    grafo->adj = (VERTICE *)malloc(v*sizeof(VERTICE));

    for (i=0; i<v; i++)
    {
        grafo->adj[i].cab=NULL;
    }
    return(grafo);
}



LADJACENCIA *criaAdjacencias(int v, int peso, char rotulovertice[])
{
    LADJACENCIA *aux = (LADJACENCIA *) malloc (sizeof(LADJACENCIA));
    aux->vertice =v;
    aux->peso = peso;
    aux->prox = NULL;
    strcpy(aux->rotulo, rotulovertice);
    return(aux);
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO peso, char rotulovertice[])
{
    if(!gr)
        return (false);
    if((vf<0)||(vf >= gr->vertices))
        return(false);
    if((vi<0)||(vf >= gr->vertices))
        return(false);



    LADJACENCIA *novo = criaAdjacencias(vf,peso,rotulovertice);
    novo->prox = gr->adj[vi].cab;
    gr->adj[vi].cab=novo;
    gr->arestas++;
    return (true);
}

void imprimeGrafo(GRAFO *gr)
{


    printf("Numero de Vertices: %d\nNumero de Arestas: %d\n",gr->vertices-1,gr->arestas/2);
    int i;

    for(i=0; i<gr->vertices; i++)
    {
        if(i!=0)
        {
            printf("v%d: ",i);
        }


        LADJACENCIA *ad = gr->adj[i].cab;
        while(ad)
        {
            printf("v%d(Peso: %d) Rotulo vertice: %s  ",ad->vertice,ad->peso,ad->rotulo);
            ad=ad->prox;
        }
        printf("\n");
    }
}



