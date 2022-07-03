#include <stdio.h>
#include <time.h>
#include "Registros.h"

int idade(tCliente cliente) {
    time_t t = time(NULL);
    struct tm dataAtual = *localtime(&t);

    if (dataAtual.tm_year + 1900 - cliente.dataNascimento.ano > 0) {
        if (dataAtual.tm_mon + 1 - cliente.dataNascimento.mes < 0)
            return (dataAtual.tm_year + 1900 - cliente.dataNascimento.ano - 1);
        else if (dataAtual.tm_mon + 1 - cliente.dataNascimento.mes == 0) {
            if (dataAtual.tm_mday - cliente.dataNascimento.dia < 0)
                return (dataAtual.tm_year + 1900 - cliente.dataNascimento.ano - 1);
            else
                return (dataAtual.tm_year + 1900 - cliente.dataNascimento.ano);
        }
        else if (dataAtual.tm_mon + 1 - cliente.dataNascimento.mes > 0)
            return (dataAtual.tm_year + 1900 - cliente.dataNascimento.ano);
    }
    else
        return 0;
}