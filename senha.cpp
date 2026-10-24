#include "senha.h"
#include <string>
#include <iostream>
#include <cctype>
#include <stdexcept>


using namespace std;

void Senha::validarSenha(string valor) {
    if (valor.length() != 5) {
        throw invalid_argument("Senha Invalida. A senha deve ter exatamente 5 caracteres.");
    }

    bool temNumero = false;
    bool temLetra = false;

    for (size_t i = 0; i < valor.length(); i++) {
        char c = valor[i]; // Corrigido para ler de 'valor'

        if (isalpha(c)) {
            temLetra = true;
        } else if (isdigit(c)) {
            temNumero = true;
        }
    }

    // A verificacao final deve ocorrer APOS o loop
    if (!temNumero || !temLetra) {
        throw invalid_argument("Senha invalida. A senha deve conter numeros e letras.");
    }
}

void Senha::setSenha(string valor) {
    validarSenha(valor);
    this->senha = valor;
};
