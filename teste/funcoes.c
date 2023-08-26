#include "cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void opCliente(int escolha, cliente **inicio,venda **inicioV)
{
    int op;
    switch (escolha)
    {
    case 1:
        printf("\nCadastrar: ");
        cadastrarC(&*inicio);
        break;
    case 2:
        printf("\nO que deseja alterar?");
        printf("\n1- Nome \n2- Telefone \n3- Endereco \n4 -Data \n0-Sair\n");
        scanf("%d",&op);
        if(op == 0)
        {
            printf("\nSaindo");
        }
        else
            alterarC(&*inicio,op);
        break;
    case 3:
        consultarC(&*inicio);
        break;
    case 4:
        excluiC(&*inicio,&*inicioV);
        break;
    case 5:
        listarC(&*inicio);
        break;
    default:
        printf("\nEscolha invalida");
        break;
    }
}



void opProduto(int escolha, produto **inicio,venda **inicioV)
{
    int op;
    switch (escolha)
    {
    case 1:
        printf("\nCadastrar: ");
        cadastrarP(&*inicio);
        break;
    case 2:
        printf("\nO que deseja alterar?");
        printf("\n1- Descricao \n2-Quantidade \n3-Preco \n0-Sair\n");
        scanf("%d",&op);
        if(op == 0)
        {
            printf("\nSaindo");
        }
        else
            alterarP(&*inicio,op);
        break;
    case 3:
        consultarP(&*inicio);
        break;
    case 4:
        excluiP(&*inicio,&*inicioV);
        break;
    case 5:
        listarP(&*inicio);
        break;
    default:
        printf("\nEscolha invalida");
        break;
    }
}

void cadastrarV(venda **inicio, cliente **inicioC, produto **inicioP)
{
    int cont = 0;
    venda *info, *p;
    cliente *pc;
    produto *pp;
    p = *inicio;
    pc = *inicioC;
    pp = *inicioP;
    info = (venda *)malloc(sizeof(venda));

    printf("\nCodigo da venda: ");
    scanf("%d", &info->codVenda);

    while (p)
    {
        if (info->codVenda == p->codVenda)
        {
            printf("\nCodigo ja cadastrado!");
            free(info);
            return;
        }
        else
            p = p->prox;
    }

    printf("\nCodigo do Produto: ");
    scanf("%d", &info->codProd);

    while (pp)
    {
        if (info->codProd == pp->codigo)
        {
            cont++;
            break;
        }
        else
            pp = pp->prox;
    }
    if (cont == 0)
    {
        printf("\nEsse produto nao existe, venda nao realizada");
        free(info);
        return;
    }

    cont = 0;
    printf("\nCpf do Cliente: ");
    fflush(stdin);
    gets(info->cpfCliente);

    while (pc)
    {
        if (strcmp(info->cpfCliente, pc->cpf) == 0)
        {
            cont++;
            break;
        }
        else
            pc = pc->prox;
    }

    if (cont == 0)
    {
        printf("\nEsse usuario nao existe, venda nao realizada");
        free(info);
        return;
    }

    printf("\nDigite a quantidade comprada: ");
    scanf("%d", &info->quantComprada);
    if ((pp->quantEstoque - info->quantComprada) < 0)
    {
        printf("\nEstoque negativo, impossivel fazer a venda;");
        free(info);
        return;
    }
    else
    {
        pp->quantEstoque = pp->quantEstoque - info->quantComprada;
    }

    info->ant = NULL;
    info->prox = *inicio;
    if (*inicio != NULL)
    {
        (*inicio)->ant = info;
    }
    *inicio = info;
}






void opVenda(int escolha, venda **inicio,cliente **inicioC,produto **inicioP)
{
    switch (escolha)
    {
    case 1:
        printf("\nCadastrar: ");
        cadastrarV(inicio,inicioC,inicioP);
        break;
    case 2:
        printf("\nAlterar a quantidade comprada");
        alterarV(&*inicio,&*inicioP);
        break;
    case 3:
        consultarV(&*inicio);
        break;
    case 4:
        excluiV(&*inicio);
        break;
    case 5:
        listarV(&*inicio);
        break;
    default:
        printf("\nEscolha invalida");
        break;
    }
}

