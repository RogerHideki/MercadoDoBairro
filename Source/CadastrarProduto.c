#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

int cadastrarProduto(int codigo) {
    tProduto produto;
    bool valido;
    FILE *fProdutos = fopen("../Source/Arquivos/Produtos.dat", "ab");

    if (fProdutos) {
        produto.codigo = codigo;
        valido = false;
        while (!valido) {
            printf("Setor: ");
            scanf(" %[^\n]s", produto.setor);
            if (strcmp(produto.setor, "Higiene e limpeza") == 0 ||
                strcmp(produto.setor, "Bebidas") == 0 ||
                strcmp(produto.setor, "Frios") == 0 || strcmp(produto.setor, "Padaria") == 0 ||
                strcmp(produto.setor, "Açougue") == 0) {
                valido = true;
            } else {
                printf("\nSetor inválido, digite um setor válido\n\n");
            }
        }
        printf("Nome: ");
        scanf(" %[^\n]s", produto.nome);
        printf("Preço: ");
        scanf(" %lf", &produto.preco);
        printf("Data de validade (dd/mm/aaaa): ");
        scanf(" %d/%d/%d", &produto.validade.dia, &produto.validade.mes,
              &produto.validade.ano);
        valido = false;
        while (!valido) {
            printf("Quantidade em estoque: ");
            scanf(" %d", &produto.estoque);
            if (produto.estoque >= 0) {
                valido = true;
            } else {
                printf("\nQuantidade inválida, digite uma quantidade válida\n\n");
            }
        }
        fwrite(&produto, sizeof(tProduto), 1, fProdutos);
        fclose(fProdutos);
        limpaTela();
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
    return 1;
}
