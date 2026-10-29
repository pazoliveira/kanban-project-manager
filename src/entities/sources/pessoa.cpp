
#include "entities/headers/pessoa.h"
#include "domain/headers/papel.h"
#include "entities/headers/cartao_atividade.h"
#include "entities/headers/projeto.h"
#include <vector>

class Projeto;
class CartaoAtividade;
class Quadro;

Pessoa::Pessoa() {
}

void Pessoa::setEmail(Email email) {
    this->email = email;
}

Email Pessoa::getEmail() {
    return email;
}

void Pessoa::setNome(Nome nome) {
    this->nome = nome;
}

Nome Pessoa::getNome() {
    return nome;
}

void Pessoa::setSenha(Senha senha) {
    this->senha = senha;
}

Senha Pessoa::getSenha() {
    return senha;
}

void Pessoa::setPapel(Papel papel) {
    this->papel = papel;
}

Papel Pessoa::getPapel() {
    return papel;
}

void Pessoa::adicionarCartao(CartaoAtividade* cartao) {
    if (cartao != nullptr) {
        cartoesDesenvolvidos.push_back(cartao);
    }
}

void Pessoa::adicionarProjeto(Projeto* projeto) {
    if (projeto != nullptr) {
        projetosGerenciados.push_back(projeto);
    }
}

const std::vector<CartaoAtividade*>& Pessoa::getCartoesDesenvolvidos() const {
    return cartoesDesenvolvidos;
}

const std::vector<Projeto*>& Pessoa::getProjetosGerenciados() const {
    return projetosGerenciados;
}