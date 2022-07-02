#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

void alterarDadosProduto() {
    tProduto produto;
    int opcao;
    bool valido;
    FILE *fProdutos = fopen("../Arquivos/Produtos.dat", "rb+");

    if (fProdutos) {
        printf("Estoque de Produtos:\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&produto, sizeof(tProduto), 1, fProdutos)) {
            printf("%d - %20s\t%50s\tR$ %.2lf\t%2d/%2d/%4d\t%d unidades\n", produto.codigo, produto.setor, produto.nome,
                   produto.preco, produto.validade.dia, produto.validade.mes, produto.validade.ano, produto.estoque);
        }
        printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

        printf("\nDigite o código do produto que deseja alterar: ");
        scanf(" %d", &opcao);
        opcao--;
        limpaTela();

        if (opcao >= 0 && opcao < produto.codigo) {
            produto.codigo = opcao + 1;
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
            fseek(fProdutos, opcao * sizeof(tProduto), SEEK_SET);
            fwrite(&produto, sizeof(tProduto), 1, fProdutos);
            limpaTela();
        } else {
            limpaTela();
            printf("Código inválido\n\n");
        }
        fclose(fProdutos);
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
}