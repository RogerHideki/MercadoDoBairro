#include <stdio.h>
#include "Funcoes.h"
#include "Registros.h"

void alterarDadosCliente() {
    tCliente cliente;
    int opcao;
    FILE *fClientes = fopen("../Arquivos/Cliente.dat", "rb+");

    if (fClientes) {

        //LISTAGEM DE TODOS OS CLIENTES CADASTRADOS
        printf("Lista de Clientes:\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&cliente, sizeof(tCliente), 1, fClientes)) {
            printf("%d - %13s\t%50s\t%2d/%2d/%4d\t%d anos\t%50s\t%50s\t%2s\t%d pontos\n", cliente.codigo, cliente.cpf,
                   cliente.nome, cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano,
                   cliente.idade, cliente.endereco, cliente.cidade, cliente.estado, cliente.pontos);
        }
        printf("---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

        //ENTRADA DO CÓDIGO CORRESPONDENTE DO CLIENTE QUE TERÁ SEUS DADOS ALTERADOS
        printf("Digite o código do cliente que deseja alterar: ");
        scanf(" %d", &opcao);
        opcao--;
        limpaTela();

        //PARAMETRO DE ENTRADA, CASO SEJA UM CÓDIGO CORRESPONDENTE, EDITA, CASO NÃO, SAI
        if (opcao >= 0 && opcao < cliente.codigo) {
            cliente.codigo = opcao + 1;

            //ENTRADA DE DADOS PARA ATUALIZAÇÃO DE INFORMAÇÕES DO CLIENTE
            printf("CPF: ");
            scanf(" %[^\n]s", cliente.cpf);
            printf("Nome: ");
            scanf(" %[^\n]s", cliente.nome);
            printf("Data de nascimento: ");
            scanf(" %d/%d/%d", &cliente.dataNascimento.dia, &cliente.dataNascimento.mes,
                  &cliente.dataNascimento.ano);
            cliente.idade = idade(cliente);
            printf("Endereço: ");
            scanf(" %[^\n]s", cliente.endereco);
            printf("Cidade: ");
            scanf(" %[^\n]s", cliente.cidade);
            printf("Estado: ");
            scanf(" %[^\n]s", cliente.estado);
            printf("Pontos: ");
            scanf(" %d", &cliente.pontos);

            //REGISTRO DAS INFORMAÇÕES DOS DADOS ATUALIZADOS NO ARQUIVO
            fseek(fClientes, opcao * sizeof(tCliente), SEEK_SET);
            fwrite(&cliente, sizeof(tCliente), 1, fClientes);
            limpaTela();
        } else {
            limpaTela();
            printf("Código inválido\n\n");
        }
        fclose(fClientes);
    } else {
        limpaTela();
        printf("Erro ao abrir arquivo\n\n");
    }
}