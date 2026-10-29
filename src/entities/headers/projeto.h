#ifndef PROJETO_H_INCLUDED
#define PROJETO_H_INCLUDED

#include <vector>
#include "domain/headers/identificador.h"
#include "domain/headers/nome.h"
#include "domain/headers/texto.h"
#include "domain/headers/timestamp.h"

// Declarações antecipadas
class Pessoa;
class Quadro;

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
    // Pessoa responsável pelo projeto
    Pessoa* gestor;
    // Quadros pertencentes ao projeto
    vector<Quadro*> quadros;

public:
    Projeto();

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


    void setGestor(Pessoa* pessoa);
    Pessoa* getGestor();

    void adicionarQuadro(Quadro* quadro);


};

#endif // PROJETO_H_INCLUDED
