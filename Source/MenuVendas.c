#include <stdio.h>
#include "Funcoes.h"
#include "Registros.h"

void menuVendas() {
    //Variáveis
    tVenda venda;
    int opcao, codigo = 1;
    FILE *fVendas = fopen("../Arquivos/Vendas.dat", "rb");

    if (fVendas) {
        while (fread(&venda, sizeof(tVenda), 1, fVendas))
            codigo += 1;
        fclose(fVendas);
    }

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
                codigo += cadastrarVenda(codigo);
                break;
            case 2:

                break;
            default:
                if (opcao != 9)
                    printf("Opção inválida\n\n");
        }
    } while (opcao != 9);
}