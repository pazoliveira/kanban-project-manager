#include "stubs.h"

#include <iostream>
#include <stdexcept>

// -------------------------------------------------------------------------
// Definições de constantes.

const std::string StubCntrSPessoa::TRIGGER_FALHA        = "falha@teste.com";
const std::string StubCntrSPessoa::TRIGGER_ERRO_SISTEMA = "erro@teste.com";

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
    senha.setSenha("Abc12");
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
