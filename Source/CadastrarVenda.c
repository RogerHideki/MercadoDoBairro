#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

int cadastrarVenda(int codigoVenda) {
    tVenda venda;
    tCliente cliente;
    int codigo = 1, cpfCadastrado;
    FILE *fClientes;
    FILE *fVendas = fopen("../Arquivos/Vendas.dat", "ab");

    if (fVendas) {
        venda.codigo = codigoVenda;
        printf("CPF: ");
        scanf(" %[^\n]s", venda.cpfCliente);
        cpfCadastrado = 0;
        fClientes = fopen("../Arquivos/Cliente.dat", "rb");
        if (fClientes) {
            while (fread(&cliente, sizeof(tCliente), 1, fClientes)) {
                codigo += 1;
                if (strcmp(venda.cpfCliente, cliente.cpf) == 0)
                    cpfCadastrado = 1;
            }
            fclose(fClientes);
        }
        if (cpfCadastrado == 0){
            cpfCadastrado = 1;
            cadastrarCliente(codigo, cpfCadastrado);
        }
            


        fclose(fVendas);
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
    return 1;
}