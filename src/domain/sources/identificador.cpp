#include "identificador.h"
#include <stdexcept>
#include <cctype>

using namespace std;

void Identificador::validarIdentificador(string valor) {
    if (valor.length() != 6) {
        throw invalid_argument("Identificador deve conter exatamente 6 caracteres.");
    }
    for (int i = 0; i < 3; ++i) {
        if (!isalpha(valor[i])) {
            throw invalid_argument("Os tres primeiros caracteres devem ser letras.");
        }
    }
    for (int i = 3; i < 6; ++i) {
        if (!isdigit(valor[i])) {
            throw invalid_argument("Os tres ultimos caracteres devem ser digitos.");
        }
    }
}

void Identificador::setIdentificador(string valor) {
    validarIdentificador(valor);
    this->identificador = valor;
}
