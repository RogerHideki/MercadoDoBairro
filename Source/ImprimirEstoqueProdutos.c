#include <stdio.h>
#include "Funcoes.h"
#include "Registros.h"

void imprimirEstoqueProdutos(tProduto **produto, int codigo) {
    int i;

    printf("Estoque de Produtos:\n");
    printf("----------------------------------------------------------------\n");
    for (i = 0; i < codigo; i++) {
        printf("%d - %s\t%s\t%.2lf\t%2d/%2d/%4d\t%d\n", produto[i]->codigo, produto[i]->setor, produto[i]->nome,
               produto[i]->preco, produto[i]->validade.dia, produto[i]->validade.mes, produto[i]->validade.ano,
               produto[i]->estoque);
    }
    printf("----------------------------------------------------------------\n");
}