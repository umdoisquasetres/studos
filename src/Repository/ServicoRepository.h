#ifndef SERVICOREPOSITORY_H
#define SERVICOREPOSITORY_H

#include "../domain/Servico.h"
#include <vector>

class ServicoRepository {
    public:
        virtual ~ServicoRepository() = default;
        virtual void adicionar(const Servico& servico) = 0;
        virtual std::vector<Servico> listar() const = 0;
        virtual Servico buscarPorId(int id) = 0;
        virtual Servico buscarPorNome(const std::string& nome) const = 0;
        virtual void atualizar(const Servico& servico) = 0;
        virtual void deletar(int id) = 0;
};

#endif