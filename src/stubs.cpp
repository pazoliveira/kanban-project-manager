#include "stubs.h"

#include <iostream>
#include <stdexcept>

// -------------------------------------------------------------------------
// Definições de constantes.

const std::string StubCntrSPessoa::TRIGGER_FALHA        = "falha@teste.com";
const std::string StubCntrSPessoa::TRIGGER_ERRO_SISTEMA = "erro@teste.com";
const std::string StubCntrSProjeto::TRIGGER_ERRO_SISTEMA = "ERR999";
const std::string StubCntrSQuadro::TRIGGER_ERRO_SISTEMA = "ERR999";

// -------------------------------------------------------------------------
// Construtor: cadastra um usuário de teste para facilitar o login.

StubCntrSPessoa::StubCntrSPessoa() {
    Pessoa gestor;
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;

    email.setEmail("gestor@kanban.com");
    nome.setNome("Gestor Teste");
    senha.setSenha("abc12");
    papel.setPapel("GESTOR");

    gestor.setEmail(email);
    gestor.setNome(nome);
    gestor.setSenha(senha);
    gestor.setPapel(papel);

    pessoas[email.getEmail()] = gestor;
}

// -------------------------------------------------------------------------
// Autenticação.

bool StubCntrSPessoa::autenticar(Email email, Senha senha) {
    // Apresentar dados recebidos (útil para depurar o fluxo).
    std::cout << "\nStubCntrSPessoa::autenticar\n"
              << "Email = " << email.getEmail() << "\n"
              << "Senha = " << senha.getSenha() << "\n";

    // Comportamentos de teste conforme o email recebido.
    if (email.getEmail() == TRIGGER_FALHA)
        return false;

    if (email.getEmail() == TRIGGER_ERRO_SISTEMA)
        throw std::runtime_error("Erro de sistema");

    // Comportamento normal: confere com as pessoas cadastradas.
    auto it = pessoas.find(email.getEmail());
    if (it == pessoas.end())
        return false;                       // email não cadastrado

    return it->second.getSenha().getSenha() == senha.getSenha();
}

// -------------------------------------------------------------------------
// Cadastro.

bool StubCntrSPessoa::cadastrar(Pessoa &pessoa) {
    const std::string chave = pessoa.getEmail().getEmail();

    if (pessoas.count(chave) > 0)
        return false;                       // PK duplicada

    pessoas[chave] = pessoa;
    return true;
}

bool StubCntrSPessoa::ler(Pessoa *pessoa) {
    auto it = pessoas.find(pessoa->getEmail().getEmail());
    if (it == pessoas.end())
        return false;               // não encontrada

    *pessoa = it->second;           // preenche todos os campos
    return true;
}

bool StubCntrSPessoa::atualizar(Pessoa pessoa) {
    auto it = pessoas.find(pessoa.getEmail().getEmail());
    if (it == pessoas.end())
        return false;               // não existe para atualizar

    it->second = pessoa;
    return true;
}

bool StubCntrSPessoa::listar(vector<Pessoa> *lista) {
    lista->clear();
    for (auto& pessoa : pessoas) {
        lista->push_back(pessoa.second);
       }

    return true;
}

bool StubCntrSPessoa::excluir(Email email){

 const std::string chave = email.getEmail();

    if (chave == TRIGGER_ERRO_SISTEMA)
        throw std::runtime_error("Erro de sistema");

    return pessoas.erase(chave) > 0;       // true se removeu algo
}

// -------------------------------------------------------------------------
// Projeto.

bool StubCntrSProjeto::criar(Projeto projeto) {
    const std::string chave = projeto.getIdentificador().getIdentificador();

    if (chave == TRIGGER_ERRO_SISTEMA)
        throw std::runtime_error("Erro de sistema");

    if (projetos.count(chave) > 0)
        return false;                       // PK duplicada

    projetos[chave] = projeto;
    return true;
}

bool StubCntrSProjeto::ler(Projeto *projeto) {
    const std::string chave = projeto->getIdentificador().getIdentificador();

    if (chave == TRIGGER_ERRO_SISTEMA)
        throw std::runtime_error("Erro de sistema");

    auto it = projetos.find(chave);
    if (it == projetos.end())
        return false;                       // não encontrado

    *projeto = it->second;                  // preenche todos os campos
    return true;
}

bool StubCntrSProjeto::atualizar(Projeto projeto) {
    const std::string chave = projeto.getIdentificador().getIdentificador();

    if (chave == TRIGGER_ERRO_SISTEMA)
        throw std::runtime_error("Erro de sistema");

    auto it = projetos.find(chave);
    if (it == projetos.end())
        return false;                       // não existe para atualizar

    it->second = projeto;
    return true;
}

bool StubCntrSProjeto::listar(vector<Projeto> *lista) {
    lista->clear();
    for (auto& projeto : projetos) {
        lista->push_back(projeto.second);
       }

    return true;
}

bool StubCntrSProjeto::excluir(Identificador identificador) {
    const std::string chave = identificador.getIdentificador();

    if (chave == TRIGGER_ERRO_SISTEMA)
        throw std::runtime_error("Erro de sistema");

    return projetos.erase(chave) > 0;       // true se removeu algo
}

// -------------------------------------------------------------------------
// Quadro.

bool StubCntrSQuadro::criar(Quadro quadro) {
    const std::string chave = quadro.getIdentificador().getIdentificador();

    if (chave == TRIGGER_ERRO_SISTEMA)
        throw std::runtime_error("Erro de sistema");

    if (quadros.count(chave) > 0)
        return false;                       // PK duplicada

    quadros[chave] = quadro;
    return true;

}

bool StubCntrSQuadro::ler(Quadro *quadro) {
    std::string chave = quadro->getIdentificador().getIdentificador();

    if (chave == TRIGGER_ERRO_SISTEMA)
        throw std::runtime_error("Erro de sistema");

    auto it = quadros.find(chave);
    if (it == quadros.end())
        return false;

    *quadro = it->second;
    return true;
}

bool StubCntrSQuadro::atualizar(Quadro quadro) {
    std::string chave = quadro.getIdentificador().getIdentificador();

    if (chave == TRIGGER_ERRO_SISTEMA)
        throw std::runtime_error("Erro de sistema");

    auto it = quadros.find(chave);
    if (it == quadros.end())
        return false;

    it->second = quadro;
    return true;
}

bool StubCntrSQuadro::listar(std::vector<Quadro> *lista) {
    lista->clear();
    for (auto &quadro : quadros)
        lista->push_back(quadro.second);
    return true;
}

bool StubCntrSQuadro::excluir(Identificador identificador) {
    std::string chave = identificador.getIdentificador();

    if (chave == TRIGGER_ERRO_SISTEMA)
        throw std::runtime_error("Erro de sistema");

    return quadros.erase(chave) > 0;
}



