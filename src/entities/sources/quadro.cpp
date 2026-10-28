#include "entities/headers/quadro.h"
#include "entities/headers/quadro.h"
#include "entities/headers/projeto.h"
#include "entities/headers/cartao_atividade.h"

Quadro::Quadro() {
}

void Quadro::setIdentificador(Identificador identificador) {
    this->identificador = identificador;
}

Identificador Quadro::getIdentificador() {
    return identificador;
}

void Quadro::setNome(Nome nome) {
    this->nome = nome;
}

Nome Quadro::getNome() {
    return nome;
}

void Quadro::setLimite(Limite limite) {
    this->limite = limite;
}

Limite Quadro::getLimite() {
    return limite;
}


void Quadro::setProjeto(Projeto* projeto) {
    projeto = projeto;
}

Projeto* Quadro::getProjeto() {
    return projeto;
}

void Quadro::adicionarCartao(CartaoAtividade* cartao) {
    if (cartao != nullptr) {
        cartoes.push_back(cartao);
    }
}





