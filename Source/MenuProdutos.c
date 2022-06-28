#include <stdio.h>
#include "Funcoes.h"

void menuProdutos() {
    //Variável local
    int opcao;

    //Imprime o menu de produtos
    printf("1. Cadastrar um novo produto\n");
    printf("2. Alterar dados de um produto\n");
    printf("3. Listar estoque de produtos por setor\n");
    printf("4. Listar produtos com estoque abaixo de 5\n");
    printf("9. Voltar\n");

    //Pede uma opção, anota a opção escolhida e depois limpa a tela
    printf("\nDigite uma opção: ");
    scanf(" %d", &opcao);
    limpaTela();

    //Seleciona a opção escolhida
    switch (opcao) {
        case 1:
            cadastrarProduto();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 9:
            menuPrincipal();
            break;
        default:
            printf("Opção inválida\n\n");
            menuProdutos();
    }
}