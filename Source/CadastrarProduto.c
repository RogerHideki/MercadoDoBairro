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
}