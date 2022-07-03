#include <stdio.h>
#include "Funcoes.h"
#include "Registros.h"

void estoqueBaixo() {
    tProduto produto;
    FILE *fProdutos = fopen("../Arquivos/Produtos.dat", "rb");

    if (fProdutos) {
        printf("Produtos com estoque abaixo de 5 unidades:\n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&produto, sizeof(tProduto), 1, fProdutos)) {
            if (produto.estoque < 5) {
                printf("%d - %20s\t%50s\tR$ %.2lf\t%2d/%2d/%4d\t%d unidades\n", produto.codigo, produto.setor,
                       produto.nome, produto.preco, produto.validade.dia, produto.validade.mes, produto.validade.ano,
                       produto.estoque);
            }
        }
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        fclose(fProdutos);
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
}