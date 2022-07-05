#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

void cadastrarProduto() {
    tProduto produto;
    int codigo = 1;
    bool valido;
    FILE *fProdutos = fopen("../Arquivos/Produtos.dat", "rb");

    if(fProdutos) {
        while (fread(&produto, sizeof(tProduto), 1, fProdutos))
            codigo += 1;
        fclose(fProdutos);
    }

    fProdutos = fopen("../Arquivos/Produtos.dat", "ab");

    if (fProdutos) {
        produto.codigo = codigo;
        valido = false;
        while (!valido) {
            printf("Setor: ");
            scanf(" %[^\n]s", produto.setor);
            if (strcmp(produto.setor, "Higiene e limpeza") == 0 ||
                strcmp(produto.setor, "Bebidas") == 0 ||
                strcmp(produto.setor, "Frios") == 0 || strcmp(produto.setor, "Padaria") == 0 ||
                strcmp(produto.setor, "Acougue") == 0) {
                valido = true;
            } else {
                printf("\nSetor inválido, digite um setor válido\n\n");
            }
        }
        printf("Nome: ");
        scanf(" %[^\n]s", produto.nome);
        valido = false;
        while (!valido) {
            printf("Preço: ");
            scanf(" %lf", &produto.preco);
            if (produto.preco >= 0) {
                valido = true;
            } else {
                printf("\nPreço inválido, digite um preço válido\n\n");
            }
        }
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
}