#ifndef INMEMORY_CLIENTE_REPOSITORY_H
#define INMEMORY_CLIENTE_REPOSITORY_H

#include <vector>
#include <algorithm>
#include "../Repository/ClienteRepository.h"

class InMemoryClienteRepository : public ClienteRepository {
    private:
        std::vector<Cliente> clientes;
    public:
        void adicionar(const Cliente& cliente) override{
            clientes.push_back(cliente);
        }

        std::vector<Cliente> listar() const override{
            return clientes;
        }

        void atualizar(const Cliente& cliente) override {
            for (auto& c : clientes) {
                if (c.getId() == cliente.getId()) {
                    c = cliente; // Atualiza o cliente existente
                    return;
                }
            }
        }

        void deletar(int id) override {
            clientes.erase(std::remove_if(clientes.begin(), clientes.end(),
                [id](const Cliente& c) { return c.getId() == id; }), clientes.end());
        }
        Cliente buscarPorId(int id) override {
            for (auto& c : clientes) {
                if (c.getId() == id) {
                    return c; // Retorna um ponteiro para o cliente encontrado
                }
            }
            return Cliente(); // Retorna nullptr se não encontrar
        }
        std::vector<Cliente> buscarPorNome(const std::string& nome) const override {
            std::vector<Cliente> encontrados;
            for (const auto& c : clientes) {
                if (c.getNome() == nome) {
                    encontrados.push_back(c); // Adiciona o cliente encontrado à lista
                }
            }
            return encontrados; // Retorna a lista de clientes encontrados
        }


};

#endif