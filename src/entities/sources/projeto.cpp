#include "projeto.h"
#include "projeto.h"
#include "pessoa.h"
#include "quadro.h"
#include "email.h"

void Projeto::setIdentificador(Identificador identificador) {
    this->identificador = identificador;
}

Identificador Projeto::getIdentificador() {
    return identificador;
}

void Projeto::setNome(Nome nome) {
    this->nome = nome;
}

Nome Projeto::getNome() {
    return nome;
}

void Projeto::setDescricao(Texto descricao) {
    this->descricao = descricao;
}

Texto Projeto::getDescricao() {
    return descricao;
}

void Projeto::setInicio(Timestamp inicio) {
    this->inicio = inicio;
}

Timestamp Projeto::getInicio() {
    return inicio;
}

void Projeto::setTermino(Timestamp termino) {
    this->termino = termino;
}

Timestamp Projeto::getTermino() {
    return termino;
}

void Projeto::setEmailGestor(Email email) {
    this->emailGestor = email;
}

Email Projeto::getEmailGestor() const {
    return emailGestor;
}
