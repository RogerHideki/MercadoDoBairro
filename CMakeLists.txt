cmake_minimum_required(VERSION 3.22)
project(MercadoDoBairro C)

set(CMAKE_C_STANDARD 99)

add_executable(main Source/main.c Source/Funcoes.h Source/Registros.h Source/MenuVendas.c Source/MenuClientes.c Source/MenuProdutos.c Source/LimpaTela.c Source/CadastrarCliente.c Source/Idade.c Source/AlterarDadosCliente.c Source/CadastrarProduto.c Source/AlterarDadosProduto.c Source/EstoquePorSetor.c Source/EstoqueBaixo.c)
add_executable(Teste Source/Teste.c)