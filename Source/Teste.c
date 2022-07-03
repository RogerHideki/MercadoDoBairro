#include <stdio.h>
#include <time.h>

int teste() {
    time_t s;
    struct tm *DataAtual;

    s = time(NULL);
    DataAtual = localtime(&s);

    if ((DataAtual->tm_year + 1900) - 2003 > 0) {
        if ((DataAtual->tm_mon + 1) - 8 < 0)
            printf((DataAtual->tm_year));
        else if ((DataAtual->tm_mon + 1) - 8 == 0) {
            if ((DataAtual->tm_mday) - 19 < 0)
                printf((DataAtual->tm_year));
            else
                printf((DataAtual->tm_year));
        }
        else if ((DataAtual->tm_mon + 1) - 8 > 0)
            printf((DataAtual->tm_year));
    }
    else
        printf(0);

    return 0;
}