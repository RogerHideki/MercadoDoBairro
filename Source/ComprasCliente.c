#include <stdio.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

void comprasCliente() {
    tCliente cliente;
    tVenda venda;
    char cpf[13];
    int cadastrado;
    FILE *fClientes;
    FILE *fVendas;

    printf("CPF: ");
    scanf(" %[^\n]s", cpf);
    limpaTela();
    cadastrado = 0;
    fClientes = fopen("../Arquivos/Cliente.dat", "rb");
    if (fClientes) {
        while (fread(&cliente, sizeof(tCliente), 1, fClientes) && cadastrado == 0) {
            if (strcmp(cpf, cliente.cpf) == 0)
                cadastrado = 1;
        }
        fclose(fClientes);
    }
    if (cadastrado == 1) {
        fVendas = fopen("../Arquivos/Vendas.dat", "rb");

        if (fVendas) {
            printf("Compras do Cliente:\n");
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            while (fread(&venda, sizeof(tVenda), 1, fVendas)) {
                if (strcmp(cpf, venda.cpfCliente) == 0) {
                    printf("%2d/%2d/%4d\tR$ %.2f\t%d produtos\n", venda.dataCompra.dia, venda.dataCompra.mes,
                           venda.dataCompra.ano, venda.precoTotal, venda.quantidadeProdutos);
                }
            }
            printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
            fclose(fClientes);
        } else
            printf("Nenhuma compra foi realizada\n\n");
    } else
        printf("Cliente não cadastrado\n\n");
}