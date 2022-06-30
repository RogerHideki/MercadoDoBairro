#include <stdio.h>
#include "Funcoesteste.h"
#include "Registrosteste.h"

void imprimirEstoqueProdutos(tProduto **produto, int tam) {
    int i;

    printf("Estoque de Produtos:\n");
    printf("--------------------------------\n");
    for (i = 0; i < tam; i++) {
        printf("%d - %s\t%s\t%lf\t%2d/%2d/%4d\t%d\n", produto[i]->codigo, produto[i]->setor, produto[i]->nome,
               produto[i]->preco, produto[i]->validade->dia, produto[i]->validade->mes, produto[i]->validade->ano,
               produto[i]->estoque);
    }
    printf("--------------------------------\n");
}