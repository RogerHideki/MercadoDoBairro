#include <stdio.h>
#include <time.h>

int main()
{
    time_t s;
    struct tm* DataAtual;

    s = time(NULL);
    DataAtual = localtime(&s);

    if (DataAtual->tm_year + 1900)-
    DataAtual->tm_mon + 1));
    DataAtual->tm_mday;

    return 0;
}