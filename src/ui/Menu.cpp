#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <iostream>
#include <string>
#include "Menu.h"

Menu::Menu() {}
Menu::~Menu() {}

void Menu::limparTela()
{
    system(CLEAR);
}

void Menu::verificaBuffer()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
}

void Menu::pausar()
{
    std::cout << "Pressione Enter para continuar...";
    std::cin.ignore(1000, '\n');
    std::cin.get();
}

void Menu::cabecalho(const std::string &titulo)
{
    std::cout << "==============================" << std::endl;
    std::cout << "       " << titulo << std::endl;
    std::cout << "==============================" << std::endl;
}

void Menu::iniciar()
{
    menuPrincipal();
}

void Menu::menuPrincipal()
{
    int opcao = 0;
    do
    {
        limparTela();
        cabecalho("Tela de inicio");
        std::cout << "1. Clientes" << std::endl;
        std::cout << "2. Serviços" << std::endl;
        std::cout << "3. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        verificaBuffer();
        switch (opcao)
        {
        case 1:
            menuClientes();
            break;
        case 2:
            menuServicos();
            break;
        case 3:
            std::cout << "Saindo..." << std::endl;
            return;
        default:
            std::cout << "Opção inválida!" << std::endl;
            pausar();
        }
    } while (opcao != 3);
}

void Menu::menuClientes()
{
    limparTela();
    cabecalho("Menu de Clientes");
    std::cout << "1. Cadastrar Cliente" << std::endl;
    std::cout << "2. Listar Clientes" << std::endl;
    std::cout << "3. Voltar" << std::endl;
    std::cout << "Escolha uma opção: ";
    int opcao;
    std::cin >> opcao;
    // VERIFICAÇÃO DE ERRO (Se digitar letra)
    verificaBuffer();
    switch (opcao)
    {
    case 1:
        cadastrarCliente();
        pausar();
        break;
    case 2:
        listarClientes();
        pausar();
        break;
    case 3:

        break;
    default:
        std::cout << "Opção inválida!" << std::endl;
        pausar();
    }
}

void Menu::menuServicos()
{
    int opcao = 0;
    do
    {
        limparTela();
        cabecalho("Menu de Serviços");
        std::cout << "1. Cadastrar Serviço" << std::endl;
        std::cout << "2. Listar Serviços" << std::endl;
        std::cout << "3. Voltar" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        // VERIFICAÇÃO DE ERRO (Se digitar letra)
        verificaBuffer();
        switch (opcao)
        {
        case 1:
            cadastrarServico();
            pausar();
            break;
        case 2:
            listarServicos();
            pausar();
            break;
        case 3:

            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            pausar();
        }
    } while (opcao != 3);
}

void Menu::cadastrarCliente()
{
    limparTela();
    cabecalho("Cadastrar Cliente");
    std::string nome, cpfCnpj, email, telefone, endereco;

    std::cin.ignore(); // Limpa o buffer antes de ler strings
    std::cout << "Nome: ";
    std::getline(std::cin, nome);
    std::cin.ignore();
    std::cout << "CPF/CNPJ: ";
    std::getline(std::cin, cpfCnpj);
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "Telefone: ";
    std::getline(std::cin, telefone);
    std::cin.ignore();
    std::cout << "Endereço: ";
    std::getline(std::cin, endereco);

    Cliente novoCliente(proximoId++, nome, cpfCnpj, email, telefone, endereco);
    listaDeClientes.push_back(novoCliente);
    std::cout << "Cliente cadastrado com sucesso!" << std::endl;
}

void Menu::listarClientes()
{
    limparTela();
    cabecalho("Lista de Clientes");
    if(listaDeClientes.empty()){
        std::cout << "Nenhum cliente cadastrado!" << std::endl;
    }else{
        for(const auto& cliente : listaDeClientes){
            cliente.exibir();
            std::cout << "------------------------" << std::endl;
        }
    }
}

void Menu::buscarClientePorId()
{
    std::cout << "Buscar Cliente por ID selecionado!" << std::endl;
}

void Menu::buscarClientePorNome()
{
    std::cout << "Buscar Cliente por Nome selecionado!" << std::endl;
}

void Menu::atualizarCliente()
{
    std::cout << "Atualizar Cliente selecionado!" << std::endl;
}

void Menu::deletarCliente()
{
    std::cout << "Deletar Cliente selecionado!" << std::endl;
}

void Menu::cadastrarServico()
{
    std::cout << "Cadastrar Serviço selecionado!" << std::endl;
}

void Menu::listarServicos()
{
    std::cout << "Listar Serviços selecionado!" << std::endl;
}

void Menu::buscarServicoPorId()
{
    std::cout << "Buscar Serviço por ID selecionado!" << std::endl;
}

void Menu::buscarServicoPorDescricao()
{
    std::cout << "Buscar Serviço por Descrição selecionado!" << std::endl;
}

void Menu::atualizarServico()
{
    std::cout << "Atualizar Serviço selecionado!" << std::endl;
}

void Menu::deletarServico()
{
    std::cout << "Deletar Serviço selecionado!" << std::endl;
}