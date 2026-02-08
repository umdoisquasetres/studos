#ifndef CLIENTES_H
#define CLIENTES_H

#include <string>
class Cliente{
private:
    int id;
    std::string nome;
    std::string cpfCnpj;
    std::string email;
    std::string telefone;
    std::string endereco;
public:
    Cliente();
    Cliente(const int id, const std::string& nome, const std::string& cpfCnpj, const std::string& email, const std::string& telefone, const std::string& endereco);

    // --- GETTERS (Para ler os dados) ---
    int getId() const { return id; }
    std::string getNome() const { return nome; }
    std::string getCpfCnpj() const { return cpfCnpj; }
    std::string getEmail() const { return email; }
    std::string getTelefone() const { return telefone; }
    std::string getEndereco() const { return endereco; }

    // --- SETTERS (Para alterar os dados depois de criar) ---
    void setId(int novoId) { id = novoId; }
    void setNome(const std::string& novoNome) { nome = novoNome; }
    void setCpfCnpj(const std::string& novoDoc) { cpfCnpj = novoDoc; }
    void setEmail(const std::string& novoEmail) { email = novoEmail; }
    void setTelefone(const std::string& novoTel) { telefone = novoTel; }
    void setEndereco(const std::string& novoEnd) { endereco = novoEnd; }

    void exibir() const;
};

#endif