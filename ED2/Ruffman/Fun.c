#include <stdio.h>
#include <stdlib.h>
#define TAM 256
#include <locale.h>
#include <string.h>
#include <conio.h>
#include "Fun.h"




void inicia_tabela_e_zera_tabela(unsigned int tabela[]){
    int i;
    for(i=0;i<TAM;i++){
        tabela[i]=0;
    }

}

void preenche_tabela_com_a_frequencia(unsigned char texto[], unsigned int tab[]){
    int i = 0;

    while(texto[i]!='\0'){
        tab[texto[i]]++; //acessa o numero do caracter de texto
        i++;
    }

}

void imprime_tabela_de_frequencia(unsigned int tab[]){
    printf("\t==============================\n");
    printf("\t\tTABELA DE FREQUENCIA\n");
    for(int i=0; i<TAM; i++){
        if(tab[i]>0){
             if(i == 32){
                printf("\t\t%d = %u = espace\n",i,tab[i]);
             }
             else{
                printf("\t\t%d = %u = %c\n",i,tab[i],i);
             }

        }

    }
    printf("\t==============================\n");
}

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;


}

void inserir_ordenado(Lista *lista, No *no){
    No *aux;

    if(lista->inicio == NULL){
        lista->inicio = no;
    }

    //frequencia menor que o inicio da lista
    else if(no->frequencia_caracter < lista->inicio->frequencia_caracter){
        no->proximo = lista->inicio;
        lista->inicio = no;
    }
    else{
        aux = lista->inicio;
        while(aux->proximo!=NULL && aux->proximo->frequencia_caracter <= no->frequencia_caracter)
             aux = aux->proximo;
        no->proximo = aux->proximo;
        aux->proximo = no;
    }
     lista->tam++;
}

void preencher_minha_lista( unsigned int tab[], Lista *lista){
     int i;
     No *novo;
     for(int i=0; i<TAM; i++){
         if(tab[i]>0){
            novo = malloc(sizeof(No));
            if(novo){
                novo->caracter = i;
                novo->frequencia_caracter = tab[i];
                novo->dir = NULL;
                novo->esq = NULL;
                novo->proximo = NULL;
                inserir_ordenado(lista, novo);//manda o no criado
            }

            else{
                printf("Erro ao alocar memoria\n");
                break;
            }
         }
     }
}

void imprimir_lista(Lista *lista){
    No *aux = lista->inicio;

    printf("\n\tLista ordenada: Tamanho: %d\n", lista->tam);
    while(aux){
        printf("\t\tCaracter: %c Frequencia: %d\n", aux->caracter, aux->frequencia_caracter);
        aux = aux->proximo;
    }
}

No* remove_no_inicial_da_lista(Lista *lista){
    No *aux = NULL;

    if(lista->inicio!=NULL)
    {
        aux = lista->inicio;
        lista->inicio = aux->proximo;
        aux->proximo = NULL;
        lista->tam--;
    }

    return aux;

}

No* montar_arvore(Lista *lista){
    No *primeiro, *segundo, *novo;
    while(lista->tam > 1){
        primeiro = remove_no_inicial_da_lista(lista);
        segundo = remove_no_inicial_da_lista(lista);
        novo = malloc(sizeof(No));

        if(novo){
            novo->caracter = '+';
            novo->frequencia_caracter = primeiro->frequencia_caracter + segundo->frequencia_caracter;
            novo->esq = primeiro;
            novo->dir = segundo;
            novo->proximo = NULL;

            inserir_ordenado(lista, novo);
        }
        else{
            printf("\n\tERRO ao alocar memoria na arvore!\n");
            break;
        }
    }
    return lista->inicio;
}


void imprimir_arvore(No *raiz, int tam){
    if(raiz->esq == NULL && raiz->dir == NULL)
        printf("\tFolha: %c\tAltura: %d\n", raiz->caracter, tam);
    else{
        imprimir_arvore(raiz->esq, tam + 1);
        imprimir_arvore(raiz->dir, tam + 1);
    }
}



//dicionario Etapa 4

int altura_arvore(No *raiz){
    int esq, dir;

    if(raiz == NULL)
        return -1;
    else{
        esq = altura_arvore(raiz->esq) + 1;
        dir = altura_arvore(raiz->dir) + 1;

        if(esq > dir)
            return esq;
        else
            return dir;
    }
}

char** aloca_dicionario(int colunas){
    char **dicionario;
    int i;

    dicionario = malloc(sizeof(char*) * TAM);

    for(i = 0; i < TAM; i++)
        dicionario[i] = calloc(colunas, sizeof(char)); //limpa a memoria

    return dicionario;
}

void gerar_dicionario(char **dicionario, No *raiz, char *caminho, int colunas){ //colunas tamanho da matriz
    char esquerda[colunas], direita[colunas];

    if(raiz->esq == NULL && raiz->dir == NULL)
        strcpy(dicionario[raiz->caracter], caminho);
    else{
        strcpy(esquerda, caminho);
        strcpy(direita, caminho);

        strcat(esquerda, "0");//concatena duas strings
        strcat(direita, "1");

        gerar_dicionario(dicionario, raiz->esq, esquerda, colunas);
        gerar_dicionario(dicionario, raiz->dir, direita, colunas);
    }
}

void imprime_dicionario(char **dicionario){
    int i;

    printf("\n\t\tDicionario:\n");
    for(i = 0; i < TAM; i++){
        if(strlen(dicionario[i]) > 0)
            printf("\t\t%3d: %s\n", i, dicionario[i]);
    }
}
//Etapa 5 Codificar

int calcula_tamanho_string(char **dicionoario, unsigned char *texto){ //quanto caracteres para texto codificado?
    int i = 0, tam = 0;
    while(texto[i] != '\0'){
        tam = tam + strlen(dicionoario[texto[i]]);//tamanho da string
        i++;
    }
    return tam + 1;//considerando caracter '\0' fim de string
}

char* codificar(char **dicionario, unsigned char *texto){

    int i = 0, tam = calcula_tamanho_string(dicionario, texto);
    char *codigo = calloc(tam, sizeof(char));

    while(texto[i] != '\0'){
        strcat(codigo, dicionario[texto[i]]);//concatena a string
        i++;
    }
    return codigo;
}

//Etapa 6 Decofificar

char* decodificar(unsigned char texto[], No *raiz){
    int i = 0;
    No *aux = raiz;
    char temp[2];
    char *decodificado = calloc(strlen(texto), sizeof(char));

    while(texto[i] != '\0'){
        if(texto[i] == '0')
            aux = aux->esq;
        else
            aux = aux->dir;

        if(aux->esq == NULL && aux->dir == NULL){
            temp[0] = aux->caracter;
            temp[1] = '\0';
            strcat(decodificado, temp);
            aux = raiz;
        }

        i++;
    }
    return decodificado;
}
