#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED
#include <string>

using namespace std;
/// @brief Classe de domínio que representa um e-mail
/// Formato: parte-local@domínio
/// Parte local pode conter letra (a-z), dígito (0-9) ou ponto(.) ou hífen (-); não pode iniciar ou terminar com ponto ou hífen; ponto ou hífen deve ser seguido por letra(s) ou dígito(s); comprimento máximo é 64 caracteres.
/// Domínio é composto por uma ou mais partes separadas por ponto (.); cada parte pode conter letra (a-z), dígito (0-9) ou hífen (-); não pode iniciar ou terminar com hífen; comprimento máximo é 255 caracteres.

class Email {

private:
    string email;
    void validarEmail(string valor);
    void validarEmail(string valor);

public:
    ///@brief Atribui um valor ao e-mail apos validação.
    ///@param valor String contendo o endereço de e-mail.
    ///@throws std::invalid_argument Se o formato de e-mail for inválido.
    void setEmail(string valor);

    ///@brief Retorna o valor do e-mail.
    ///@return std::string valor do e-mail.
    string getEmail();
};

inline string Email::getEmail() {
    return email;
}

#endif // EMAIL_H_INCLUDED
