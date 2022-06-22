#include <stdio.h>
#include "Registros.h"

void cadastrarProduto() {
    //Arquivo
    FILE *fProdutos;

    //Registro
    tProduto produto;

    //Abre o arquivo
    fProdutos = fopen("../Source/Arquivos/Produtos.csv", "ab");
    if (fProdutos == NULL) {
        perror("Erro ao tentar abrir o arquivo\n");
        return (-1);
    }

    codigo
    setor[20]
    nome[50]
    preco
    validade
    estoque

    fwrite(produto, sizeof(tProduto), 5, fProdutos);
    fclose(fProdutos);
}