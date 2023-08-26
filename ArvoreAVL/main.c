#include <conio.h>
#include <stdlib.h>
typedef struct noAVL
{
    int dado;
    int bal;
    struct noAVL *esq;
    struct noAVL *dir;
}AVL;



int Inserir(int val, AVL **raiz)
{
    if (*raiz == NULL)
    {
        AVL *novo;
        novo = (AVL *) malloc(sizeof(AVL));
        novo->dado = val;
        novo->bal = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz=novo;
        return 0;
    }
    else if (val < (*raiz)->dado)
    {
        if (Inserir(val, &(*raiz)->esq)==0)
        {
            switch ((*raiz)->bal)
            {
            case -1:
                (*raiz)->bal = 0;
                return 1;
                break;
            case 0:
                (*raiz)->bal = 1;
                return 0;
                break;
            case 1:
                if ((*raiz)->esq->bal == 1)RotacaoSimplesADireita(&(*raiz));
                else RotacaoDuplaADireita(&(*raiz));
                return 1;
                break;
            }
        }
    }




    else
    {
        if (Inserir(val, &(*raiz)->dir)==0)
        {
            switch ((*raiz)->bal)
            {
            case -1:
                if ((*raiz)->dir->bal == -1)RotacaoSimplesAEsquerda(&(*raiz));
                else RotacaoDuplaAEsquerda(&(*raiz));
                return 1;
            case 0:
                (*raiz)->bal = -1;
                return 0;
            case 1:
                (*raiz)->bal = 0;
                return 1;
            }
        }
    }
    return 0;
}





void RotacaoSimplesADireita(AVL **raiz)
{
    AVL *ne = (*raiz)->esq;
    (*raiz)->esq = ne->dir;
    ne->dir = *raiz;
    ne->bal = (*raiz)->bal = 0;
    *raiz = ne;
}
void RotacaoSimplesAEsquerda(AVL **raiz)
{
    AVL *nd = (*raiz)->dir;
    (*raiz)->dir = nd->esq;
    nd->esq = *raiz;
    nd->bal = (*raiz)->bal = 0;
    *raiz = nd;
}

void RotacaoDuplaADireita(AVL **raiz)
{
    AVL *ne = (*raiz)->esq;
    AVL *ned = ne->dir;
    (*raiz)->esq = ned->dir;
    ne->dir = ned->esq;
    ned->esq = ne;
    ned->dir = *raiz;
    if (ned->bal == 1)
    {
        (*raiz)->bal = 0;
        ne->bal = -1;
    }
    else if (ned->bal == 1)
    {
        (*raiz)->bal = 0;
        ne->bal = -1;
    }
    else if (ned->bal == 0)
    {
        (*raiz)->bal = 0;
        ne->bal = 0;
    }
    else
    {
        (*raiz)->bal = 0;
        ne->bal = 1;
    }
    ned->bal = 0;
    *raiz = ned;
}


void mostra(AVL *raiz)
{
    if(raiz==NULL)
        return;
    printf("valor do no: %d ( %d )\n",raiz->dado,raiz->bal);
    printf("esq:%p - no:%p - dir:%p\n\n", raiz->esq,raiz,raiz->dir);
    mostra(raiz->esq);
    mostra(raiz->dir);

}

           void RotacaoDuplaAEsquerda(AVL **raiz)
    {
        AVL *nd = (*raiz)->dir;
        AVL *nde = nd->esq;
        (*raiz)->dir = nde->esq;
        nd->esq = nde->dir;
        nde->dir = nd;
        nde->esq = *raiz;
        if (nde->bal == 1)
        {
            (*raiz)->bal = 0;
            nd->bal = -1;
        }
        else if (nde->bal == 0)
        {
            (*raiz)->bal = 0;
            nd->bal = 0;
        }
        else
        {
            (*raiz)->bal = 1;
            nd->bal = 0;
        }
        nde->bal = 0;
        *raiz = nde;
    }

    int main(void)
    {
        AVL *raiz1 = NULL;
        int valor=0;
        do
        {
            printf("\nDigite um numero : ");
            scanf("%d",&valor);
            if(valor!=0)Inserir(valor,&raiz1);
        }
        while(valor!=0);
        mostra(raiz1);
        getch();
        return 0;
    }
