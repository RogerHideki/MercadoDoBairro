#include <stdio.h>
#include "Funcoes.h"

void menuPrincipal() {
    //Variável local
    int opcao;

    //Imprime o menu principal
    printf("1. Vendas\n");
    printf("2. Clientes\n");
    printf("3. Produtos\n");
    printf("9. Sair\n");

    //Pede uma opção, anota a opção escolhida e depois limpa a tela
    printf("\nDigite uma opção: ");
    scanf(" %d", &opcao);
    limpaTela();

    //Seleciona a opção escolhida
    switch (opcao) {
        case 1:
            menuVendas();
            break;
        case 2:
            menuClientes();
            break;
        case 3:
            menuProdutos();
            break;
        case 9:
            printf("Programa finalizado\n");
            break;
        default:
            printf("Opção inválida\n\n");
            menuPrincipal();
    }
}