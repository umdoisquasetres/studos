#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include "../domain/Cliente.h"
#include "../Repository/ClienteRepository.h"

class Menu
{
private:

    ClienteRepository* repositorio;
    // Funções auxiliares
    void limparTela();
    void pausar();
    void cabecalho(const std::string &titulo);
    void verificaBuffer();

    //Gerar ID automático
    int proximoId = 1;

    // Menus
    void menuPrincipal();
    void menuClientes();
    void menuServicos();

    // Operações de Cliente
    void cadastrarCliente();
    void listarClientes();
    void buscarClientePorId();
    void buscarClientePorNome();
    void atualizarCliente();
    void deletarCliente();

    // Operações de Serviço
    void cadastrarServico();
    void listarServicos();
    void buscarServicoPorId();
    void buscarServicoPorDescricao();
    void atualizarServico();
    void deletarServico();

public:
    Menu(ClienteRepository* repo);
    ~Menu();
    void iniciar();
};

#endif