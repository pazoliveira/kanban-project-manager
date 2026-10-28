#include "domain/headers/timestamp.h"
#include <cctype>
#include <stdexcept>

using namespace std;

// Construtor padrão corrigido para Timestamp::Timestamp
Timestamp::Timestamp() {
    this->valor = "";
}

// Construtor com parâmetro corrigido para Timestamp::Timestamp
Timestamp::Timestamp(string valor) {
    setDataHora(valor);
}

bool Timestamp::ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

void Timestamp::validarTimestamp(string valor) {
    // Procura os separadores '-' e ':'
    size_t pos1 = valor.find('-');
    size_t pos2 = (pos1 != string::npos) ? valor.find('-', pos1 + 1) : string::npos;
    size_t pos3 = (pos2 != string::npos) ? valor.find('-', pos2 + 1) : string::npos;
    size_t posColon = (pos3 != string::npos) ? valor.find(':', pos3 + 1) : string::npos;

    // Garante que existem exatamente 3 hífens e 1 dois-pontos nos lugares corretos
    if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos || posColon == string::npos) {
        throw invalid_argument("Data e horario invalidos. Formato correto: DIA-MES-ANO-HORARIO.");
    }

    string sDia = valor.substr(0, pos1);
    string sMes = valor.substr(pos1 + 1, pos2 - (pos1 + 1));
    string sAno = valor.substr(pos2 + 1, pos3 - (pos2 + 1));
    string sHoraCompleta = valor.substr(pos3 + 1);

    // 1. Validação do ANO (2000 a 2099)
    if (sAno.length() != 4) {
        throw invalid_argument("Data invalida. O ano deve conter exatamente 4 digitos.");
    }
    for (char c : sAno) {
        if (!isdigit(c)) {
            throw invalid_argument("Data invalida. O ano deve conter apenas digitos.");
        }
    }
    int ano = stoi(sAno);
    if (ano < 2000 || ano > 2099) {
        throw invalid_argument("Data invalida. O ano deve estar entre 2000 e 2099.");
    }

    // 2. Validação do MÊS (Siglas permitidas)
    if (sMes != "JAN" && sMes != "FEV" && sMes != "MAR" && sMes != "ABR" &&
        sMes != "MAI" && sMes != "JUN" && sMes != "JUL" && sMes != "AGO" &&
        sMes != "SET" && sMes != "OUT" && sMes != "NOV" && sMes != "DEZ") {
        throw invalid_argument("Data invalida. Mes deve ser uma sigla em maiusculo (ex: JAN, FEV).");
    }

    // 3. Validação do DIA (1 a 31 + Regra de Bissexto)
    if (sDia.empty() || sDia.length() > 2) {
        throw invalid_argument("Data invalida. Dia incorreto.");
    }
    for (char c : sDia) {
        if (!isdigit(c)) {
            throw invalid_argument("Data invalida. O dia deve conter apenas numeros.");
        }
    }
    int dia = stoi(sDia);

    int maxDias = 31;
    if (sMes == "FEV") {
        maxDias = ehBissexto(ano) ? 29 : 28;
    } else if (sMes == "ABR" || sMes == "JUN" || sMes == "SET" || sMes == "NOV") {
        maxDias = 30;
    }

    if (dia < 1 || dia > maxDias) {
        throw invalid_argument("Data invalida. Dia fora do limite permitido para o mes/ano informado.");
    }

    // 4. Validação do HORÁRIO (00:00 a 23:59)
    if (sHoraCompleta.length() != 5 || sHoraCompleta[2] != ':') {
        throw invalid_argument("Horario invalido. Use o formato HH:MM (ex: 14:30).");
    }

    string sH = sHoraCompleta.substr(0, 2);
    string sM = sHoraCompleta.substr(3, 2);

    for (char c : sH) {
        if (!isdigit(c)) throw invalid_argument("Horario invalido. As horas devem ser numericas.");
    }
    for (char c : sM) {
        if (!isdigit(c)) throw invalid_argument("Horario invalido. Os minutos devem ser numericos.");
    }

    int hora = stoi(sH);
    int minuto = stoi(sM);

    if (hora < 0 || hora > 23) {
        throw invalid_argument("Horario invalido. A hora deve estar entre 00 e 23.");
    }
    if (minuto < 0 || minuto > 59) {
        throw invalid_argument("Horario invalido. Os minutos devem estar entre 00 e 59.");
    }
}

void Timestamp::setDataHora(string valor) {
    validarTimestamp(valor);
    this->valor = valor;
}

string Timestamp::getDataHora() const {
    return this->valor;
}
