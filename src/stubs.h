#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <map>
#include <string>

#include "interfaces.h"
#include "pessoa.h"
#include "projeto.h"

using namespace std;

/**
 * @brief Stub do serviço de Pessoa (autenticação e cadastro).
 * @details Armazena as pessoas em memória, usando o valor do Email
 *          (PK) como chave. Possui emails-gatilho para simular
 *          falha de autenticação e erro de sistema.
 */
class StubCntrSPessoa: public InterfaceServicoAutenticacao, public InterfaceServicoPessoa {
private:
    map<string, Pessoa> pessoas;   // conteiner para armazenar os obejtos pessoas

public:
    // Emails-gatilho para testes.
    static const string TRIGGER_FALHA;
    static const string TRIGGER_ERRO_SISTEMA;

    StubCntrSPessoa(); //construtor

    bool autenticar(Email email, Senha senha) override;
    bool cadastrar(Pessoa &pessoa);
    bool ler(Pessoa *pessoa) override;
    bool atualizar(Pessoa pessoa) override;
    bool listar(vector<Pessoa> *lista) override;
    bool excluir(Email email) override;
};

/**
 * @brief Stub do serviço de Projeto, com armazenamento em memória.
 * @details A chave do mapa é o valor do Identificador (PK de Projeto).
 */
class StubCntrSProjeto : public InterfaceServicoProjeto {
private:
    map<string, Projeto> projetos;   // identificador -> Projeto

public:
    // Identificadores-gatilho para testes.
    static const string TRIGGER_ERRO_SISTEMA;

    bool criar(Projeto projeto) override;
    bool ler(Projeto *projeto) override;
    bool atualizar(Projeto projeto) override;
    bool listar(vector<Projeto> *lista) override;
    bool excluir(Identificador identificador) override;
};

/**
 * @brief Stub do serviço de Quadro, com armazenamento em memória.
 * @details A chave do mapa é o valor do Identificador (PK de Quadro).
 */
class StubCntrSQuadro: public InterfaceServicoQuadro {

private:
    map<string, Quadro> quadros;   // identificador -> Quadro

public:
    // Identificadores-gatilho para testes.
    static const string TRIGGER_ERRO_SISTEMA;

    bool criar(Quadro quadro) override;
    bool ler(Quadro *quadro) override;
    bool atualizar(Quadro quadro) override;
    bool listar(vector<Quadro> *lista) override;
    bool excluir(Identificador identificador) override;

};

#endif // STUBS_H_INCLUDED
