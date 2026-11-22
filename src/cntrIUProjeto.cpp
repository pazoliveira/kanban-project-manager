#include "cntrIUProjeto.h"
#include "interfaces.h"
#include "projeto.h"

#include <iostream>
#include <string>

void CntrIUProjeto::executar(Email email) {
    int opcao;
    Projeto projeto;
    do {
        cout << "\n=== Projetos ===\n"
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
            case 2: ler(&projeto); break;
            case 3: atualizar(projeto); break;
            case 4: listar(); break;
            case 5: excluir(); break;
            case 0: break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);
}

bool CntrIUProjeto::criar(Email &gestor) {
        string entrada;

        Projeto projeto;
        Identificador identificador;
        Nome nome;
        Texto descricao;
        Timestamp inicio;
        Timestamp termino;
        Email emailGestor;


    try {
            cout << "Identificador: ";
            getline(cin >> ws, entrada);
            identificador.setIdentificador(entrada);

            cout << "Nome: ";
            getline(cin >> ws, entrada);
            nome.setNome(entrada);

            cout << "Descricao: ";
            getline(cin >> ws, entrada);
            descricao.setTexto(entrada);

            cout << "Inicio: ";
            getline(cin >> ws, entrada);
            inicio.setDataHora(entrada);

            cout << "Termino: ";
            getline(cin >> ws, entrada);
            termino.setDataHora(entrada);

            cout << "Email do Gestor: ";
            getline(cin >> ws, entrada);
            emailGestor.setEmail(entrada);


            projeto.setIdentificador(identificador);
            projeto.setNome(nome);
            projeto.setDescricao(descricao);
            projeto.setInicio(inicio);
            projeto.setTermino(termino);
            projeto.setEmailGestor(emailGestor);

        }
        catch (const invalid_argument &excecao) {
            cout << "Dado invalido: " << excecao.what() << "\n";
            cout << "Tentar novamente? (s/n): ";
            cin >> entrada;
            if (entrada != "s" && entrada != "S")
                return false;
        }

        // Delegação ao serviço: grava a pessoa (falha se o email já existe).
        if (cntrSProjeto->criar(projeto)) {
            cout << "Projeto cadastrado com sucesso.\n";
            return true;
        }

        cout << "Ja existe Projeto com esse Identificador.\n";
        cout << "Tentar novamente? (s/n): ";
        cin >> entrada;
        if (entrada != "s" && entrada != "S")
            return false;

    return true;

}

bool CntrIUProjeto::ler(Projeto*) {
    string entrada;
    Identificador identificador;
    Projeto projeto;

    cout << "\n=== Consultar projeto ===\n";

    try {
        // Lê e valida o identificador (a PK do projeto).
        cout << "Identificador: ";
        getline(cin >> ws, entrada);
        identificador.setIdentificador(entrada);
        projeto.setIdentificador(identificador);
    }
    catch (const invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << "\n";
        return false;
    }

    // Delegação ao serviço: preenche o restante dos dados em 'projeto'.
    if (!cntrSProjeto->ler(&projeto)) {
        cout << "Projeto nao encontrado.\n";
        return false;
    }

    // Apresentação dos dados.
    cout << "\n--- Dados do projeto ---\n"
         << "Identificador: " << projeto.getIdentificador().getIdentificador() << "\n"
         << "Nome:          " << projeto.getNome().getNome() << "\n"
         << "Descricao:     " << projeto.getDescricao().getTexto() << "\n"
         << "Inicio:        " << projeto.getInicio().getDataHora() << "\n"
         << "Termino:       " << projeto.getTermino().getDataHora() << "\n"
         << "Gestor:        " << projeto.getEmailGestor().getEmail() << "\n";


    return true;
}

