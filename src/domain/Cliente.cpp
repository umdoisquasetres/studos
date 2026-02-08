#include "./Cliente.h"
#include <iostream>

// 1. Implementação do Construtor Vazio
// Inicializamos com valores seguros para evitar lixo de memória
Cliente::Cliente() : id(0), nome(""), cpfCnpj(""), email(""), telefone(""), endereco("") {}

//Construtor com parâmetros
Cliente::Cliente(const int id, const std::string& nome, const std::string& cpfCnpj, const std::string& email, const std::string& telefone, const std::string& endereco)
    : id(id), nome(nome), cpfCnpj(cpfCnpj), email(email), telefone(telefone), endereco(endereco) {}

//Exibe as informações do cliente
void Cliente::exibir() const {
    std::cout << "\n=== Dados do Cliente ===" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "CPF/CNPJ: " << cpfCnpj << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Telefone: " << telefone << std::endl;
    std::cout << "Endereço: " << endereco << std::endl;
}