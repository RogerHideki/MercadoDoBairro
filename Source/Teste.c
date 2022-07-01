#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int dia, mes, ano;
}Contato;

void salvarB(char arq[], Contato **c, int quant){
    FILE *file = fopen(arq, "wb");
    int i;

    if(file){
        for(i = 0; i < quant; i++)
            fwrite(c[i], sizeof(Contato), 1, file);
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

int lerB(char arq[], Contato **c){
    int quant = 0;
    Contato *novo = malloc(sizeof(Contato));
    FILE *file = fopen(arq, "rb");

    if(file){
        while(fread(novo, sizeof(Contato), 1, file)){
            c[quant] = novo;
            quant++;
            novo = malloc(sizeof(Contato));
        }
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
    return quant;
}

void alterarB(char arq[]){
    FILE *file = fopen(arq, "rb+");
    Contato c;
    int id, i = 1;

    if(file){
        printf("\tLista de contatos:\n");
        printf("\t----------------------------\n");
        while(fread(&c, sizeof(Contato), 1, file)){
            printf("\t%d = %2d/%2d/%4d\t%s\n", i, c.dia, c.mes, c.ano, c.nome);
            i++;
        }
        printf("\t----------------------------\n");

        printf("\n\tDigite o indice do contato que deseja alterar:\n\n");
        scanf("%d", &id);
        getchar();
        id--;

        if(id >= 0 && id < i - 1){
            printf("\tDigite nome e data de nascimento dd mm aaaa: ");
            scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
            fseek(file, id * sizeof(Contato), SEEK_SET);
            fwrite(&c, sizeof(Contato), 1, file);
        }
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

int main(){

    Contato *agenda[50];
    char arquivo2[] = {"agenda.dat"};
    int opcao, quant = 0;

    do{
        printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t3 - Imprimir\n");
        printf("\t4 - Salvar\n\t5 - Ler arquivo\n\t6 - SalvarB\n\t7 - LerB\n\t8 - AltererB\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 6:
                salvarB(arquivo2, agenda, quant);
                break;
            case 7:
                quant = lerB(arquivo2, agenda);
                break;
            case 8:
                alterarB(arquivo2);
                break;
            default:
                if(opcao != 0)
                    printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}