// DEMAIS FUN��ES

int compras(venda **inicioV, produto **inicioP)
{
   // printf("chegou 1");
    venda *pv;
    produto *pp;
    pv=*inicioV;
    pp=*inicioP;
    float valor;
    printf("\nDigite o valor que deseja consultar: ");
    scanf("%f",&valor);

   // printf("chegou xxx");

  int quantidade = 0;

    while (pv) {
        while (pp) {
            printf("Produto: %d  CodigoVenda: %d\n", pv->codProd, pp->codigo);
            if (pv->codProd == pp->codigo) {
                float valorTotal = pv->quantComprada * pp->precoUnitario;
                printf("\t---------------------------------------\n");
                printf("\t Valor: %f\n", valor);
                printf("\t Valor Total: %f\n", valorTotal);
                printf("\t---------------------------------------\n");

                if (valorTotal > valor) {
                    quantidade++;
                }
            }
            pp = pp->prox;
        }
        pv = pv->prox;
    }

    return quantidade;

}

void produtos(produto **inicio)
{
    produto *p;
    p = *inicio;
    int valor;
    int controlador = 0;
    printf("\nDigite o valor que deseja consultar: ");
    scanf("%d",&valor);
    printf("\nProdutos quantidade inferior: \n");
    while(p)
    {
        if(p->quantEstoque < valor)
        {
            printf("\n--------------------------------------");
            printf("\n\tDescricao: %s", p->descricao);
            printf("\n\tDescricao: %s", p->descricao);
            printf("\n\tCodigo: %d", p->codigo);
            printf("\n\tQuantidade em estoque: %d",p->quantEstoque);
            printf("\n--------------------------------------\n");
            controlador++;
        }
        p=p->prox;
    }
    if(controlador == 0){
       printf("\n--------------------------------------");
       printf("\nNenhum produto encontrado");
       printf("\n--------------------------------------\n");
    }

}



//    CLIENTE

void cadastrarC(cliente **inicio)
{
    cliente *info, *p;
    p = *inicio;
    info = (struct cliente *)malloc(sizeof(cliente));

    printf("\nNome: ");
    fflush(stdin);
    gets(info->nome);
    printf("\nCpf: ");
    gets(info->cpf);

    while (p)
    {
        if (strcmp(p->cpf,info->cpf)==0)
        {
            printf("\nCpf ja cadastrado!");
            return;
        }
        else
            p = p->prox;
    }

    printf("\nTelefone: ");
    fflush(stdin);
    gets(info->telefone);

    printf("\nEndereco\n");

    printf("\nEstado: ");
    fflush(stdin);
    gets(info->ende.estado);

    printf("\nCidade: ");
    fflush(stdin);
    gets(info->ende.cidade);

    printf("\nRua: ");
    fflush(stdin);
    gets(info->ende.rua);

    printf("\nNumero: ");
    scanf("%d",&info->ende.numero);

    printf("\nData de Nascimento\n");

    printf("\nDia: ");
    scanf("%d", &info->dataNascimento.dia);

    printf("\nMes: ");
    scanf("%d", &info->dataNascimento.mes);

    printf("\nAno: ");
    scanf("%d", &info->dataNascimento.ano);

    info->ant = NULL;
    if (*inicio == NULL)
    {
        info->prox = NULL;
        info->ant = NULL;
        *inicio = info;
    }

    else
    {
        info->prox = *inicio;
        (*inicio)->ant = info;
        (*inicio) = info;
    }
}

