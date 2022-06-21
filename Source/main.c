#include <stdio.h>
#include <windows.h>
#include "Funcoes.h"
#include "Registros.h"

int main() {
    SetConsoleOutputCP(65001);

    menuPrincipal();
    scanf("%d");

    return 0;
}