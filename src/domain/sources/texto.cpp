#include "texto.h"
#include <cctype>
#include <stdexcept>

using namespace std;

void Texto::validarTexto (string texto) {
    if (texto.empty() || texto.size() > 30) {
        throw invalid_argument("Texto inválido. Texto vazio ou maior que 30 caracteres.");
    }

    if (!isupper(texto[0]) || texto[texto.size() - 1] != '.') {
        throw invalid_argument("Texto inválido. Deve-se iniciar a frase com letra maiúscula e finalizar o texto com '.' .");
    }

    for (size_t i = 0; i < texto.size(); i++) {
        char c = texto[i];

        if (c == ',' || c == '.' || c == ';' || c == ':' || c == '?' || c == '!') {
            if (i + 1 < texto.size()) {
                char proximo = texto[i + 1];

                if (proximo == ',' || proximo == '.' || proximo == ';' || proximo == ':' || proximo == '?' || proximo == '!') {
                    throw invalid_argument("Texto inválido. Não deve haver dois sinais de pontuações seguidos.");
                }
            }
        }
    }
}

void Texto::setTexto(string valor) {
    validarTexto(valor);
    this->texto = valor;
}
