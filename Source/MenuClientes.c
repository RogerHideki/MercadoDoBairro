#include <stdio.h>
#include "Funcoes.h"

void menuClientes() {
    //Variável local
    int opcao;

    //Imprime o menu de clientes
    printf("1. Cadastrar um novo cliente\n");
    printf("2. Atualizar pontuação de um cliente\n");
    printf("3. Atualizar dados de um cliente\n");
    printf("4. Mostrar a quantidade de clientes com idade entre 18 e 25 anos\n");
    printf("5. Listar clientes com mais de 1000 pontos\n");
    printf("9. Voltar\n");

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
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 9:
            menuPrincipal();
            break;
        default:
            printf("Opção inválida\n\n");
            menuProdutos();
    }
}