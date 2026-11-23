#include "cntrIUQuadro.h"
#include "interfaces.h"
#include "quadro.h"

#include <iostream>
#include <string>

void CntrIUQuadro::executar(Email email) {
    int opcao;
    Quadro quadro;
    do {
        cout << "\n=== Quadros ===\n"
             << "1 - Criar\n"
             << "2 - Consultar\n"
             << "3 - Atualizar\n"
             << "4 - Listar\n"
             << "5 - Excluir\n"
             << "0 - Voltar\n"
             << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: criar(email); break;
            case 2: ler(&quadro); break;
            case 3: atualizar(quadro); break;
            case 4: listar(); break;
            case 5: excluir(); break;
            case 0: break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}

bool CntrIUQuadro::criar(Email &gestor) {
        string entrada;

        while (true) {

        Quadro quadro;
        Identificador identificador;
        Nome nome;
        Limite limite;
        Identificador identificadorProjeto;


    try {
            cout << "ID Quadro: ";
            getline(cin >> ws, entrada);
            identificador.setIdentificador(entrada);

            cout << "Nome: ";
            getline(cin >> ws, entrada);
            nome.setNome(entrada);

            cout << "Limite: ";
            getline(cin >> ws, entrada);
            limite.setLimite(stoi(entrada)); // converte a string para int

            cout << "ID do Projeto: ";
            getline(cin >> ws, entrada);
            identificadorProjeto.setIdentificador(entrada);

            quadro.setIdentificador(identificador);
            quadro.setNome(nome);
            quadro.setLimite(limite);
            quadro.setIdentificadorProjeto(identificadorProjeto);

        }
        catch (const invalid_argument &excecao) {
            cout << "Dado inválido: " << excecao.what() << "\n";
            cout << "Tentar novamente? (s/n): ";
            cin >> entrada;
            if (entrada != "s" && entrada != "S")
                return false;
            continue;
        }

        // Delegação ao serviço: grava o quadro.
        if (cntrSQuadro->criar(quadro)) {
            cout << "Quadro cadastrado com sucesso.\n";
            return true;
        }

        cout << "Já existe Quadro com esse Identificador.\n";
        cout << "Tentar novamente? (s/n): ";
        cin >> entrada;
        if (entrada != "s" && entrada != "S")
            return false;
        }
}

bool CntrIUQuadro::ler(Quadro*){
    string entrada;
    Identificador identificador;
    Quadro quadro;

    cout << "\n=== Consultar quadro ===\n";

    try {
        // Lê e valida o identificador (a PK do projeto).
        cout << "ID do quadro: ";
        getline(cin >> ws, entrada);
        identificador.setIdentificador(entrada);
        quadro.setIdentificador(identificador);
    }
    catch (const invalid_argument &excecao) {
        cout << "Dado inválido: " << excecao.what() << "\n";
        return false;
    }

    // Delegação ao serviço.
    if (!cntrSQuadro->ler(&quadro)) {
        cout << "Quadro não encontrado.\n";
        return false;
    }

    // Apresentação dos dados.
    cout << "\n--- Dados do quadro ---\n"
         << "ID Quadro:     " << quadro.getIdentificador().getIdentificador() << "\n"
         << "Nome:          " << quadro.getNome().getNome() << "\n"
         << "Limite:        " << quadro.getLimite().getLimite() << "\n"
         << "ID Projeto:    " << quadro.getIdentificadorProjeto().getIdentificador() << "\n"
         << "---------------------------\n";

    return true;

}

bool CntrIUQuadro::atualizar(Quadro) {

    string entrada;
    Identificador identificador;
    Quadro quadro;

    cout << "\n=== Atualizar quadro ===\n";

    // 1. Identificador e busca do quadro atual.
    try {
        cout << "Identificador (3 letras + 3 numeros, ex.: ABC123): ";
        getline(cin >> ws, entrada);
        identificador.setIdentificador(entrada);
        quadro.setIdentificador(identificador);
    }
    catch (const invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << "\n";
        return false;
    }

    if (!cntrSQuadro->ler(&quadro)) {
        cout << "Quadro não encontrado.\n";
        return false;
    }

    // 2. Novos valores (ENTER mantém o atual).
    cout << "\nDeixe em branco e tecle ENTER para manter o valor atual.\n";

    try {
        Nome nome;
        Limite limite;
        Identificador identificadorProjeto;

        cout << "Nome [" << quadro.getNome().getNome() << "]: ";
        getline(cin, entrada);
        if (!entrada.empty()) {
            nome.setNome(entrada);
            quadro.setNome(nome);
        }

        cout << "Limite [" << quadro.getLimite().getLimite() << "]: ";
        getline(cin, entrada);
        if (!entrada.empty()) {
            limite.setLimite(stoi(entrada));
            quadro.setLimite(limite);
        }

        cout << "ID Projeto [" << quadro.getIdentificadorProjeto().getIdentificador() << "]: ";
        getline(cin, entrada);
        if (!entrada.empty()) {
            identificadorProjeto.setIdentificador(entrada);
            quadro.setIdentificadorProjeto(identificadorProjeto);
        }

    }
    catch (const invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << "\n";
        cout << "Nenhuma alteracao foi gravada.\n";
        return false;
    }

    // 3. Delegação ao serviço.
    if (!cntrSQuadro->atualizar(quadro)) {
        cout << "Nao foi possivel atualizar o quadro.\n";
        return false;
    }

    cout << "Quadro atualizado com sucesso.\n";
    return true;

}

bool CntrIUQuadro::listar() {

    vector<Quadro> lista;

    cout << "\n=== Quadros cadastrados ===\n"<< endl;


    if (!cntrSQuadro->listar(&lista)) {
        cout << "Não foi possível listar os quadros cadastrados.\n";
        return false;
    }

    if (lista.empty()) {
        cout << "Nenhum quadro cadastrado.\n";
        return true;
    }

    for (Quadro &quadro : lista) {
        cout << "ID Quadro: "              << quadro.getIdentificador().getIdentificador() << "\n"
             << "Nome:  "                  << quadro.getNome().getNome() << "\n"
             << "Limite: "                 << quadro.getLimite().getLimite() << "\n"
             << "ID Projeto: "             << quadro.getIdentificadorProjeto().getIdentificador() << "\n"
             << "---------------------------\n";
    }

    return true;

}

bool CntrIUQuadro::excluir() {

    cout << "\n=== Excluir quadro ===\n";

    string entrada;
    Identificador identificador;
    Quadro quadro;

    try {
        // Lê e valida o identificador (a PK do quadro).
        cout << "ID Quadro: ";
        getline(cin >> ws, entrada);
        identificador.setIdentificador(entrada);
        quadro.setIdentificador(identificador);
    }
    catch (const invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << "\n";
        return false;
    }


    if (!cntrSQuadro->ler(&quadro)) {
        cout << "Quadro não encontrado.\n";
        return false;
    }

    if (!cntrSQuadro->excluir(identificador)) {
        cout << "Falha ao excluir quadro.\n";
        return false;
    }

    // Apresentação dos dados.
    cout << "\n--- Dados do quadro excluído ---\n"
         << "ID Quadro: "           << quadro.getIdentificador().getIdentificador() << "\n"
         << "Nome: "                << quadro.getNome().getNome() << "\n"
         << "Limite: "              << quadro.getLimite().getLimite() << "\n"
         << "ID Projeto: "          << quadro.getIdentificadorProjeto().getIdentificador() << "\n"
         << "---------------------------\n";

    return true;


}
