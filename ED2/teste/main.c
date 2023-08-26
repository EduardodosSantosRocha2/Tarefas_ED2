#include "cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    cliente *inicioC = NULL;
    produto *inicioP = NULL;
    venda *inicioV = NULL;
    int escolha;


    do
    {
        printf("\nMENU\n");
        printf("\nESCOLHA UMA OPCAO\n");
        printf("\n1- Cliente \n2- Produto \n3- Vendas \n4- Consultar quantidade de vendas com valor superior \n5- Consultar produtos com quantidade menor a um valor \n0- Sair");
        printf("\nFaca uma escolha: ");
        scanf("%d",&escolha);
        switch (escolha)
        {
        case 1:
            printf("\nO que fazer com Cliente?\n");
            printf("\n1 Cadastrar \n2 Alterar \n3 Consultar \n4 Remover \n5 Listar\n");
            printf("\nFaca uma escolha: ");
            scanf("%d",&escolha);
            opCliente(escolha,&inicioC,&inicioV);
            break;
        case 2:
            printf("\nO que fazer com Produto?\n");
            printf("\n1 Cadastrar \n2 Alterar \n3 Consultar \n4 Remover \n5 Listar\n");
            printf("\nFaca uma escolha: ");
            scanf("%d",&escolha);
            opProduto(escolha,&inicioP,&inicioV);
            break;
        case 3:
            printf("\nO que fazer com Vendas?\n");
            printf("\n1 Cadastrar \n2 Alterar \n3 Consultar \n4 Remover \n5 Listar\n");
            printf("\nFaca uma escolha: ");
            scanf("%d",&escolha);
            opVenda(escolha,&inicioV,&inicioC,&inicioP);
            break;
        case 4:
            printf("\nQuantidade de vendas com valor maior: %d",compras(&inicioV,&inicioP));
            break;
        case 5:
           produtos(&inicioP);
            break;
        case 0:
            printf("\nFechando...");
            break;
        default:
            printf("\nComando invalido");
            break;
        }
    }
    while(escolha != 0);
}

