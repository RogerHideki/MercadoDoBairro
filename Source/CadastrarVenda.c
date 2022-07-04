#include <stdio.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

void cadastrarVenda() {
    tVenda venda;
    tCliente cliente;
    int codigo = 1, cadastrado = 0;
    FILE *fClientes;
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
        printf("Código do produto: ");
        scanf(" %[^\n]s", venda.cpfCliente);



        fwrite(&venda, sizeof(tVenda), 1, fVendas);
        fclose(fVendas);
        limpaTela();
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
}