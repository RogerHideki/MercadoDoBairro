#include <windows.h>
#include <stdio.h>
#include "Funcoes.h"

int main() {
    SetConsoleOutputCP(65001);

    //Variável
    int opcao;

    do {
        //Imprime o menu principal
        printf("1 - Vendas\n");
        printf("2 - Clientes\n");
        printf("3 - Produtos\n");
        printf("9 - Sair\n");

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
            default:
                if (opcao != 9)
                    printf("Opção inválida\n\n");
        }
    } while (opcao != 9);
    printf("Programa finalizado\n");

    return 0;
}