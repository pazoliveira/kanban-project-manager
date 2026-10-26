#include "projeto.h"
#include "pessoa.h"
#include "quadro.h"

Projeto::Projeto() : gestor(nullptr) {
}

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

void Projeto::setGestor(Pessoa* pessoa) {
    gestor = pessoa;
}

Pessoa* Projeto::getGestor() {
    return gestor;
}

void Projeto::adicionarQuadro(Quadro* quadro) {
    if (quadro != nullptr) {
        quadros.push_back(quadro);
    }
}
