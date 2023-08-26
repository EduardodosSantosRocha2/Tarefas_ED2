#ifndef CABECALHO_H_INCLUDED
#define CABECALHO_H_INCLUDED

typedef struct Data
{
    int dia, mes, ano;

} data;

typedef struct Endereco
{
    char rua[30],cidade[30],estado[30];
    int numero;

} endereco;

typedef struct Cliente
{
    char cpf[30],nome[30],telefone[30];
    endereco ende;
    data dataNascimento;
    struct Cliente *prox;
    struct Cliente *ant;

} cliente;

typedef struct Produto
{
    char descricao[30];
    int codigo, quantEstoque;
    float precoUnitario;
    struct Produto *prox;
    struct Produto *ant;

} produto;

typedef struct Venda
{
    char cpfCliente[30];
    int codProd;
    int codVenda, quantComprada;
    struct Venda *prox;
    struct Venda *ant;

} venda;


// FUNÇÕES DO CLIENTE

void cadastrarC(cliente **inicio);
void alterarC(cliente **inicio, int op);
void consultarC(cliente **inicio);
void excluiC(cliente **inicio, venda **inicioV);
void listarC(cliente **inicio);

// FUNÇÕES DO PRODUTO

void cadastrarP(produto **inicio);
void alterarP(produto **inicio, int op);
void consultarP(produto **inicio);
void excluiP(produto **inicio, venda **inicioV);
void listarP(produto **inicio);

// FUNÇÕES DE VENDA
void cadastrarV(venda **inicio, cliente **inicioC, produto **inicioP);
void alterarV(venda **inicio, produto **inicioP);
void consultarV(venda **inicio);
void excluiV(venda **inicio);
void listarV(venda **inicio);

//DEMAIS FUNCOES

int compras(venda **inicioV, produto **inicioP);
void produtos(produto **inicio);
void cadastrarC(cliente **inicio);
void alterarC(cliente **inicio, int op);
void consultarC(cliente **inicio);
void excluiC(cliente **inicio, venda **inicioV);
void listarC(cliente **inicio);
void cadastrarP(produto **inicio);
void alterarP(produto **inicio, int op);
void consultarP(produto **inicio);
void excluiP(produto **inicio, venda **inicioV);
void listarP(produto **inicio);
void alterarV(venda **inicio, produto **inicioP);
void consultarV(venda **inicio);
void excluiV(venda **inicio);
void listarV(venda **inicio);


#endif // CABECALHO_H_INCLUDED
