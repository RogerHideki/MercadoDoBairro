#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

void cadastrarProduto(tProduto produto, int codigo) {
    int quantidadeCadastros;
    bool valido;
    tProduto *novo = malloc(sizeof(tProduto));

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

    for (codigo = 0; codigo < quantidadeCadastros; codigo++) {
        produto[codigo].codigo = codigo + 1;
        valido = false;
        while (!valido) {
            printf("Setor: ");
            scanf(" %[^\n]s", produto[codigo].setor);
            if (strcmp(produto[codigo].setor, "Higiene e limpeza") == 0 ||
                strcmp(produto[codigo].setor, "Bebidas") == 0 ||
                strcmp(produto[codigo].setor, "Frios") == 0 || strcmp(produto[codigo].setor, "Padaria") == 0 ||
                strcmp(produto[codigo].setor, "Açougue") == 0) {
                valido = true;
            } else {
                printf("\nSetor inválido, digite um setor válido\n\n");
            }
        }
        printf("Nome: ");
        scanf(" %[^\n]s", produto[codigo].nome);
        printf("Preço: ");
        scanf(" %lf", &produto[codigo].preco);
        printf("Data de validade (dd/mm/aaaa): ");
        scanf(" %d/%d/%d", &produto[codigo].validade->dia, &produto[codigo].validade->mes,
              &produto[codigo].validade->ano);
        valido = false;
        while (!valido) {
            printf("Quantidade em estoque: ");
            scanf(" %d", &produto[codigo].estoque);
            if (produto[codigo].estoque >= 0) {
                valido = true;
            } else {
                printf("\nQuantidade inválida, digite uma quantidade válida\n\n");
            }
        }
        limpaTela();
    }
}
