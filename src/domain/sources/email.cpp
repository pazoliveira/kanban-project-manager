#include "domain/headers/email.h"
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
    this->email = valor; 
    
}
<<<<<<< C:/Users/Oliveira/AppData/Local/Temp/ours.tmp

/*
bool Email::validar(string valor) {

    // Procura o @
    int posArroba = valor.find('@');

    // Se não existir @, é inválido
    if (posArroba == -1) {
        return false;
    }

    // Se existir mais de um @, é inválido
    if (valor.find('@', posArroba + 1) != -1) {
        return false;
    }

    // Separa parte local e domínio
    string local = valor.substr(0, posArroba);
    string dominio = valor.substr(posArroba + 1);

    // Verifica tamanho da parte local
    if (local.empty() || local.length() > 64) {
        return false;
    }

    // Verifica tamanho do domínio
    if (dominio.empty() || dominio.length() > 255) {
        return false;
    }

    // --------------------------------
    // VALIDAÇÃO DA PARTE LOCAL
    // --------------------------------

    // Não pode começar ou terminar com . ou -
    if (local[0] == '.' || local[0] == '-' ||
        local[local.length() - 1] == '.' ||
        local[local.length() - 1] == '-') {
        return false;
    }

    for (int i = 0; i < local.length(); i++) {

        char c = local[i];

        // Letras
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z')) {
            continue;
        }

        // Números
        if (c >= '0' && c <= '9') {
            continue;
        }

        // Ponto ou hífen
        if (c == '.' || c == '-') {

            // Deve ser seguido por letra ou número
            if (i + 1 >= local.length()) {
                return false;
            }

            char proximo = local[i + 1];

            if (!((proximo >= 'a' && proximo <= 'z') ||
                  (proximo >= 'A' && proximo <= 'Z') ||
                  (proximo >= '0' && proximo <= '9'))) {
                return false;
            }

            continue;
        }

        // Qualquer outro caractere é inválido
        return false;
    }

    // --------------------------------
    // VALIDAÇÃO DO DOMÍNIO
    // --------------------------------

    // Divide o domínio em partes
    int inicio = 0;

    while (inicio < dominio.length()) {

        int posPonto = dominio.find('.', inicio);

        string parte;

        if (posPonto == -1) {
            parte = dominio.substr(inicio);
        } else {
            parte = dominio.substr(inicio, posPonto - inicio);
        }

        // Parte não pode ser vazia
        if (parte.empty()) {
            return false;
        }

        // Não pode começar ou terminar com hífen
        if (parte[0] == '-' ||
            parte[parte.length() - 1] == '-') {
            return false;
        }

        // Verifica os caracteres da parte
        for (int i = 0; i < parte.length(); i++) {

            char c = parte[i];

            if ((c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9') ||
                c == '-') {
                continue;
            }

            return false;
        }

        if (posPonto == -1) {
            break;
        }

        inicio = posPonto + 1;
    }

    return true;
}

void Email::setEmail(string valor) {

    if (validar(valor)) {
        email = valor;
    }
}

*/
=======
>>>>>>> C:/Users/Oliveira/AppData/Local/Temp/theirs.tmp
