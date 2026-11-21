#ifndef PROJETO_H_INCLUDED
#define PROJETO_H_INCLUDED

#include "email.h"
#include "identificador.h"
#include "nome.h"
#include "texto.h"
#include "timestamp.h"

/**
 * @brief Representa o domínio Projeto no sistema Kanban.
 * @details Valida e armazena o valor correspondente às regras de negócio.
 */


class Projeto {
private:
    Identificador identificador;
    Nome nome;
    Texto descricao;
    Timestamp inicio;
    Timestamp termino;
    Email emailGestor;


public:
    Projeto() = default;

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
    void setDescricao(Texto descricao);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    Texto getDescricao();

    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setInicio(Timestamp inicio);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    Timestamp getInicio();

    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setTermino(Timestamp termino);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    Timestamp getTermino();

    /**
     * @brief Define valor referente a endereço de email do gestor do projeto.
     * @param email. valor referente ao endereço de email do gestor responsavel pelo projeto.
     */

    void setEmailGestor(Email email);

     /**
     * @brief Retorna o valor atualmente armazenado.
     * @return Objeto Email contendo o valor armazenado.
     */
    Email getEmailGestor() const;

};

#endif // PROJETO_H_INCLUDED
