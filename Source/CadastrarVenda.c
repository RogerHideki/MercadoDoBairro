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
    int codigo = 1, cadastrado, existe, continuar;
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
        venda.quantidadeProdutos = 0;
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
        limpaTela();
        itensCompra.precoTotal = 0;
        do {
            printf("Código do produto: ");
            scanf(" %d", &itensCompra.codigoProduto);
            fProdutos = fopen("../Arquivos/Produtos.dat", "rb+");
            if (fProdutos) {
                existe = 0;
                while (existe == 0 && fread(&produto, sizeof(tProduto), 1, fProdutos)) {
                    if (itensCompra.codigoProduto == produto.codigo)
                        existe = 1;
                }
                if (existe == 1) {
                    if (produto.estoque > 0) {
                        printf("\n%s\tR$ %.2lf\t%d unidades\n\n", produto.nome, produto.preco, produto.estoque);
                        printf("Quantidade: ");
                        scanf(" %d", &itensCompra.quantidade);
                        if (itensCompra.quantidade <= produto.estoque) {
                            produto.estoque = produto.estoque - itensCompra.quantidade;
                            fseek(fProdutos, (produto.codigo - 1) * sizeof(tProduto), SEEK_SET);
                            fwrite(&produto, sizeof(tProduto), 1, fProdutos);
                            venda.quantidadeProdutos++;
                            itensCompra.precoUnitario = (float)produto.preco;
                            itensCompra.precoTotal += (itensCompra.precoUnitario * (float)itensCompra.quantidade);
                            limpaTela();
                        } else {
                            limpaTela();
                            printf("Não há quantidade disponível do produto\n\n");
                        }
                    } else {
                        limpaTela();
                        printf("Não há quantidade disponível do produto\n\n");
                    }
                } else {
                    limpaTela();
                    printf("Código inválido\n\n");
                }
                fclose(fProdutos);
            }
            printf("Digite 1 para continuar a compra, ou digite qualquer outro número para finalizar a compra: ");
            scanf(" %d", &continuar);
        } while (continuar == 1);
        venda.precoTotal = itensCompra.precoTotal;
        fClientes = fopen("../Arquivos/Cliente.dat", "rb+");
        if (fClientes) {
            cliente.pontos += (int)venda.precoTotal;
            fseek(fClientes, (cliente.codigo - 1) * sizeof(tCliente), SEEK_SET);
            fwrite(&cliente, sizeof(tCliente), 1, fClientes);
            fclose(fClientes);
        }
        fwrite(&venda, sizeof(tVenda), 1, fVendas);
        fclose(fVendas);
        limpaTela();
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
}