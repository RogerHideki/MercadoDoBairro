#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Funcoes.h"
#include "Registros.h"

int cadastrarProduto() {
    //Arquivo
    FILE *fProdutos;

    //Variáveis locais
    int quantidadeCadastros;
    bool valido;

    //Abre o arquivo
    fProdutos = fopen("../Source/Arquivos/Produtos.csv", "a+");
    if (!fProdutos) {
        perror("Erro ao tentar abrir o arquivo\n");
        return (-1);
    }
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
    fclose(fProdutos);