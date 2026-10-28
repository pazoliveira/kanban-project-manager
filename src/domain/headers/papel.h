#ifndef PAPEL_H_INCLUDED
#define PAPEL_H_INCLUDED
#include <string>

using namespace std;

/**
 * @brief Representa o domínio Papel no sistema Kanban.
 * @details Valida e armazena o valor correspondente às regras de negócio.
<<<<<<< C:/Users/Oliveira/AppData/Local/Temp/ours.tmp
 * Formato: GESTOR, DESENVOLVEDOR
=======
>>>>>>> C:/Users/Oliveira/AppData/Local/Temp/theirs.tmp
 */
class Papel {

private:
    string papel;
    void validarPapel(string valor);

public:
    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setPapel(string valor);
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    string getPapel() const;
};


inline string Papel::getPapel() const {
    return papel;
};


#endif // PAPEL_H_INCLUDED
