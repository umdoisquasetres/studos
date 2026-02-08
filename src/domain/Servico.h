#ifndef SERVICOS_H
#define SERVICOS_H

#include <string>

class Servico{
    private:
        int id;
        std::string nome;
        std::string descricao;
        double preco;

    public:
        Servico() : id(0), nome(""), descricao(""), preco(0.0) {}
        Servico(int id, const std::string& nome, const std::string& descricao, double preco)
            : id(id), nome(nome), descricao(descricao), preco(preco) {}

        int getId() const { return id; }
        void setId(int newId) { id = newId; }

        std::string getNome() const { return nome; }
        void setNome(const std::string& newNome) { nome = newNome; }

        std::string getDescricao() const { return descricao; }
        void setDescricao(const std::string& newDescricao) { descricao = newDescricao; }

        double getPreco() const { return preco; }
        void setPreco(double newPreco) { preco = newPreco; }

        void exibir() const;
};

#endif