#include "pessoa.h"
#include "papel.h"
#include "cartao_atividade.h"
#include "projeto.h"


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


