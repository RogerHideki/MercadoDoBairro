#include <stdio.h>
#include "Funcoes.h"

void menuProdutos() {
    //Variável
    int opcao;

    do {
        //IMPRIME O SUBMENU DE PRODUTOS
        printf("1 - Cadastrar um novo produto\n");
        printf("2 - Alterar dados de um produto\n");
        printf("3 - Listar estoque de produtos por setor\n");
        printf("4 - Listar produtos com estoque abaixo de 5 unidades\n");
        printf("9 - Voltar\n");

        //PEDE UMA OPÇÃO, ANOTA A OPÇÃO ESCOLHIDA E DEPOIS LIMPA TELA
        printf("\nDigite uma opção: ");
        scanf(" %d", &opcao);
        limpaTela();

        //SELECÃO DE OPÇÕES
        switch (opcao) {
            case 1: //CASO 1, A FUNÇÃO DE CADASTRAR PRODUTO É CHAMADA
                cadastrarProduto();
                break;
            case 2: //CASO 2, A FUNÇÃO DE ATUALIZAR INFORMAÇÕES É CHAMADA
                alterarDadosProduto();
                break;
            case 3: //CASO 3, A FUNÇÃO DE LISTAR ESTOQUE POR SETOR É CHAMADA
                estoquePorSetor();
                break;
            case 4: //CASO 4, A FUNÇÃO DE LISTAR OS PRODUTOS COM ESTOQUE BAIXO É CHAMADA
                estoqueBaixo();
                break;
            default:
                if (opcao != 9)
                    printf("Opção inválida\n\n");
        }
    } while (opcao != 9); //CASO 9, A FUNÇÃO RETORNA PARA O MENU PRINCIPAL
}