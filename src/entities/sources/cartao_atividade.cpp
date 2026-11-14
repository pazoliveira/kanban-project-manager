#include "cartao_atividade.h"
#include "cartao_atividade.h"
#include "pessoa.h"
#include "quadro.h"


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

void CartaoAtividade::setEmailDesenvolvedor(Email email){
    this->emailDesenvolvedor = email;
}

Email CartaoAtividade::getEmailDesenvolvedor() const {
    return emailDesenvolvedor;
}

void CartaoAtividade::setIdentificadorQuadro(Identificador identificadorQuadro) {
    this->identificadorQuadro = identificadorQuadro;
}


Identificador CartaoAtividade::getIdentificadorQuadro() const{
    return identificadorQuadro;
}


