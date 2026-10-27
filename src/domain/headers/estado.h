#ifndef ESTADO_H_INCLUDED
#define ESTADO_H_INCLUDED
#include <string>

using namespace std;

/**
 * @brief Representa o domínio Estado no sistema Kanban.
 * @details Valida e armazena o valor correspondente às regras de negócio.
 * Formato: A FAZER, FAZENDO, FEITO
 */
class Estado {

private:
    string estado;
    void validarEstado(string valor);

public:
    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setEstado(string valor);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    string getEstado() const;
};


inline string Estado::getEstado() const {
    return estado;
};

#endif // ESTADO_H_INCLUDED
