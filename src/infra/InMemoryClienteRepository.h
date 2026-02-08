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
                    c = cliente; 
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
                    return c; 
                }
            }
            return Cliente(); 
        }
        Cliente buscarPorNome(const std::string& nome) const override {
            for (const auto& c : clientes) {
                if (c.getNome() == nome) {
                    return c;
                }
            }
            return Cliente(); // Retorna um cliente vazio se não encontrar
        }



};

#endif