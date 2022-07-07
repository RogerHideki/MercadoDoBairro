#include <stdio.h>
#include "Funcoes.h"

void menuClientes() {
    //Variáveis
    int opcao, cadastrado = 0;

    do {
        //IMPRIME O SUBMENU DE CLIENTES
        printf("1 - Cadastrar um novo cliente\n");
        printf("2 - Atualizar dados de um cliente\n");
        printf("3 - Mostrar a quantidade de clientes com idade entre 18 e 25 anos\n");
        printf("4 - Listar clientes com mais de 1000 pontos\n");
        printf("9 - Voltar\n");

        //PEDE UMA OPÇÃO, ANOTA A OPÇÃO ESCOLHIDA E LIMPA A TELA
        printf("\nDigite uma opção: ");
        scanf(" %d", &opcao);
        limpaTela();

        //SELEÇÃO DE OPÇÕES
        switch (opcao) {
            case 1: //CASO 1, A FUNÇÃO DE CADASTRAR UM NOVO CLIENTE É CHAMADA
                cadastrarCliente(cadastrado);
                break;
            case 2: //CASO 2, A FUNÇÃO DE ALTERAR OS  DO CLIENTE É CHAMADA
                alterarDadosCliente();
                break;
            case 3: //CASO 3, A FUNÇÃO DE LISTAR A QUANTIDADE DE CLIENTE ENTRE 18 À 25 ANOS
                quantidadeClientesIdadeEntre18E25();
                break;
            case 4: //CASO 4, A FUNÇÃO DE LISTAR OS CLIENTES COM MAIS DE 1000 PONTOS É CHAMADA
                clientesMais1000Pontos();
                break;
            default:
                if (opcao != 9)
                    printf("Opção inválida\n\n");
        }
    } while (opcao != 9); //CASO 9, A FUNÇÃO RETORNA PARA O MENU PRINCIPAL
}