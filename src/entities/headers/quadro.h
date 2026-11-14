#ifndef QUADRO_H_INCLUDED
#define QUADRO_H_INCLUDED


#include "identificador.h"
#include "nome.h"
#include "limite.h"


/**
 * @brief Representa o domínio Quadro no sistema Kanban.
 * @details Valida e armazena o valor correspondente às regras de negócio.
 */

class Quadro {
private:
    Identificador identificador;
    Nome nome;
    Limite limite;
    Identificador identificadorProjeto;


public:
    Quadro();

    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setIdentificador(Identificador identificador);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    Identificador getIdentificador();

    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setNome(Nome nome);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    Nome getNome();

    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setLimite(Limite limite);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    Limite getLimite();


    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
     void setIdentificadorProjeto(Identificador identificadorProjeto);


     /**
     * @brief Retorna o valor atualmente armazenado.
     * @return Obejto tipo Identificador contendo o valor.
     */
    Identificador getIdentificadorProjeto() const;

};

#endif // QUADRO_H_INCLUDED
