#ifndef DATAHORA_H
#define DATAHORA_H

#include <string>

using namespace std;

///
/// @brief Classe de domínio para representação de Data e Horário.
///
/// Formato esperado: DIA-MES-ANO-HORARIO (ex: 29-FEV-2024-14:30)
/// - DIA: 1 a 31 (respeitando o mes e ano bissexto)
/// - MES: JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ
/// - ANO: 2000 a 2099
/// - HORARIO: 00:00 a 23:59
///
class Timestamp {
private:
    string valor;

    ///
    /// @brief Valida se o formato e os valores da data/horario sao validos.
    /// @param valor String no formato DIA-MES-ANO-HORARIO.
    /// @throw std::invalid_argument Se o valor for invalido.
    ///
    void validarTimestamp(string valor);

    ///
    /// @brief Auxiliar para checar se o ano e bissexto.
    ///
    bool ehBissexto(int ano);

public:
    ///
    /// @brief Construtor padrao da classe Timestamp.
    ///
    Timestamp();

    ///
    /// @brief Construtor que inicializa com valor e aplica validação.
    /// @param valor String com a data e horário.
    ///
    Timestamp(string valor);

    ///
    /// @brief Define um novo valor para a data/horario apos validar.
    /// @param valor String no formato DIA-MES-ANO-HORARIO.
    ///
    void setDataHora(string valor);

    ///
    /// @brief Retorna a data/horário armazenada.
    /// @return string O valor atual.
    ///
    string getDataHora() const;
};


#endif // DATAHORA_H
