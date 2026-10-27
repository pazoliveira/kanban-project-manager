#ifndef PRIORIDADE_H_INCLUDED
#define PRIORIDADE_H_INCLUDED
#include <string>

using namespace std;

/**
 * @brief Representa o domínio Prioridade no sistema Kanban.
 * @details Valida e armazena o valor correspondente às regras de negócio.
 * Formato: ALTA, MEDIA, BAIXA
 */
class Prioridade {

private:
    string prioridade;
    void validarPrioridade(string valor);

public:
    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setPrioridade(string valor);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    string getPrioridade() const;
};


inline string Prioridade::getPrioridade() const {
    return prioridade;
};

#endif // PRIORIDADE_H_INCLUDED