void alterarC(cliente **inicio, int op)
{
    cliente *p;
    p = *inicio;

    char cpf[30];

    printf("\nDigite o CPF do cliente que deseja alterar: ");
    fflush(stdin);
    gets(cpf);

    while (p)
    {
        if (strcmp(cpf,p->cpf)==0)
        {
            if(op==1)
            {
                char nome[30];
                printf("\nNovo nome: ");
                fflush(stdin);
                gets(nome);
                strcpy(p->nome, nome);
                return;
            }
            else if(op==2)
            {
                char telefone[30];
                printf("\nNovo telefone: ");
                fflush(stdin);
                gets(telefone);
                strcpy(p->telefone, telefone);
                return;
            }
            else if(op==3)
            {
                char rua[30],cidade[30],estado[30];
                int numero;
                printf("\nNova Rua: ");
                fflush(stdin);
                gets(rua);
                strcpy(p->ende.rua, rua);
                printf("\nNovo Numero: ");
                scanf("%d",&numero);
                p->ende.numero=numero;
                printf("\nNova Cidade: ");
                fflush(stdin);
                gets(cidade);
                strcpy(p->ende.cidade, cidade);
                printf("\nNovo Estado: ");
                fflush(stdin);
                gets(estado);
                strcpy(p->ende.estado, estado);
                return;
            }
            else if(op==4)
            {
                int dia, mes, ano;
                printf("\nNovo dia: ");
                scanf("%d", &dia);
                p->dataNascimento.dia = dia;
                printf("\nNovo mes: ");
                scanf("%d", &mes);
                p->dataNascimento.mes = mes;
                printf("\nNovo ano: ");
                scanf("%d", &ano);
                p->dataNascimento.ano = ano;
                return;
            }
            else
            {
                printf("\nComando invalido");
                return;
            }
        }
        p = p->prox;
    }
    printf("\nEsse usuario nao existe");
}

void consultarC(cliente **inicio)
{
    cliente *p;
    p = *inicio;
    char cpf[30];

    if (*inicio == NULL)
    {
        printf("\nNao ha usuarios cadastrados");
        return;
    }

    printf("\n\nDigite o CPF do cliente desejado: \n");
    fflush(stdin);
    gets(cpf);
    while (p)
    {

        if (strcmp(cpf,p->cpf)==0)
        {
            printf("\nDados do cliente:\n");
            printf("\nNome: %s", p->nome);
            printf("\nCPF: %s", p->cpf);
            printf("\nEndereco do cliente:\n");
            printf("\nRua: %s", p->ende.rua);
            printf("\nNumero: %d",p->ende.numero);
            printf("\nCidade: %s", p->ende.cidade);
            printf("\nEstado: %s", p->ende.estado);
            printf("\nData de nascimento do cliente:\n");
            printf("\nDia: %d", p->dataNascimento.dia);
            printf("\nMes: %d", p->dataNascimento.mes);
            printf("\nAno: %d", p->dataNascimento.ano);
            return;
        }
        p = p->prox;
    }
    printf("\nEsse usuario nao existe");
}

void excluiC(cliente **inicio, venda **inicioV)
{
    venda *pv;
    cliente *p, *exc;
    p = *inicio;
    pv = *inicioV;

    char cpf[30];

    if (p == NULL)
    {
        printf("\nNenhum usuario cadastrado");
        return;
    }
    else
    {
        printf("\nDigite o CPF do cliente que deseja excluir: ");
        fflush(stdin);
        gets(cpf);

        while (pv)
        {
            if (strcmp(pv->cpfCliente,cpf)==0)
            {
                printf("\nEste cliente esta relacionado a uma venda, nao pode ser excluido");
                return;
            }
            pv = pv->prox;
        }


        while (p)
        {
            if (strcmp(p->cpf,cpf)==0)
            {
                if (p->ant == NULL && p->prox == NULL)
                {
                    exc = p;
                    free(exc);
                    printf("\nCliente excluido com sucesso");
                    return;
                }

                else if (p->ant == NULL)
                {
                    p->prox->ant = NULL;
                    exc = p;
                    free(exc);
                    printf("\nCliente excluido com sucesso");
                    return;
                }
                else
                {
                    p->ant->prox = p->prox;
                    p->prox->ant = p->ant;

                    exc = p;
                    free(exc);
                    printf("\nCliente excluido com sucesso");
                    return;
                }
            }
            p = p->prox;
        }

        printf("\nEsse usuario nao existe");
    }
}

