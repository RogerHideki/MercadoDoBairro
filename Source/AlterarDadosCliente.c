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
            printf("%d - %13s\t%50s\t%2d/%2d/%4d\t%d anos\t\n", cliente.codigo, cliente.cpf, cliente.nome,
                   cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano, cliente.idade,
                   cliente.endereco, cliente.cidade, cliente.estado, cliente.pontos);
        }
        printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

        printf("\nDigite o código do cliente que deseja alterar: ");
        scanf(" %d", &opcao);
        opcao--;
        limpaTela();

        if (opcao >= 0 && opcao < cliente.codigo) {
            cliente.codigo = opcao + 1;
            valido = false;
            while (!valido) {
                printf("Setor: ");
                scanf(" %[^\n]s", cliente.setor);
                if (strcmp(cliente.setor, "Higiene e limpeza") == 0 ||
                    strcmp(cliente.setor, "Bebidas") == 0 ||
                    strcmp(cliente.setor, "Frios") == 0 || strcmp(cliente.setor, "Padaria") == 0 ||
                    strcmp(cliente.setor, "Açougue") == 0) {
                    valido = true;
                } else {
                    printf("\nSetor inválido, digite um setor válido\n\n");
                }
            }
            printf("Nome: ");
            scanf(" %[^\n]s", cliente.nome);
            printf("Preço: ");
            scanf(" %lf", &cliente.preco);
            printf("Data de validade (dd/mm/aaaa): ");
            scanf(" %d/%d/%d", &cliente.validade.dia, &cliente.validade.mes,
                  &cliente.validade.ano);
            valido = false;
            while (!valido) {
                printf("Quantidade em estoque: ");
                scanf(" %d", &cliente.estoque);
                if (cliente.estoque >= 0) {
                    valido = true;
                } else {
                    printf("\nQuantidade inválida, digite uma quantidade válida\n\n");
                }
            }
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