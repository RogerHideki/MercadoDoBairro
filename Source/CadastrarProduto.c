#include <stdio.h>
#include "Registros.h"

int cadastrarProduto() {
    //Arquivo
    FILE *fProdutos;

    //Registro
    tProduto produto;

    //Variável local
    int i, quantidadeCadastros;

    //Abre o arquivo
    fProdutos = fopen("../Source/Arquivos/Produtos.csv", "ab");
    if (fProdutos == NULL) {
        perror("Erro ao tentar abrir o arquivo\n");
        return (-1);
    }

    printf("Quantidade de cadastros:");
    scanf(" %d", &quantidadeCadastros);
    i += 0;
    for (i; i < i + quantidadeCadastros; i++){
        produto.codigo = i + 1;
        printf("Setor: ");
        scanf(" %[^\n]s", produto.setor);
        printf("Nome: ");
        scanf(" %[^\n]s", produto.nome);
        printf("Preço: ");
        scanf(" %lf", &produto.preco);
        printf("Data de validade (DD/MM/AAAA): ");
        scanf(" %d/%d/%d", &produto.validade.dia, &produto.validade.mes, &produto.validade.ano);
        printf("Quantidade em estoque: ");
        scanf(" %d", &produto.estoque);

        fwrite(&produto, sizeof(tProduto), 1, fProdutos);
    }
    fclose(fProdutos);
}