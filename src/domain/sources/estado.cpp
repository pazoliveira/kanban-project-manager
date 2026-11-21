#include "estado.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>

using namespace std;

void Estado::validarEstado(string valor) {

    for (size_t i = 0; i < valor.length(); i++) {
        valor[i] = toupper(static_cast<unsigned char>(valor[i]));
    }

    if (valor != "A FAZER" && valor != "FAZENDO" && valor != "FEITO") {
        throw invalid_argument("Estado inválido. Deve ser A FAZER, FAZENDO ou FEITO.");
    }
}

void Estado::setEstado(string valor){
    validarEstado(valor);

    for (size_t i = 0; i < valor.length(); i++) {
        valor[i] = toupper(static_cast<unsigned char>(valor[i]));
    }

    this->estado = valor;
}
