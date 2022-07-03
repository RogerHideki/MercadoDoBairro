#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm dataAtual = *localtime(&t);

    if (dataAtual.tm_year + 1900 - 2003 > 0) {
        if (dataAtual.tm_mon + 1 - 8 < 0)
            printf(" %d", dataAtual.tm_year + 1900 - 2003 - 1);
        else if (dataAtual.tm_mon + 1 - 8 == 0) {
            if (dataAtual.tm_mday - 19 < 0)
                printf(" %d", dataAtual.tm_year + 1900 - 2003 - 1);
            else
                printf(" %d", dataAtual.tm_year + 1900 - 2003);
        }
        else if (dataAtual.tm_mon + 1 - 8 > 0)
            printf(" %d", dataAtual.tm_year + 1900 - 2003);
    }
    else
        printf("0");
}