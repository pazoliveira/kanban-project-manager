#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED
#include <string>

using namespace std;
/// @brief Classe de domínio que representa um endereço de e-mail.

class Email {

private:
    string email;
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
