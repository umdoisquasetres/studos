#include "Servico.h"
#include <iostream>

// Implementação do Construtor Vazio
Servico::Servico() : id(0), nome(""), descricao(""), preco(0.0) {}

// Construtor com parâmetros
Servico::Servico(int id, const std::string& nome, const std::string& descricao, double preco)
    : id(id), nome(nome), descricao(descricao), preco(preco) {}

// Exibe as informações do serviço
void Servico::exibir() const {
    std::cout << "\n=== Dados do Serviço ===" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Descrição: " << descricao << std::endl;
    std::cout << "Preço: R$ " << preco << std::endl;
}