void listarC(cliente **inicio)
{
    cliente *p;
    p= *inicio;
    printf("\nClientes Cadastrados: ");
    while (p)
    {
        printf("\nDados do cliente:\n");
        printf("\nNome: %s", p->nome);
        printf("\nCPF: %s", p->cpf);
        printf("\nEndereco do cliente:\n");
        printf("\nRua: %s", p->ende.rua);
        printf("\nNumero: %d",p->ende.numero);
        printf("\nCidade: %s", p->ende.cidade);
        printf("\nEstado: %s", p->ende.estado);
        printf("\nData de nascimento do cliente:\n");
        printf("\nDia: %d", p->dataNascimento.dia);
        printf("\nMes: %d", p->dataNascimento.mes);
        printf("\nAno: %d", p->dataNascimento.ano);
        p = p->prox;
    }
}

//     PRODUTO //////////


void cadastrarP(produto **inicio)
{
    produto *info, *p;
    p = *inicio;
    info = (struct produto *)malloc(sizeof(produto));

    printf("\nDescricao: ");
    fflush(stdin);
    gets(info->descricao);
    printf("\nCodigo: ");
    scanf("%d", &info->codigo);

    while (p)
    {
        if (info->codigo == p->codigo)
        {
            printf("\nCodigo ja cadastrado!");
            return;
        }
        else
            p = p->prox;
    }

    printf("\nQuantidade em estoque: ");
    scanf("%d",&info->quantEstoque);

    printf("\nPreco: ");
    scanf("%f",&info->precoUnitario);

    info->ant = NULL;
    if (*inicio == NULL)
    {
        info->prox = NULL;
        info->ant = NULL;
        *inicio = info;
    }

    else
    {
        info->prox = *inicio;
        (*inicio)->ant = info;
        (*inicio) = info;
    }
}

void alterarP(produto **inicio, int op)
{
    produto *p;
    p = *inicio;

    int codigo;

    printf("\nDigite o codigo do produto que deseja alterar: ");
    scanf("%d",&codigo);

    while (p)
    {
        if (codigo == p->codigo)
        {
            if(op==1)
            {
                char descricao[30];
                printf("\nNova descricao: ");
                fflush(stdin);
                gets(descricao);
                strcpy(p->descricao, descricao);
                return;
            }
            else if(op==2)
            {
                int quant;
                printf("\nNova quantidade: ");
                scanf("%d",&quant);
                p->quantEstoque=quant;
                return;
            }
            else if(op==3)
            {
                float preco;
                printf("\nNovo preco: ");
                scanf("%f",&preco);
                p->precoUnitario=preco;
                return;
            }
            else
            {
                printf("\nComando invalido");
                return;
            }
        }
        p = p->prox;
    }
    printf("\nEsse produto nao existe");
}

void consultarP(produto **inicio)
{
    produto *p;
    p = *inicio;
    int codigo;

    if (*inicio == NULL)
    {
        printf("\nNao ha produtos cadastrados");
        return;
    }

    printf("\nDigite o codigo do produto desejado: \n");
    scanf("%d",&codigo);
    while (p)
    {

        if (codigo == p->codigo)
        {
            printf("\nDados do produto:\n");
            printf("\nDescricao: %s", p->descricao);
            printf("\nCodigo: %d", p->codigo);
            printf("\nQuantidade em estoque: %d",p->quantEstoque);
            printf("\nPreco Unitario: %f", p->precoUnitario);
            return;
        }
        p = p->prox;
    }
    printf("\nEsse usuario nao existe");
}

void excluiP(produto **inicio, venda **inicioV)
{
    venda *pv;
    produto *p, *exc;
    p = *inicio;
    pv = *inicioV;

    int codigo;

    if (p == NULL)
    {
        printf("\nNenhum produto cadastrado");
        return;
    }
    else
    {
        printf("\nDigite o codigo do produto que deseja excluir: ");
        scanf("%d",&codigo);

        while (pv)
        {
            if (pv->codProd == codigo)
            {
                printf("\nEste produto esta relacionado a uma venda, nao pode ser excluido");
                return;
            }
            pv = pv->prox;
        }


        while (p)
        {
            if (codigo == p->codigo)
            {
                if (p->ant == NULL && p->prox == NULL)
                {
                    exc = p;
                    free(exc);
                    printf("\nProduto excluido com sucesso");
                    return;
                }

                else if (p->ant == NULL)
                {
                    p->prox->ant = NULL;
                    exc = p;
                    free(exc);
                    printf("\nProduto excluido com sucesso");
                    return;
                }
                else
                {
                    p->ant->prox = p->prox;
                    p->prox->ant = p->ant;

                    exc = p;
                    free(exc);
                    printf("\nProduto excluido com sucesso");
                    return;
                }
            }
            p = p->prox;
        }

        printf("\nEsse produto nao existe");
    }
}

