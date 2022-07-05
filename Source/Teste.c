#include <stdio.h>
#include "Registros.h"

int main() {
    tVenda venda;
    FILE *fVendas = fopen("../Arquivos/Vendas.dat", "rb+");

    if (fVendas) {
        printf("Lista de Clientes:\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&venda, sizeof(tVenda), 1, fVendas)) {
            printf("%d - %13s\t%2d/%2d/%4d\tR$ %.2f\t%d produtos\n", venda.codigo, venda.cpfCliente,
                   venda.dataCompra.dia, venda.dataCompra.mes, venda.dataCompra.ano, venda.precoTotal,
                   venda.quantidadeProdutos);
        }
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        fclose(fVendas);
    }
}