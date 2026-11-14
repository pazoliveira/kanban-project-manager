#include "limite.h"
#include <stdexcept>

void Limite::setLimite(int valor) {
    validarLimite(valor);
    this->limite = valor;
}


void Limite::validarLimite(int valor) {
    if(valor < 1 || valor > 25 )
        throw invalid_argument("Erro de argumento. Informe um valor entre 1 e 25 e tente novamente.");
};