void listarP(produto **inicio)
{
    produto *p;
    p= *inicio;
    printf("\nClientes Cadastrados: ");
    while (p)
    {
        printf("\nDados do produto:\n");
        printf("\nDescricao: %s", p->descricao);
        printf("\nCodigo: %d", p->codigo);
        printf("\nQuantidade em estoque: %d",p->quantEstoque);
        printf("\nPreco Unitario: %f", p->precoUnitario);
        p = p->prox;
    }
}

//  VENDAS




void alterarV(venda **inicio, produto **inicioP)
{
    venda *p;
    produto *pp;
    p = *inicio;
    pp = *inicioP;

    int codigo;

    printf("\nDigite o codigo da venda que deseja alterar: ");
    scanf("%d",&codigo);

    while (p)
    {
        if (codigo == p->codVenda)
        {
            int quantNova;
            printf("\nNova quantidade comprada: ");
            scanf("%d",&quantNova);
            if(quantNova <= p->quantComprada)
            {
                printf("\nQuantidade deve ser superior a antiga %d",&p->quantComprada);
                return;
            }
            while (pp)
            {
                if (p->codProd == pp->codigo)
                {
                    if((pp->quantEstoque - (p->quantComprada + quantNova)) < 0)
                    {
                        printf("\nEstoque negativo, impossivel fazer a venda;");
                        return;
                    }
                }
                else
                    pp = pp->prox;
            }
            p->quantComprada=p->quantComprada+quantNova;
            return;
        }
        p = p->prox;
    }
    printf("\nEssa venda nao foi feita");
}

void consultarV(venda **inicio)
{
    venda *p;
    p = *inicio;
    int codigo;

    if (*inicio == NULL)
    {
        printf("\nNao ha vendas cadastradas");
        return;
    }

    printf("\nDigite o codigo da venda desejada: \n");
    scanf("%d",&codigo);
    while (p)
    {

        if (codigo == p->codVenda)
        {
            printf("\nDados da venda:\n");
            printf("\nCodigo da venda: %d", p->codVenda);
            printf("\nCodigo do produto: %d",p->codProd);
            printf("\nCPF do cliente: %s",p->cpfCliente);
            printf("\nQuantidade comprada: %d",p->quantComprada);
            return;
        }
        p = p->prox;
    }
    printf("\nEsse usuario nao existe");
}

void excluiV(venda **inicio)
{
    venda *p, *exc;
    p = *inicio;

    int codigo;

    if (p == NULL)
    {
        printf("\nNenhuma venda cadastrada");
        return;
    }
    else
    {
        printf("\nDigite o codigo da venda que deseja excluir: ");
        scanf("%d",&codigo);
        while (p)
        {
            if (codigo == p->codVenda)
            {
                if (p->ant == NULL && p->prox == NULL)
                {
                    exc = p;
                    free(exc);
                    printf("\nVenda excluida com sucesso");
                    return;
                }

                else if (p->ant == NULL)
                {
                    p->prox->ant = NULL;
                    exc = p;
                    free(exc);
                    printf("\nVenda excluida com sucesso");
                    return;
                }
                else
                {
                    p->ant->prox = p->prox;
                    p->prox->ant = p->ant;

                    exc = p;
                    free(exc);
                    printf("\nVenda excluida com sucesso");
                    return;
                }
            }
            p = p->prox;
        }

        printf("\nEssa venda nao foi feita");
    }
}

void listarV(venda **inicio)
{
    venda *p;
    p= *inicio;
    printf("\nVendas Cadastradas: ");
    while (p)
    {
        printf("\nDados da venda:\n");
        printf("\nCodigo da venda: %d", p->codVenda);
        printf("\nCodigo do produto: %d",p->codProd);
        printf("\nCPF do cliente: %s",p->cpfCliente);
        printf("\nQuantidade comprada: %d",p->quantComprada);
        p = p->prox;
    }
}
