#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include "Registros.h"
#include "Funcoes.h"

int main() {
    SetConsoleOutputCP(65001);
    //Variáveis locais
    int opcao;
    bool valido;

    valido = false;
    while (!valido) {
        valido = true;

        menuPrincipal();

        //Pede uma opção, anota a opção escolhida e depois limpa a tela
        printf("\nDigite uma opção: ");
        scanf(" %d", &opcao);
        system("cls");

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
                valido = false;
        }
    }

    return 0;
}