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
            return ((DataAtual->tm_year + 1900) - cliente.dataNascimento.ano - 1);
        else if ((DataAtual->tm_mon + 1) - cliente.dataNascimento.mes == 0) {
            if ((DataAtual->tm_mday) - cliente.dataNascimento.dia);
                return ();
            else
                return ();
        }
        else if ((DataAtual->tm_mon + 1) - cliente.dataNascimento.mes > 0)
            return ((DataAtual->tm_year + 1900) - cliente.dataNascimento.ano);
    }
    else
        return 0;
}