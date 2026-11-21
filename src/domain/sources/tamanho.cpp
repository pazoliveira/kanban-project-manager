#include "tamanho.h"
#include <stdexcept>

using namespace std;

void Tamanho::validarTamanho(string valor) {
    if (valor != "GRANDE" && valor != "MÉDIO" && valor != "PEQUENO") {
        throw invalid_argument("Tamanho invalido: deve ser 'GRANDE', 'MÉDIO' ou 'PEQUENO'.");
    }
}

void Tamanho::setTamanho(string valor) {
    validarTamanho(valor);
    this->tamanho = valor;
};
