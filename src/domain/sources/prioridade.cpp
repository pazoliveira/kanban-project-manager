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
