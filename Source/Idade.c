#include <stdio.h>
#include <time.h>
#include "Registros.h"

int idade(tCliente cliente) {
    time_t s;
    struct tm *DataAtual;

    s = time(NULL);
    DataAtual = localtime(&s);

    if ((DataAtual->tm_year + 1900) - cliente.dataNascimento.ano > 0) {
        if ((DataAtual->tm_mon + 1) - cliente.dataNascimento.mes < 0)
            return ((DataAtual->tm_year + 1900) - cliente.dataNascimento.ano);
        else if ((DataAtual->tm_mon + 1) - cliente.dataNascimento.mes == 0)

        else if ((DataAtual->tm_mon + 1) - cliente.dataNascimento.mes > 0)
    }

    DataAtual->tm_mday;

    return 0;
}