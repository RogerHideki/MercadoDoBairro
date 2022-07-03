#include <stdio.h>
#include "Funcoes.h"
#include "Registros.h"

void clientesMais1000Pontos() {
    tCliente cliente;
    int i;
    FILE *fClientes;

    fClientes = fopen("../Arquivos/Cliente.dat", "rb");

    if (fClientes) {
        while (fread(&cliente, sizeof(tCliente), 1, fClientes)) {
            if (cliente.idade >= 18 && cliente.idade <= 25) {
                printf("%d", cliente.pontos);
            }
        }
        printf("Quantidade de clientes com idade entre 18 e 25 anos:\n");
        fclose(fClientes);
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
}