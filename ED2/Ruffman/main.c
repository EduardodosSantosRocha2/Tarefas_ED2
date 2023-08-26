#include <stdio.h>
#include <stdlib.h>
#define TAM 256
#include <locale.h>
#include <string.h>
#include <conio.h>
#include "Fun.h"

int main()
{
    system("color 2");
    No *arvore;
    Lista lista;
    int colunas;
    char **dicionario;
    char *codificado, *decodificado;

    unsigned char texto[] = "UFU ao contrário é UFU!";//unsigned armazena de 0 a 255 padrão as tabela ascii possibilitando acentuação
    unsigned int tabela_de_frequencia[TAM];
    setlocale(LC_ALL, "Portuguese_Brazil");

    //tabela_de_frequencia
    inicia_tabela_e_zera_tabela(tabela_de_frequencia);
    preenche_tabela_com_a_frequencia(texto, tabela_de_frequencia);
    imprime_tabela_de_frequencia(tabela_de_frequencia);
    //
    //Lista_encadeada_ordenada
       criar_lista(&lista);
       preencher_minha_lista(tabela_de_frequencia, &lista);
       imprimir_lista(&lista);
    //

    //Etapa 3
        arvore = montar_arvore(&lista);

        printf("\t==============================\n");
                printf("\nArvore de Huffman\n");
                imprimir_arvore(arvore, 0);


    //Etapa 4


        colunas = altura_arvore(arvore) + 1;
        dicionario = aloca_dicionario(colunas);
        gerar_dicionario(dicionario, arvore, "", colunas);
        printf("\t==============================\n");
                 imprime_dicionario(dicionario);
        printf("\t==============================\n");


    //Etapa 5 codificação
        codificado = codificar(dicionario, texto);
        printf("\nTexto codificado: %s\t\n", codificado);

    //Etapa 6 Decodificar
        decodificado = decodificar(codificado, arvore);
        printf("\n\tTexto decodificado: %s\n", decodificado);


    return 0;
}
