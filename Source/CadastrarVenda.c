#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Funcoes.h"
#include "Registros.h"

void cadastrarVenda() {
    tVenda venda;
    tCliente cliente;
    tProduto produto;
    tItensCompra itensCompra;
    int codigo = 1, cadastrado = 0;
    time_t t = time(NULL);
    struct tm dataAtual = *localtime(&t);
    FILE *fClientes;
    FILE *fProdutos;
    FILE *fVendas = fopen("../Arquivos/Vendas.dat", "rb");

    if (fVendas) {
    while (fread(&venda, sizeof(tVenda), 1, fVendas))
        codigo += 1;
    fclose(fVendas);
    }

    fVendas = fopen("../Arquivos/Vendas.dat", "ab");

    if (fVendas) {
        venda.codigo = codigo;
        printf("CPF: ");
        scanf(" %[^\n]s", venda.cpfCliente);
        cadastrado = 1;
        fClientes = fopen("../Arquivos/Cliente.dat", "rb");
        if (fClientes) {
            while (fread(&cliente, sizeof(tCliente), 1, fClientes) && cadastrado == 1) {
                if (strcmp(venda.cpfCliente, cliente.cpf) == 0)
                    cadastrado = 0;
            }
            fclose(fClientes);
        }
        if (cadastrado == 1)
            cadastrarCliente(cadastrado);
        venda.dataCompra.dia = dataAtual.tm_mday;
        venda.dataCompra.mes = dataAtual.tm_mon + 1;
        venda.dataCompra.ano = dataAtual.tm_year + 1900;
        do {
            printf("Código do produto: ");
            scanf(" %d", itensCompra.codigoProduto);
            fProdutos = fopen("../Arquivos/Produtos.dat", "rb");
            if (fProdutos) {
                while (fread(&produto, sizeof(tProduto), 1, fProdutos)) {
                    if(itensCompra.codigoProduto == produto.codigo))
                }
            }
        } while ();




        fwrite(&venda, sizeof(tVenda), 1, fVendas);
        fclose(fVendas);
        limpaTela();
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
}