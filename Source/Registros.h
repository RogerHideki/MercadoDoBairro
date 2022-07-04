//
// Created by Roger Hideki on 30/06/2022.
//

#ifndef MERCADODOBAIRRO_REGISTROS_H
#define MERCADODOBAIRRO_REGISTROS_H

typedef struct tData {
    int dia, mes, ano;
} tData;

typedef struct tVenda {
    int codigo, quantidadeProdutos;
    char cpfCliente[13];
    tData dataCompra;
    float precoTotal;
} tVenda;

typedef struct tCliente {
    char cpf[13], nome[50], endereco[50], cidade[50], estado[2];
    tData dataNascimento;
    int codigo, idade, pontos;
} tCliente;

typedef struct tProduto {
    int codigo, estoque;
    char setor[20], nome[50];
    double preco;
    tData validade;
} tProduto;

typedef struct tItensCompra {
    int codigoProduto, quantidade;
    float precoUnitario, precoTotal;
} tItensCompra;

#endif //MERCADODOBAIRRO_REGISTROS_H
