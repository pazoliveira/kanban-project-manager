#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <vector>
#include "domain/headers/email.h"
#include "domain/headers/nome.h"
#include "domain/headers/senha.h"
#include "domain/headers/papel.h"

// Declarações antecipadas
class CartaoAtividade;
class Projeto;

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
    // Cartões desenvolvidos pela pessoa
    std::vector<CartaoAtividade*> cartoesDesenvolvidos;
    // Projetos gerenciados pela pessoa
    std::vector<Projeto*> projetosGerenciados;

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

    /**
     * @brief Adiciona um cartão de atividade à lista de cartões desenvolvidos.
     * @param cartao Ponteiro para o CartaoAtividade.
     */
    void adicionarCartao(CartaoAtividade* cartao);

    /**
     * @brief Adiciona um projeto à lista de projetos gerenciados.
     * @param projeto Ponteiro para o Projeto.
     */
    void adicionarProjeto(Projeto* projeto);

    /**
     * @brief Retorna os cartões desenvolvidos pela pessoa.
     * @return Referência constante para o vetor de ponteiros de CartaoAtividade.
     */
    const std::vector<CartaoAtividade*>& getCartoesDesenvolvidos() const;

    /**
     * @brief Retorna os projetos gerenciados pela pessoa.
     * @return Referência constante para o vetor de ponteiros de Projeto.
     */
    const std::vector<Projeto*>& getProjetosGerenciados() const;
};

#endif // PESSOA_H_INCLUDED