#include <stdio.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

int cadastrarVenda(int codigo) {
    tVenda venda;
    FILE *fClientes;
    FILE *fVendas = fopen("../Arquivos/Vendas.dat", "ab");

    if (fVendas) {
        venda.codigo = codigo;
        fClientes = fopen("../Arquivos/Cliente.dat", "rb");
        if (fClientes) {
            strcmp();
        }

        fwrite(&venda, sizeof(tVenda), 1, fVendas);
        fclose(fVendas);
        limpaTela();
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
    return 1;
}