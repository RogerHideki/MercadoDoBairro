#include <stdio.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

void estoquePorSetor() {
    tProduto produto;
    int i;
    FILE *fProdutos;

    for (i = 0; i < 5; i++) {
        fProdutos = fopen("../Arquivos/Produtos.dat", "rb");

        //SEPARAÇÃO NA IMPRESSÃO DOS SETORES
        if (fProdutos) {
            printf("Estoque de Produtos do Setor ");
            if (i == 0)
                printf("Higiene e limpeza:\n");
            else if (i == 1)
                printf("Bebidas:\n");
            else if (i == 2)
                printf("Frios:\n");
            else if (i == 3)
                printf("Padaria:\n");
            else
                printf("Acougue:\n");
            printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            while (fread(&produto, sizeof(tProduto), 1, fProdutos)) {

                //IMPRESSÃO DO ESTOQUE DE SETORES
                if (i == 0 && strcmp(produto.setor, "Higiene e limpeza") == 0) {
                    printf("%d - %20s\t%50s\tR$ %.2lf\t%2d/%2d/%4d\t%d unidades\n", produto.codigo, produto.setor,
                           produto.nome, produto.preco, produto.validade.dia, produto.validade.mes,
                           produto.validade.ano, produto.estoque);
                } else if (i == 1 && strcmp(produto.setor, "Bebidas") == 0) {
                    printf("%d - %20s\t%50s\tR$ %.2lf\t%2d/%2d/%4d\t%d unidades\n", produto.codigo, produto.setor,
                           produto.nome, produto.preco, produto.validade.dia, produto.validade.mes,
                           produto.validade.ano, produto.estoque);
                } else if (i == 2 && strcmp(produto.setor, "Frios") == 0) {
                    printf("%d - %20s\t%50s\tR$ %.2lf\t%2d/%2d/%4d\t%d unidades\n", produto.codigo, produto.setor,
                           produto.nome, produto.preco, produto.validade.dia, produto.validade.mes,
                           produto.validade.ano, produto.estoque);
                } else if (i == 3 && strcmp(produto.setor, "Padaria") == 0) {
                    printf("%d - %20s\t%50s\tR$ %.2lf\t%2d/%2d/%4d\t%d unidades\n", produto.codigo, produto.setor,
                           produto.nome, produto.preco, produto.validade.dia, produto.validade.mes,
                           produto.validade.ano, produto.estoque);
                } else if (i == 4 && strcmp(produto.setor, "Acougue") == 0) {
                    printf("%d - %20s\t%50s\tR$ %.2lf\t%2d/%2d/%4d\t%d unidades\n", produto.codigo, produto.setor,
                           produto.nome, produto.preco, produto.validade.dia, produto.validade.mes,
                           produto.validade.ano, produto.estoque);
                }
            }
            printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
            fclose(fProdutos);
        } else {
            limpaTela();
            printf("Erro ao abrir arquivo\n\n");
        }
    }
}