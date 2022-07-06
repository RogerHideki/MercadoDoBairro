#include <stdio.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

void cadastrarCliente(int cadastrado, tVenda venda) {
    tCliente cliente;
    int codigo = 1;
    FILE *fClientes = fopen("../Arquivos/Cliente.dat", "rb");

    if (fClientes) {
        while (fread(&cliente, sizeof(tCliente), 1, fClientes))
            codigo += 1;
        fclose(fClientes);
    }

    fClientes = fopen("../Arquivos/Cliente.dat", "ab");

    if (fClientes) {
        cliente.codigo = codigo;
        if (cadastrado == 0) {
            printf("CPF: ");
            scanf(" %[^\n]s", cliente.cpf);
        }
        else
            strcpy(cliente.cpf, venda.cpfCliente);
        printf("Nome: ");
        scanf(" %[^\n]s", cliente.nome);
        printf("Data de nascimento: ");
        scanf(" %d/%d/%d", &cliente.dataNascimento.dia, &cliente.dataNascimento.mes,
              &cliente.dataNascimento.ano);
        cliente.idade = idade(cliente);
        printf("Endereço: ");
        scanf(" %[^\n]s", cliente.endereco);
        printf("Cidade: ");
        scanf(" %[^\n]s", cliente.cidade);
        printf("Estado: ");
        scanf(" %[^\n]s", cliente.estado);
        cliente.pontos = 0;
        fwrite(&cliente, sizeof(tCliente), 1, fClientes);
        fclose(fClientes);
        limpaTela();
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
}