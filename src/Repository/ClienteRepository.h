#ifndef CLIENTE_REPOSITORY_H
#define CLIENTE_REPOSITORY_H

#include <vector>
#include "../domain/Cliente.h"

class ClienteRepository {
    public:
        virtual ~ClienteRepository() = default;
        virtual void adicionar(const Cliente& cliente) = 0;
        virtual std::vector<Cliente> listar() const = 0;
        virtual Cliente buscarPorId(int id) = 0;
        virtual std::vector<Cliente> buscarPorNome(const std::string& nome) const = 0;
        virtual void atualizar(const Cliente& cliente) = 0;
        virtual void deletar(int id) = 0;
};

#endif