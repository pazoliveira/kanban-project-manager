#include "papel.h"
#include <stdexcept>

using namespace std;

void Papel::validarPapel(string valor) {
    if (valor != "GESTOR" && valor != "DESENVOLVEDOR") {
        throw invalid_argument("Papel invalido: deve ser 'GESTOR' ou 'DESENVOLVEDOR'.");
    }
}

void Papel::setPapel(string valor) {
    validarPapel(valor);
    this->papel = valor;
}
/*
bool Papel::validarPapel(string valor) {

    if (valor == "Gestor" || valor == "Desenvolvedor") {
           return true;
        }
    else {
        return false;
        };
}

void Papel::setPapel(string valor) {
    if (validarPapel(valor)) {
        papel = valor;
    }
};
*/
