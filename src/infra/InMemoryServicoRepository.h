#ifndef INMEMORY_SERVICO_REPOSITORY_H
#define INMEMORY_SERVICO_REPOSITORY_H

#include "../Repository/ServicoRepository.h"
#include <vector>
#include <algorithm>

class InMemoryServicoRepository : public ServicoRepository {
    private:
        std::vector<Servico> servicos;
    public:
        void adicionar(const Servico& servico) override{
            servicos.push_back(servico);
        }

        std::vector<Servico> listar() const override{
            return servicos;
        }

        void atualizar(const Servico& servico) override {
            for (auto& s : servicos) {
                if (s.getId() == servico.getId()) {
                    s = servico; 
                    return;
                }
            }
        }

        void deletar(int id) override {
            servicos.erase(std::remove_if(servicos.begin(), servicos.end(),
                [id](const Servico& s) { return s.getId() == id; }), servicos.end());
        }
        Servico buscarPorId(int id) override {
            for (auto& s : servicos) {
                if (s.getId() == id) {
                    return s; 
                }
            }
            return Servico(); 
        }
        Servico buscarPorNome(const std::string& nome) const override {
            for (const auto& s : servicos) {
                if (s.getNome() == nome) {
                    return s;
                }
            }
            return Servico(); // Retorna um serviço vazio se não encontrar
        }
    };
#endif