#ifndef NOME_H_INCLUDED
#define NOME_H_INCLUDED
#include <string>

using namespace std;

/**
 * @brief Representa o domínio Nome no sistema Kanban.
 * @details Valida e armazena o valor correspondente às regras de negócio.
 * Formato: Texto com até 15 caracteres.
 * Caractere pode ser letra maiúscula (A-Z), letra minúscula (a-z) ou espaço em branco; espaço em
 * branco é seguido por letra; primeiro caractere não é espaço em branco; último caractere não é
 * espaço em branco.
 */
class Nome {

private:
    string nome;
    void validarNome(string valor);

public:
    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setNome(string valor);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    string getNome() const;
};

inline string Nome::getNome() const {
    return nome;
};
#endif // NOME_H_INCLUDED
