#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include "Registros.h"
#include "Funcoes.h"

/*void menu1() {
    //Imprime o menu de vendas
    printf("1. Cadastrar uma nova venda\n");
    printf("2. Listar compras de um cliente\n");
    printf("9. Sair\n");
}

void menu2() {
    //Imprime o menu de clientes
    printf("1. Cadastrar um novo cliente\n");
    printf("2. Atualizar pontuação de um cliente\n");
    printf("3. Atualizar dados de um cliente\n");
    printf("4. Mostrar a quantidade de clientes com idade entre 18 e 25 anos\n");
    printf("5. Listar clientes com mais de 1000 pontos\n");
    printf("9. Sair\n");
}

void menu3() {
    //Imprime o menu de produtos
    printf("1. Cadastrar um novo produto\n");
    printf("2. Alterar dados de um produto\n");
    printf("3. Listar estoque de produtos por setor\n");
    printf("4. Listar produtos com estoque abaixo de 5\n");
    printf("9. Sair\n");
}*/

int main() {
    SetConsoleOutputCP(65001);

    imprima();
   /* //Variáveis locais
    int opcao;
    bool valido;

    valido = false;
    while (!valido) {
        valido = true;

        //Imprime o menu principal
        printf("1. Vendas\n");
        printf("2. Clientes\n");
        printf("3. Produtos\n");
        printf("9. Sair\n");

        //Pede uma opção, anota a opção escolhida e depois limpa a tela
        printf("\nDigite uma opção: ");
        scanf(" %d", &opcao);
        system("cls");

        //Seleciona a opção escolhida
        switch (opcao) {
            case 1:
                menu1();
                break;
            case 2:
                menu2();
                break;
            case 3:
                menu3();
                break;
            case 9:
                printf("Programa finalizado\n");
                break;
            default:
                printf("Opção inválida\n\n");
                valido = false;
        }
    }*/

    return 0;
}