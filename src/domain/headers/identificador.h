#ifndef IDENTIFICADOR_H_INCLUDED
#define IDENTIFICADOR_H_INCLUDED
#include <string>

using namespace std;

/**
 * @brief Representa o domínio Identificador no sistema Kanban.
 * @details Valida e armazena o valor correspondente às regras de negócio.
 * Formato: 6 caracteres
 * Sendo letras (a-z ou A-Z) os três primeiros caracteres.
 * Sendo dígitos (0-9) os três últimos caracteres.
 */
class Identificador {
private:
    string identificador;
    void validarIdentificador (string);

public:
    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setIdentificador(string);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    string getIdentificador() const;

};

inline string Identificador::getIdentificador() const {
    return identificador;
};

#endif // IDENTIFICADOR_H_INCLUDED
