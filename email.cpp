#include "email.h"
#include <cctype>
#include <stdexcept>

using namespace std;

void Email::validarEmail(string valor) {
    size_t posArroba = valor.find('@');
    if (posArroba == string::npos || posArroba == valor.rfind('@')) {
        throw invalid_argument("E-mail invalido. Deve conter apenas 1 '@'.");
    }

    string local = valor.substr(0, posArroba);
    string dominio = valor.substr(posArroba + 1);

    // Validação da parte Local
    if (local.empty() || local.length() > 64) {
        throw invalid_argument("E-mail invalido. Deve conter entre 1 e 64 caracteres na parte local.");
    }

    char char_um = local[0];
    char char_fim = local[local.length() - 1];

    if (char_um == '.' || char_um == '-' || char_fim == '.' || char_fim == '-') {
        throw invalid_argument("E-mail invalido. Nao pode haver nem no inicio e nem no fim os caracteres '-' e '.'.");
    }

    for (size_t i = 0; i < local.length(); i++) {
        char c = local[i];
        if (!isalnum(c) && c != '.' && c != '-') {
            throw invalid_argument("E-mail invalido. Deve conter apenas letras, numeros, o sinal '.' ou o sinal '-'.");
        }

        if (c == '.' || c == '-') {
            if (i + 1 >= local.length() || !isalnum(local[i + 1])) {
                throw invalid_argument("E-mail invalido. Apos os caracteres '.' e '-' deve conter uma letra ou numero.");
            }
        }
    }

    // Validação do Domínio (agora dentro da função!)
    size_t inicio = 0;
    while (inicio < dominio.length()) {
        size_t fim = dominio.find('.', inicio);
        if (fim == string::npos) {
            fim = dominio.length();
        }

        string parteDominio = dominio.substr(inicio, fim - inicio);

        if (parteDominio.empty()) {
            throw invalid_argument("Email invalido. Parte do dominio nao pode ser vazia.");
        }

        if (parteDominio[0] == '-' || parteDominio[parteDominio.length() - 1] == '-') {
            throw invalid_argument("Email invalido. Parte do dominio nao pode iniciar ou terminar com hifen.");
        }

        for (char c : parteDominio) {
            if (!isalnum(c) && c != '-') {
                throw invalid_argument("Email invalido. Caractere invalido no dominio.");
            }
        }

        inicio = fim + 1;
    }
}

void Email::setEmail(string valor) {
    validarEmail(valor);
    this->email = valor; // Corrigido de 'valor' para 'email' conforme o .h
}
