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
            //case 3: atualizar(quadro); break;
            //case 4: listar(); break;
            //case 5: excluir(); break;
            case 0: break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}

bool CntrIUQuadro::criar(Email &gestor) {
        string entrada;
        int l; // o limite aceita somente int

        while (true) {

        Quadro quadro;
        Identificador identificador;
        Nome nome;
        Limite limite;
        Identificador identificadorProjeto;


    try {
            cout << "Identificador Quadro: ";
            getline(cin >> ws, entrada);
            identificador.setIdentificador(entrada);

            cout << "Nome: ";
            getline(cin >> ws, entrada);
            nome.setNome(entrada);

            cout << "Limite: ";
            cin >> l;
            limite.setLimite(l);

            cout << "Identificador do Projeto: ";
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
        cout << "Identificador do quadro: ";
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
