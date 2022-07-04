#include <stdio.h>
#include "Funcoes.h"

void menuClientes() {
    //Variáveis
    int opcao, cadastrado = 1;

    do {
        //Imprime o menu de clientes
        printf("1 - Cadastrar um novo cliente\n");
        printf("2 - Atualizar dados de um cliente\n");
        printf("3 - Mostrar a quantidade de clientes com idade entre 18 e 25 anos\n");
        printf("4 - Listar clientes com mais de 1000 pontos\n");
        printf("9 - Voltar\n");

        //Pede uma opção, anota a opção escolhida e depois limpa a tela
        printf("\nDigite uma opção: ");
        scanf(" %d", &opcao);
        limpaTela();

        //Seleciona a opção escolhida
        switch (opcao) {
            case 1:
                cadastrarCliente(cadastrado);
                break;
            case 2:
                alterarDadosCliente();
                break;
            case 3:
                quantidadeClientesIdadeEntre18E25();
                break;
            case 4:
                clientesMais1000Pontos();
                break;
            default:
                if (opcao != 9)
                    printf("Opção inválida\n\n");
        }
    } while (opcao != 9);
}