#include <stdio.h>
#include "Funcoes.h"
#include "Registros.h"

int cadastrarCliente(int codigo) {
    tCliente cliente;
    FILE *fClientes = fopen("../Arquivos/Cliente.dat", "ab");

    if (fClientes) {
        cliente.codigo = codigo;
        printf("CPF: ");
        scanf(" %[^\n]s", cliente.cpf);
        printf("Nome: ");
        scanf(" %[^\n]s", cliente.nome);
        printf("Data de nascimento: ");
        scanf(" %d/%d/%d", &cliente.dataNascimento.dia, &cliente.dataNascimento.mes,
              &cliente.dataNascimento.ano);
        cliente.idade = idade();
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
    return 1;
}