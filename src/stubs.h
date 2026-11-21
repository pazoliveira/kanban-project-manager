#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <map>
#include <string>

#include "interfaces.h"
#include "pessoa.h"

/**
 * @brief Stub do serviço de Pessoa (autenticação e cadastro).
 * @details Armazena as pessoas em memória, usando o valor do Email
 *          (PK) como chave. Possui emails-gatilho para simular
 *          falha de autenticação e erro de sistema.
 */
class StubCntrSPessoa: public InterfaceServicoAutenticacao, public InterfaceServicoPessoa {
private:
    std::map<std::string, Pessoa> pessoas;   // conteiner para armazenar os obejtos pessoas

public:
    // Emails-gatilho para testes.
    static const std::string TRIGGER_FALHA;
    static const std::string TRIGGER_ERRO_SISTEMA;

    StubCntrSPessoa();

    bool autenticar(Email email, Senha senha) override;
    bool cadastrar(Pessoa &pessoa);
};

#endif // STUBS_H_INCLUDED
