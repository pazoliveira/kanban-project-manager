#include "quadro.h"
#include "quadro.h"
#include "projeto.h"
#include "cartao_atividade.h"
#include "identificador.h"

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


void Quadro::setIdentificadorProjeto(Identificador identificador) {
    this->identificadorProjeto = identificador;
}

Identificador Quadro::getIdentificadorProjeto() const {
    return identificadorProjeto;
}




