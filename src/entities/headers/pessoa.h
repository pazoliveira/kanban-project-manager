#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include "email.h"
#include "nome.h"
#include "senha.h"
#include "papel.h"


/**
 * @brief Representa a entidade Pessoa no sistema Kanban.
 * @details Valida e armazena os dados cadastrais e relacionamentos de uma pessoa.
 */
class Pessoa {
private:
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;


public:
    Pessoa();

    /**
     * @brief Define o email da pessoa.
     * @param email Objeto Email a ser definido.
     */
    void setEmail(Email email);

    /**
     * @brief Retorna o email da pessoa.
     * @return Objeto Email armazenado.
     */
    Email getEmail();

    /**
     * @brief Define o nome da pessoa.
     * @param nome Objeto Nome a ser definido.
     */
    void setNome(Nome nome);

    /**
     * @brief Retorna o nome da pessoa.
     * @return Objeto Nome armazenado.
     */
    Nome getNome();

    /**
     * @brief Define a senha da pessoa.
     * @param senha Objeto Senha a ser definido.
     */
    void setSenha(Senha senha);

    /**
     * @brief Retorna a senha da pessoa.
     * @return Objeto Senha armazenado.
     */
    Senha getSenha();

    /**
     * @brief Define o papel da pessoa.
     * @param papel Objeto Papel a ser definido.
     */
    void setPapel(Papel papel);

    /**
     * @brief Retorna o papel da pessoa.
     * @return Objeto Papel armazenado.
     */
    Papel getPapel();


};

#endif // PESSOA_H_INCLUDED
