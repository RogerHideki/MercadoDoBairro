#include <windows.h>
#include <stdio.h>
#include "Funcoes.h"

int main() {
    SetConsoleOutputCP(65001);

    //VARIÁVEL
    int opcao;

    do {
        //IMPRIME O MENU PRINCIPAL
        printf("1 - Vendas\n");
        printf("2 - Clientes\n");
        printf("3 - Produtos\n");
        printf("9 - Sair\n");

        //PEDE UMA OPÇÃO, ANOTA A OPÇÃO ESCOLHIDA E DEPOIS LIMPA TELA
        printf("\nDigite uma opção: ");
        scanf(" %d", &opcao);
        limpaTela();

        //SELEÇÃO DE OPÇÕES
        switch (opcao) {
            case 1: //CASO 1, A FUNÇÃO DE SUBMENU DE VENDAS É CHAMADA
                menuVendas();
                break;
            case 2: //CASO 2, A FUNÇÃO DE SUBMENU DE CLIENTES É CHAMADA
                menuClientes();
                break;
            case 3: //CASO 3, A FUNÇÃO DE SUBMENU DE PRODUTOS É CHAMADA
                menuProdutos();
                break;
            default:
                if (opcao != 9)
                    printf("Opção inválida\n\n");
        }
    } while (opcao != 9); //CASO 9, O PROGRAMA É ENCERRADO

    return 0;
}