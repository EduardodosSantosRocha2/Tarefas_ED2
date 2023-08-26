#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct no{
    int dado;
    struct no *proximo;
}noptr;


noptr* cria_no(){
    noptr *novo;
    novo = (noptr*) malloc(sizeof(noptr));
    return novo;
}


void inserir_ordenado(noptr **lista, int num){
    noptr *novo = cria_no();
    noptr *aux;

    if(novo){
        novo->dado = num;

        if(*lista == NULL){ // a lista está vazia?
            novo->proximo = NULL;
            *lista = novo;
        }
        else if(novo->dado < (*lista)->dado){ // é o menor?
            novo->proximo = *lista;
            *lista = novo;
        }
        else{ // inserção no meio ou no final da lista
            aux = *lista;
            while(aux->proximo && novo->dado > aux->proximo->dado)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void imprimir(noptr *inicio){
    noptr *aux = inicio;
    if(inicio == NULL){
        printf("Lista vazia!!!\n");
    }

    while(aux){
       printf("[%d] ", aux->dado);
       aux = aux->proximo;
    }
    printf("\n");

}



int mdiv(int valor){
    double a= 0.6180339887;
    int pos = floor(5*fmod((valor * a),1));
    printf("Valor pos %d \n", pos);

    return pos;
}





int main()
{
    int vet[5],
    pos, pos1;
    noptr *inicio[5];
    inicio[0] = NULL;
    inicio[1] = NULL;
    inicio[2] = NULL;
    inicio[3] = NULL;
    inicio[4] = NULL;
    int valor = 1, escolha, valorBuscar;

    do
    {
        printf("-_-_-_-_-_-_-_-_--_--_--_--_--_-\n");
        printf("(0)Sair\n(1)Inserir No\n(2)Imprimir No\n");
        printf("-_-_-_-_-_-_-_-_--_--_--_--_--_-\n");
        printf("Digite a sua escolha: \n");
        scanf("%d", &escolha);
        switch(escolha)
        {

        case 0:
            break;

        case 1:
            valor = 1;
            while(valor !=0){
                printf("-_-_-_--_-_-_--_-_-_--_-_-_--_-_-_--_-_-_-\n");
                printf("Digite o valor ou 0 para sair: \n");
                scanf("%d",&valor);
                if(valor!=0){
                    pos = mdiv(valor);
                    inserir_ordenado(&inicio[pos], valor);
                }

            }
            break;
        case 2:
            for(int i=0; i<5; i++){
                printf("Lista %d", i);
                imprimir(inicio[i]);
            }
            break;



        default:
            printf("Erro!Digite novamente!!!");
        }



    }
    while(escolha!=0);

    return 0;
}
