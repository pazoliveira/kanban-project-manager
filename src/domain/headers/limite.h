#ifndef LIMITE_H_INCLUDED
#define LIMITE_H_INCLUDED

using namespace std;

/**
 * @brief Representa o domínio Limite no sistema Kanban.
 * @details Valida e armazena o valor correspondente às regras de negócio.
 * Formato: 1 a 25
 
 */
class Limite {

private:
    int limite ;
    void validarLimite(int valor);

public:
    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setLimite(int valor);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    int getLimite() const;
};


inline int Limite::getLimite() const {
    return limite;
};

#endif // LIMITE_H_INCLUDED
