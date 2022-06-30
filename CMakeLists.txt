cmake_minimum_required(VERSION 3.22)
project(MercadoDoBairro C)

set(CMAKE_C_STANDARD 99)

add_executable(MenuPrincipal Source/MenuPrincipal.c Source/MenuVendas.c Source/MenuClientes.c Source/MenuProdutos.c Source/LimpaTela.c Source/CadastrarProduto.c Source/Funcoes.h Source/Registros.h)
add_executable(Teste Source/Teste.c)