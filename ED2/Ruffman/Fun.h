#ifndef FUN_H_INCLUDED
#define FUN_H_INCLUDED

typedef struct no{
    unsigned char caracter;
    int frequencia_caracter;
    struct no *esq, *dir,*proximo;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;


void inicia_tabela_e_zera_tabela(unsigned int tabela[]);

void preenche_tabela_com_a_frequencia(unsigned char texto[], unsigned int tab[]);

void imprime_tabela_de_frequencia(unsigned int tab[]);


void criar_lista(Lista *lista);
void inserir_ordenado(Lista *lista, No *no);

void preencher_minha_lista( unsigned int tab[], Lista *lista);

void imprimir_lista(Lista *lista);

No* remove_no_inicial_da_lista(Lista *lista);

No* montar_arvore(Lista *lista);


void imprimir_arvore(No *raiz, int tam);

//dicionario Etapa 4

int altura_arvore(No *raiz);

char** aloca_dicionario(int colunas);

void gerar_dicionario(char **dicionario, No *raiz, char *caminho, int colunas);

void imprime_dicionario(char **dicionario);
//Etapa 5 Codificar

int calcula_tamanho_string(char **dicionoario, unsigned char *texto);

char* codificar(char **dicionario, unsigned char *texto);

//Etapa 6 Decofificar

char* decodificar(unsigned char texto[], No *raiz);



#endif // FUN_H_INCLUDED