bool CntrIUProjeto::atualizar(Projeto) {
    string entrada;
    Identificador identificador;
    Projeto projeto;

    cout << "\n=== Atualizar projeto ===\n";

    // 1. Identificador e busca do projeto atual.
    try {
        cout << "Identificador (3 letras + 3 numeros, ex.: ABC123): ";
        getline(cin >> ws, entrada);
        identificador.setIdentificador(entrada);
        projeto.setIdentificador(identificador);
    }
    catch (const invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << "\n";
        return false;
    }

    if (!cntrSProjeto->ler(&projeto)) {
        cout << "Projeto nao encontrado.\n";
        return false;
    }

    // 2. Novos valores (ENTER mantém o atual).
    cout << "\nDeixe em branco e tecle ENTER para manter o valor atual.\n";

    try {
        Nome nome;
        Texto descricao;
        Timestamp inicio, termino;

        cout << "Nome [" << projeto.getNome().getNome() << "]: ";
        getline(cin, entrada);
        if (!entrada.empty()) {
            nome.setNome(entrada);
            projeto.setNome(nome);
        }

        cout << "Descricao [" << projeto.getDescricao().getTexto() << "]: ";
        getline(cin, entrada);
        if (!entrada.empty()) {
            descricao.setTexto(entrada);
            projeto.setDescricao(descricao);
        }

        cout << "Inicio [" << projeto.getInicio().getDataHora() << "]: ";
        getline(cin, entrada);
        if (!entrada.empty()) {
            inicio.setDataHora(entrada);
            projeto.setInicio(inicio);
        }

        cout << "Termino [" << projeto.getTermino().getDataHora() << "]: ";
        getline(cin, entrada);
        if (!entrada.empty()) {
            termino.setDataHora(entrada);
            projeto.setTermino(termino);
        }
    }
    catch (const invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << "\n";
        cout << "Nenhuma alteracao foi gravada.\n";
        return false;
    }

    // 3. Delegação ao serviço.
    if (!cntrSProjeto->atualizar(projeto)) {
        cout << "Nao foi possivel atualizar o projeto.\n";
        return false;
    }

    cout << "Projeto atualizado com sucesso.\n";
    return true;
}

bool CntrIUProjeto::listar() {
    vector<Projeto> lista;

    cout << "\n=== Listar projetos ===\n";


    if (!cntrSProjeto->listar(&lista)) {
        cout << "Nao foi possivel listar os projetos.\n";
        return false;
    }

    if (lista.empty()) {
        cout << "Nenhum projeto cadastrado.\n";
        return true;
    }

    for (Projeto &projeto : lista) {
        cout << "ID: "              << projeto.getIdentificador().getIdentificador() << "\n"
             << "Nome:  "           << projeto.getNome().getNome() << "\n"
             << "Descricao: "       << projeto.getDescricao().getTexto() << "\n"
             << "Inicio: "          << projeto.getInicio().getDataHora() << "\n"
             << "Termino: "         << projeto.getTermino().getDataHora() << "\n"
             << "Gestor: "          << projeto.getEmailGestor().getEmail() << "\n"
             << "---------------------------\n";
    }

    return true;

}

bool CntrIUProjeto::excluir(){

    cout << "\n=== Excluir projeto(s) ===\n";

    string entrada;
    Identificador identificador;
    Projeto projeto;

    try {
        // Lê e valida o identificador (a PK do projeto).
        cout << "Identificador: ";
        getline(cin >> ws, entrada);
        identificador.setIdentificador(entrada);
        projeto.setIdentificador(identificador);
    }
    catch (const invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << "\n";
        return false;
    }


    if (!cntrSProjeto->ler(&projeto)) {
        cout << "Projeto nao encontrado.\n";
        return false;
    }

    if (!cntrSProjeto->excluir(identificador)) {
        cout << "Falha ao excluir projeto.\n";
        return false;
    }

    // Apresentação dos dados.
    cout << "\n--- Dados do projeto excluído ---\n"
         << "Identificador: " << projeto.getIdentificador().getIdentificador() << "\n"
         << "Nome:          " << projeto.getNome().getNome() << "\n"
         << "Descricao:     " << projeto.getDescricao().getTexto() << "\n"
         << "Inicio:        " << projeto.getInicio().getDataHora() << "\n"
         << "Termino:       " << projeto.getTermino().getDataHora() << "\n"
         << "Gestor:        " << projeto.getEmailGestor().getEmail() << "\n";

    return true;

}
