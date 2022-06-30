#include <stdio.h>

int strcmpProjeto(const char *s1, const char *s2) {
    const unsigned char *str1 = (const unsigned char *) (s1);
    const unsigned char *str2 = (const unsigned char *) (s2);

    while ((*str1 == *str2) && *str1) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

int main() {
    char palavraTeste[30];
    char v[] = "açougue";
    scanf(" %s", palavraTeste);
    if (strcmpProjeto(palavraTeste, v) == 0)
        printf("Ok\n");
    else
        printf("Falha\n");
}