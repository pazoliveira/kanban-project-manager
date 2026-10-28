#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

<<<<<<< C:/Users/Oliveira/AppData/Local/Temp/ours.tmp
#include "domain/headers/email.h"
#include "domain/headers/nome.h"
#include "domain/headers/senha.h"
#include "domain/headers/papel.h"

=======
#include "email.h"
#include "nome.h"
#include "senha.h"
#include "papel.h"
#include <vector>


class CartaoAtividade;
class Projeto;

using namespace std;

>>>>>>> C:/Users/Oliveira/AppData/Local/Temp/theirs.tmp
/**
 * @brief Representa o domínio Pessoa no sistema Kanban.
 * @details Valida e armazena o valor correspondente às regras de negócio.
 */
class Pessoa {
private:
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;

    vector<CartaoAtividade*> cartoesDesenvolvidos;
    vector<Projeto*> projetosGerenciados;


public:
    Pessoa();

    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setEmail(Email email);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    Email getEmail();

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
    void setSenha(Senha senha);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    Senha getSenha();

    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setPapel(Papel papel);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    Papel getPapel();


    void adicionarCartao(CartaoAtividade* cartao);
    void adicionarProjeto(Projeto* projeto);

    const vector<CartaoAtividade*>& getCartoesDesenvolvidos() const;
    const vector<Projeto*>& getProjetosGerenciados() const;

};

#endif // PESSOA_H_INCLUDED
