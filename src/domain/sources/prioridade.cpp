#include "prioridade.h"
#include <stdexcept>

using namespace std;

void Prioridade::validarPrioridade(string valor) {
    if (valor != "ALTA" && valor != "MEDIA" && valor != "BAIXA") {
        throw invalid_argument("Prioridade invalida: deve ser 'ALTA', 'MEDIA' ou 'BAIXA'.");
    }
}

void Prioridade::setPrioridade(string valor) {
    validarPrioridade(valor);
    this->prioridade = valor;
}


/*
bool Prioridade::validarPrioridade(string valor) {

    if (valor == "ALTA" || valor == "alta" || valor == "Alta" || valor == "MEDIA" || valor == "media" || valor == "Media" || valor == "BAIXA" || valor == "baixa" || valor == "Baixa") {
           return true;
        }
    else {
        return false;
        };
}

void Prioridade::setPrioridade(string valor) {
    if (validarPrioridade(valor)) {

       if (valor == "Alta" || valor == "alta") {
        valor = "ALTA";
    }
    else if (valor == "Media" || valor == "media"){
                valor = "MEDIA";
    }
    else if (valor == "Baixa" || valor == "baixa") {
                valor = "BAIXA";
    }
        prioridade = valor;
    }
};
*/
