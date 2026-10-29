#ifndef TAMANHO_H_INCLUDED
#define TAMANHO_H_INCLUDED
#include <string>

using namespace std;

/**
 * @brief Representa o domínio Tamanho no sistema Kanban.
 * @details Valida e armazena o valor correspondente às regras de negócio.
 * Formato: GRANDE, MÉDIO, PEQUENO
 */
class Tamanho {

private:
    string tamanho;
    void validarTamanho(string valor);

public:
    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setTamanho(string valor);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    string getTamanho() const;
};


inline string Tamanho::getTamanho() const {
    return tamanho;
};

#endif // TAMANHO_H_INCLUDED
