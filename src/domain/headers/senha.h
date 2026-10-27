#ifndef SENHA_H_INCLUDED
#define SENHA_H_INCLUDED

#include <string>

using namespace std;

/**
 * @brief Representa o domínio Senha no sistema Kanban.
 * @details Valida e armazena o valor correspondente às regras de negócio.
 * Formato: 5 caracteres
 * Caractere pode ser letra (a-z ou A-Z) ou dígito (0-9); existe pelo menos uma letra e um dígito.
 */
class Senha {
private:
    string senha;
    void validarSenha(string valor);

public:
    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setSenha(string valor);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    string getSenha() const;
};

inline string Senha::getSenha() const {
    return senha; // Corrigido de 'valor' para 'senha'
}

#endif // SENHA_H_INCLUDED

/*
/**
 * @brief Representa o domínio Senha no sistema Kanban.
 * @details Valida e armazena o valor correspondente às regras de negócio.
 */
class Senha {
private:
    string valor;
    void validarSenha(string);
    bool temNumero(string);
    bool temLetra(string);


public:
    const static int SENHA_INVALIDA = 12345;
    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setValor(string);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    string getValor() const;
};

inline string Senha::getValor() const {
    return valor;
};
*/

