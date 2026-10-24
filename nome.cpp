#include "nome.h"
#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

void Nome::validarNome(string valor) {

    if (valor.empty() || valor.size() > 15 || valor.front() == ' ' || valor.back() == ' ') {
       throw invalid_argument("Nome inválido. Nome deve ter entre 1 e 15 caracteres e nem o primeiro nem o último caractere podem ser espaços em branco.");
    }
    for (size_t i = 0; i < valor.length(); i++) {
        char letra= valor[i];
        if (!isalpha(letra) && letra != ' '){
            throw invalid_argument("Nome inválido. Deve ter apenas letras e espaços vazios.");
        }
        if (letra == ' ' && !isalpha(valor[i + 1])) {
            throw invalid_argument("Nome inválido. Espaço em branco deve ser seguido de letra ");
        }
   }
}

void Nome::setNome(string valor) {
    validarNome(valor);
    this->nome = valor;

};
