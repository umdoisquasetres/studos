#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <iostream>
#include <string>
#include <limits>
#include "Menu.h"

Menu::Menu(ClienteRepository* repo) : repositorio(repo), proximoId(1) {
}
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
std::cout << "\nPressione Enter para continuar...";
    // Limpa qualquer lixo antes de esperar o enter
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    int opcao;
    do{
    limparTela();
    cabecalho("Menu de Clientes");
    std::cout << "1. Cadastrar Cliente" << std::endl;
    std::cout << "2. Listar Clientes" << std::endl;
    std::cout << "3. Voltar" << std::endl;
    std::cout << "Escolha uma opção: ";
    
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
    }}while (opcao != 3);
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
    std::cout << "CPF/CNPJ: ";
    std::getline(std::cin, cpfCnpj);
    std::cout << "Email: ";
    std::getline(std::cin, email);
    std::cout << "Telefone: ";
    std::getline(std::cin, telefone);
    std::cout << "Endereço: ";
    std::getline(std::cin, endereco);

    Cliente novoCliente(proximoId++, nome, cpfCnpj, email, telefone, endereco);
    repositorio->adicionar(novoCliente);
    std::cout << "Cliente cadastrado com sucesso!" << std::endl;
}

void Menu::listarClientes()
{
    limparTela();
    cabecalho("Lista de Clientes");
    std::vector<Cliente> listaRecebida = repositorio->listar();
    if(listaRecebida.empty()){
        std::cout << "Nenhum cliente cadastrado!" << std::endl;
    }else{
        for(const auto& cliente : listaRecebida){
            cliente.exibir();
            std::cout << "------------------------" << std::endl;
        }
    }
    pausar();
}

void Menu::buscarClientePorId()
{
    limparTela();
    cabecalho("Buscar Cliente por ID");
    int id;

    //Pede o ID para o usuario
    std::cout << "Digite o ID do cliente: ";
    std::cin >> id;
    
    //Verifica se o ID é um número válido
    if(std::cin.fail()){
        verificaBuffer();
        std::cout << "ID Invalido." << std::endl;
        pausar();
        return;
    }
    Cliente clienteEncontrado = repositorio->buscarPorId(id);
    if (clienteEncontrado.getId() == 0) {
        std::cout << "\nCliente nao encontrado!" << std::endl;
    } else {
        clienteEncontrado.exibir();
    }
    pausar();
}

void Menu::buscarClientePorNome()
{
    limparTela();
    cabecalho("Buscar Cliente por Nome");
    
    std::string nomeBusca;

    // Limpeza de buffer (Necessário antes de usar getline se veio de um menu numérico)
    std::cin.ignore(); 

    std::cout << "Digite o Nome (ou parte dele): ";
    std::getline(std::cin, nomeBusca);
    Cliente clienteEncontrado = repositorio->buscarPorNome(nomeBusca);
    if (clienteEncontrado.getNome() == "") { 
        std::cout << "\nCliente nao encontrado!" << std::endl;
    } else {
        clienteEncontrado.exibir();
    }
    pausar();
}

void Menu::atualizarCliente()
{
    limparTela();
    cabecalho("ATUALIZAR CLIENTE");

    int id;
    std::cout << "Digite o ID do cliente para editar: ";
    std::cin >> id;
    verificaBuffer(); // Limpa o buffer do ID

    // 1. Busca o cliente original
    Cliente cliente = repositorio->buscarPorId(id);

    if (cliente.getId() == 0) {
        std::cout << "\n[!] Cliente nao encontrado." << std::endl;
        pausar();
        return;
    }

    std::string input;
    
    std::cout << "\n--- Editando Cliente (Pressione ENTER para manter o valor atual) ---\n" << std::endl;

    // --- NOME ---
    std::cout << "Nome atual [" << cliente.getNome() << "]: ";
    std::getline(std::cin, input);
    if (!input.empty()) { // Se digitou algo, atualiza. Se vazio, mantem o antigo.
        cliente.setNome(input);
    }

    // --- CPF/CNPJ ---
    std::cout << "CPF/CNPJ atual [" << cliente.getCpfCnpj() << "]: ";
    std::getline(std::cin, input);
    if (!input.empty()) cliente.setCpfCnpj(input);

    // --- EMAIL ---
    std::cout << "Email atual [" << cliente.getEmail() << "]: ";
    std::getline(std::cin, input);
    if (!input.empty()) cliente.setEmail(input);

    // --- TELEFONE ---
    std::cout << "Telefone atual [" << cliente.getTelefone() << "]: ";
    std::getline(std::cin, input);
    if (!input.empty()) cliente.setTelefone(input);

    // --- ENDEREÇO ---
    std::cout << "Endereco atual [" << cliente.getEndereco() << "]: ";
    std::getline(std::cin, input);
    if (!input.empty()) cliente.setEndereco(input);

    // 3. Salva as alterações no repositório
    repositorio->atualizar(cliente);

    std::cout << "\n>>> Cliente atualizado com sucesso! <<<" << std::endl;
    pausar();
    
}

void Menu::deletarCliente()
{
    limparTela();
    cabecalho("DELETAR CLIENTE");

    int id;
    std::cout << "Digite o ID do cliente que deseja remover: ";
    std::cin >> id;

    if (std::cin.fail()) {
        verificaBuffer();
        std::cout << "ID Invalido." << std::endl;
        pausar();
        return;
    }

    // 1. Verifica se existe antes de tentar apagar
    Cliente clienteAlvo = repositorio->buscarPorId(id);

    if (clienteAlvo.getId() == 0) {
        std::cout << "\n[!] Cliente com ID " << id << " nao encontrado." << std::endl;
    } else {
        // 2. Mostra quem é para evitar acidentes
        std::cout << "\nVoce vai deletar o cliente: " << clienteAlvo.getNome() << std::endl;
        std::cout << "Tem certeza? (1-Sim / 0-Nao): ";
        int confirmar;
        std::cin >> confirmar;

        if (confirmar == 1) {
            repositorio->deletar(id);
            std::cout << "\n>>> Cliente removido com sucesso! <<<" << std::endl;
        } else {
            std::cout << "\nOperacao cancelada." << std::endl;
        }
    }
    pausar();
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