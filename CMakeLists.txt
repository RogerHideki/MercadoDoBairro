cmake_minimum_required(VERSION 3.22)
project(MercadoDoBairro C)

set(CMAKE_C_STANDARD 99)

add_executable(Main Source/main.c Source/Registros.h Source/Funcoes.h Source/MenuPrincipal.c Source/MenuVendas.c Source/MenuClientes.c Source/MenuProdutos.c)
