#include "entities/headers/cartao_atividade.h"
#include "entities/headers/cartao_atividade.h"
#include "entities/headers/pessoa.h"
#include "entities/headers/quadro.h"
#include <vector>

CartaoAtividade::CartaoAtividade() {
}

void CartaoAtividade::setIdentificador(Identificador identificador) {
    this->identificador = identificador;
}

Identificador CartaoAtividade::getIdentificador() {
    return identificador;
}

void CartaoAtividade::setNome(Nome nome) {
    this->nome = nome;
}

Nome CartaoAtividade::getNome() {
    return nome;
}

void CartaoAtividade::setDescricao(Texto descricao) {
    this->descricao = descricao;
}

Texto CartaoAtividade::getDescricao() {
    return descricao;
}

void CartaoAtividade::setPrioridade(Prioridade prioridade) {
    this->prioridade = prioridade;
}

Prioridade CartaoAtividade::getPrioridade() {
    return prioridade;
}

void CartaoAtividade::setEstado(Estado estado) {
    this->estado = estado;
}

Estado CartaoAtividade::getEstado() {
    return estado;
}

void CartaoAtividade::setTamanho(Tamanho tamanho) {
    this->tamanho = tamanho;
}

Tamanho CartaoAtividade::getTamanho() {
    return tamanho;
}

void CartaoAtividade::setEntrada(Timestamp entrada) {
    this->entrada = entrada;
}

Timestamp CartaoAtividade::getEntrada() {
    return entrada;
}

void CartaoAtividade::setInicio(Timestamp inicio) {
    this->inicio = inicio;
}

Timestamp CartaoAtividade::getInicio() {
    return inicio;
}

void CartaoAtividade::setTermino(Timestamp termino) {
    this->termino = termino;
}

Timestamp CartaoAtividade::getTermino() {
    return termino;
}

void CartaoAtividade::setDesenvolvedor(Pessoa* pessoa) {
    desenvolvedor = pessoa;
}

Pessoa* CartaoAtividade::getDesenvolvedor() {
    return desenvolvedor;
}

void CartaoAtividade::setQuadro(Quadro* quadro) {
    this->quadro = quadro;
}

Quadro* CartaoAtividade::getQuadro() {
    return quadro;
}
