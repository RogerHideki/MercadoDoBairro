#include <stdio.h>
#include "Funcoes.h"
#include "Registros.h"

void quantidadeClientesIdadeEntre18E25() {
    tCliente cliente;
    int i = 0;
    FILE *fClientes;

    fClientes = fopen("../Arquivos/Cliente.dat", "rb");

    if (fClientes) {
        while (fread(&cliente, sizeof(tCliente), 1, fClientes)) {
            if (cliente.idade >= 18 && cliente.idade <= 25)
                i++;
        }
        printf("Quantidade de clientes com idade entre 18 e 25 anos: %d clientes\n\n", i);
        fclose(fClientes);
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
}