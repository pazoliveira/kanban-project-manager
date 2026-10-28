#ifndef ESTADO_H_INCLUDED
#define ESTADO_H_INCLUDED
#include <string>

using namespace std;

/**
 * @brief Representa o domínio Estado no sistema Kanban.
 * @details Valida e armazena o valor correspondente às regras de negócio.
<<<<<<< C:/Users/Oliveira/AppData/Local/Temp/ours.tmp
 * Formato: A FAZER, FAZENDO, FEITO
 */
=======
 */

>>>>>>> C:/Users/Oliveira/AppData/Local/Temp/theirs.tmp
class Estado {

private:
    string estado;
    void validarEstado(string valor);

public:
<<<<<<< C:/Users/Oliveira/AppData/Local/Temp/ours.tmp
=======


>>>>>>> C:/Users/Oliveira/AppData/Local/Temp/theirs.tmp
    /**
     * @brief Define um novo valor após a validação.
     * @param valor Dado de entrada a ser validado.
     * @throw std::invalid_argument Se o valor for inválido.
     */
    void setEstado(string valor);
<<<<<<< C:/Users/Oliveira/AppData/Local/Temp/ours.tmp
    /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
    string getEstado() const;
=======

     /**
     * @brief Retorna o valor atualmente armazenado.
     * @return String contendo o valor.
     */
     string getEstado() const;
>>>>>>> C:/Users/Oliveira/AppData/Local/Temp/theirs.tmp
};


inline string Estado::getEstado() const {
    return estado;
};

#endif // ESTADO_H_INCLUDED
