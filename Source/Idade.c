#include <stdio.h>
#include <time.h>
#include "Registros.h"

int idade(tCliente cliente) {
    time_t s;
    struct tm *DataAtual;

    s = time(NULL);
    DataAtual = localtime(&s);

    if ((DataAtual->tm_year + 1900) - cliente.dataNascimento.ano > 0) {
        
    }
                (DataAtual->tm_mon + 1)
    DataAtual->tm_mday;

    return 0;
}