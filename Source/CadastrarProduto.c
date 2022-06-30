#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Funcoesteste.h"
#include "Registrosteste.h"

//int cadastrarProduto() {
    //Arquivo
    FILE *fProdutos;

    //Registro
    tProduto produto;

    //Variáveis locais
    int maiorCodigo, fim, quantidadeCadastros;
    bool valido;

    Abre o arquivo
    fProdutos = fopen("../Source/Arquivos/Produtos.csv", "a");
    if (fProdutos == NULL) {
        perror("Erro ao tentar abrir o arquivo\n");
        return (-1);
    }
    //valido = false;
    //while (!valido) {
    //    printf("Quantidade de cadastros:");
    //    scanf(" %d", &quantidadeCadastros);
    //    if (quantidadeCadastros > 0) {
    //        valido = true;
    //    } else {
    //        limpaTela();
    //        printf("Quantidade inválida, digite uma quantidade válida\n\n");
    //    }
    //}
    //if (produto.setor == "") {
    //    maiorCodigo = 0;
    //}
    //fim = maiorCodigo + quantidadeCadastros;
    //for (maiorCodigo; maiorCodigo < fim; maiorCodigo++) {
    //    produto.codigo = maiorCodigo + 1;
    //    valido = false;
    //    while (!valido) {
    //        printf("Setor: ");
    //        scanf(" %[^\n]s", produto.setor);
    //        if (strcmp(produto.setor, "Higiene e limpeza") == 0 || strcmp(produto.setor, "Bebidas") == 0 ||
    //            strcmp(produto.setor, "Frios") == 0 || strcmp(produto.setor, "Padaria") == 0 ||
    //            strcmp(produto.setor, "Açougue") == 0) {
    //            valido = true;
    //        } else {
    //            printf("\nSetor inválido, digite um setor válido\n\n");
    //        }
    //    }
    //    printf("Nome: ");
    //    scanf(" %[^\n]s", produto.nome);
    //    printf("Preço: ");
    //    scanf(" %lf", &produto.preco);
    //    printf("Data de validade (DD/MM/AAAA): ");
    //    scanf(" %d/%d/%d", &produto.validade.dia, &produto.validade.mes, &produto.validade.ano);
    //    valido = false;
    //    while (!valido) {
    //        printf("Quantidade em estoque: ");
    //        scanf(" %d", &produto.estoque);
    //        if (produto.estoque >= 0) {
    //            valido = true;
    //        } else {
    //            printf("\nQuantidade inválida, digite uma quantidade válida\n\n");
    //        }
    //    }
    //    limpaTela();
        fwrite(&produto, sizeof(tProduto), 1, fProdutos);
    }
    fclose(fProdutos);
}