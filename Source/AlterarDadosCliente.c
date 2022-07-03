#include <stdio.h>
#include "Funcoes.h"
#include "Registros.h"

void alterarDadosCliente() {
    tCliente cliente;
    int opcao;
    FILE *fClientes = fopen("../Arquivos/Cliente.dat", "rb+");

    if (fClientes) {
        printf("Lista de Clientes:\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&cliente, sizeof(tCliente), 1, fClientes)) {
            printf("%d - %13s\t%50s\t%2d/%2d/%4d\t%d anos\t%50s\t%50s\t%2s\t%d pontos\n", cliente.codigo, cliente.cpf,
                   cliente.nome, cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano,
                   cliente.idade, cliente.endereco, cliente.cidade, cliente.estado, cliente.pontos);
        }
        printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

        printf("\nDigite o código do cliente que deseja alterar: ");
        scanf(" %d", &opcao);
        opcao--;
        limpaTela();

        if (opcao >= 0 && opcao < cliente.codigo) {
            cliente.codigo = opcao + 1;

            fseek(fClientes, opcao * sizeof(tCliente), SEEK_SET);
            fwrite(&produto, sizeof(tCliente), 1, fClientes);
            limpaTela();
        } else {
            limpaTela();
            printf("Código inválido\n\n");
        }
        fclose(fClientes);
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
}