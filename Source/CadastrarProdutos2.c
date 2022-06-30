#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

int cadastrarProduto() {
    int quantidadeCadastros, tam, codigo = 0;
    bool valido;
    tProduto *produto = malloc(sizeof(tProduto));

    valido = false;
    while (!valido) {
        printf("Quantidade de cadastros:");
        scanf(" %d", &quantidadeCadastros);
        if (quantidadeCadastros > 0) {
            valido = true;
        } else {
            limpaTela();
            printf("Quantidade inválida, digite uma quantidade válida\n\n");
        }
    }

    tam = codigo + quantidadeCadastros;
    for (codigo; tam; codigo++) {
        produto->codigo = codigo + 1;
        valido = false;
        while (!valido) {
            printf("Setor: ");
            scanf(" %[^\n]s", produto->setor);
            if (strcmp(produto->setor, "Higiene e limpeza") == 0 || strcmp(produto->setor, "Bebidas") == 0 ||
                strcmp(produto->setor, "Frios") == 0 || strcmp(produto->setor, "Padaria") == 0 ||
                strcmp(produto->setor, "Açougue") == 0) {
                valido = true;
            } else {
                printf("\nSetor inválido, digite um setor válido\n\n");
            }
        }
        
    }
}
