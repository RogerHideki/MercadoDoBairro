#include <stdio.h>
#include <windows.h>
#include "Funcoes.h"

int main() {
    SetConsoleOutputCP(65001);

    menuPrincipal();
    printf("Finalizou o programa");
    scanf("%d");

    return 0;
}