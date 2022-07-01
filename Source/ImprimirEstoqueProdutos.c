#include <stdio.h>
#include "Funcoes.h"
#include "Registros.h"

void imprimirEstoqueProdutos(char arquivoProdutos[]) {
    tProduto produto;
    FILE *fProdutos = fopen(arquivoProdutos, "rb");

    if (fProdutos) {
        printf("Estoque de Produtos:\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
        while (!feof(fProdutos)) {
            if (fread(&produto, sizeof(tProduto), 1, fProdutos)) {
                printf("%d - %20s\t%50s\tR$ %.2lf\t%2d/%2d/%4d\t%d unidades\n", produto.codigo, produto.setor,
                       produto.nome, produto.preco, produto.validade.dia, produto.validade.mes, produto.validade.ano,
                       produto.estoque);
            }
        }
        printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
        fclose(fProdutos);
    } else
        printf("Erro ao abrir arquivo\n");
}