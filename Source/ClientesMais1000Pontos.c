#include <stdio.h>
#include "Funcoes.h"
#include "Registros.h"

void clientesMais1000Pontos() {
    tCliente cliente;
    FILE *fClientes;

    fClientes = fopen("../Arquivos/Cliente.dat", "rb");

    if (fClientes) {
        printf("Lista de Clientes com Mais de 1000 Pontos:\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&cliente, sizeof(tCliente), 1, fClientes)) {
            if (cliente.pontos > 1000) {
                printf("%d - %13s\t%50s\t%2d/%2d/%4d\t%d anos\t%50s\t%50s\t%2s\t%d pontos\n", cliente.codigo,
                       cliente.cpf, cliente.nome, cliente.dataNascimento.dia, cliente.dataNascimento.mes,
                       cliente.dataNascimento.ano, cliente.idade, cliente.endereco, cliente.cidade, cliente.estado,
                       cliente.pontos);
            }
        }
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        fclose(fClientes);
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
}