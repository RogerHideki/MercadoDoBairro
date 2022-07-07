#include <stdio.h>
#include "Funcoes.h"

void menuVendas() {
    //Variável
    int opcao;

    do {
        //IMPRIME O SUBMENU DE VENDAS
        printf("1 - Cadastrar uma nova venda\n");
        printf("2 - Listar compras de um cliente\n");
        printf("9 - Voltar\n");

        //PEDE UMA OPÇÃO, ANOTA, E LIMPA A TELA
        printf("\nDigite uma opção: ");
        scanf(" %d", &opcao);
        limpaTela();

        //SELEÇÃO DE OPÇÕES
        switch (opcao) {
            case 1: //CASO 1, A FUNÇAÕ DE CADAASTRAR UMA NOVA VENDA É CHAMADA
                cadastrarVenda();
                break;
            case 2: //CASO 2, A FUNÇÃO DE LISTAGEM DE COMPRAS É CHAMADA
                comprasCliente();
                break;
            default:
                if (opcao != 9)
                    printf("Opção inválida\n\n");
        }
    } while (opcao != 9); //CASO 9, A FUNÇÃO RETORNA PARA O MENU PRINCIPAL
}