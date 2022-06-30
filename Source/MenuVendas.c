#include <stdio.h>
#include "Funcoes.h"

void menuVendas() {
    //Variável
    int opcao;

    do {
        //Imprime o menu de vendas
        printf("1 - Cadastrar uma nova venda\n");
        printf("2 - Listar compras de um cliente\n");
        printf("9 - Voltar\n");

        //Pede uma opção, anota a opção escolhida e depois limpa a tela
        printf("\nDigite uma opção: ");
        scanf(" %d", &opcao);
        limpaTela();

        //Seleciona a opção escolhida
        switch (opcao) {
            case 1:

                break;
            case 2:

                break;
            default:
                if (opcao != 9)
                    printf("Opção inválida\n\n");
        }
    } while (opcao != 9);
}