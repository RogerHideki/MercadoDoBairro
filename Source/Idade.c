#include <stdio.h>
#include <time.h>

int main()
{
    time_t s;
    struct tm* DataAtual;

    s = time(NULL);
    DataAtual = localtime(&s);

    printf("Day of the month = %d\n",DataAtual->tm_mday);
    printf("Month of this year = %d\n",(DataAtual->tm_mon + 1));
    printf("Current year = %d\n",(DataAtual->tm_year + 1900));

    return 0;
}