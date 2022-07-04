#include <stdio.h>
#include "Funcoes.h"

void menuProdutos() {
    //Variável
    int opcao;

    do {
        //Imprime o menu de produtos
        printf("1 - Cadastrar um novo produto\n");
        printf("2 - Alterar dados de um produto\n");
        printf("3 - Listar estoque de produtos por setor\n");
        printf("4 - Listar produtos com estoque abaixo de 5 unidades\n");
        printf("9 - Voltar\n");

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
                alterarDadosProduto();
                break;
            case 3:
                estoquePorSetor();
                break;
            case 4:
                estoqueBaixo();
                break;
            default:
                if (opcao != 9)
                    printf("Opção inválida\n\n");
        }
    } while (opcao != 9);
}