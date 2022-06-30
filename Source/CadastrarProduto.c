#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

int cadastrarProduto(tProduto **produto, int codigo) {
    int quantidadeCadastros, i, tam;
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
    tam = codigo + quantidadeCadastros;
    for (i = codigo; i < tam; i++) {
        novo->codigo = i + 1;
        valido = false;
        while (!valido) {
            printf("Setor: ");
            scanf(" %[^\n]s", novo->setor);
            if (strcmp(novo->setor, "Higiene e limpeza") == 0 ||
                strcmp(novo->setor, "Bebidas") == 0 ||
                strcmp(novo->setor, "Frios") == 0 || strcmp(novo->setor, "Padaria") == 0 ||
                strcmp(novo->setor, "Açougue") == 0) {
                valido = true;
            } else {
                printf("\nSetor inválido, digite um setor válido\n\n");
            }
        }
        printf("Nome: ");
        scanf(" %[^\n]s", novo->nome);
        printf("Preço: ");
        scanf(" %lf", &novo->preco);
        printf("Data de validade (dd/mm/aaaa): ");
        scanf(" %d/%d/%d", &novo->validade.dia, &novo->validade.mes,
              &novo->validade.ano);
        valido = false;
        while (!valido) {
            printf("Quantidade em estoque: ");
            scanf(" %d", &novo->estoque);
            if (novo->estoque >= 0) {
                valido = true;
            } else {
                printf("\nQuantidade inválida, digite uma quantidade válida\n\n");
            }
        }
        produto[codigo] = novo;
        limpaTela();
    }
    return (codigo + 1);
}
