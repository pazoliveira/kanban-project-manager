#include "cntrIUPessoa.h"
#include "pessoa.h"

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

bool CntrIUPessoa::executar(Email email) {

    int opcao;
    Pessoa pessoa;

     do {
        cout << "\n=== Time de Desenvolvimento ===\n"
             << "1 - Cadastrar\n"
             << "2 - Consultar\n"
             << "3 - Atualizar\n"
             << "4 - Listar\n"
             << "5 - Excluir\n"
             << "0 - Voltar\n"
             << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrar(); break;
            case 2: ler(); break;
            case 3: atualizar(); break;
            case 4: listar(); break;
            case 5: excluir(); break;
            case 0: break;
            default: cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    return true;
}

bool CntrIUPessoa::cadastrar() {
    string entrada;

    while (true) {
        cout << "\n=== Cadastro de usuario ===\n";

        Pessoa pessoa;
        Email email;
        Nome nome;
        Senha senha;
        Papel papel;

        try {
            cout << "Email: ";
            getline(cin >> ws, entrada);
            email.setEmail(entrada);

            cout << "Nome: ";
            getline(cin >> ws, entrada);
            nome.setNome(entrada);

            cout << "Senha: ";
            getline(cin >> ws, entrada);
            senha.setSenha(entrada);

            cout << "Papel:\n"
                 << "  1 - Gestor\n"
                 << "  2 - Desenvolvedor\n"
                 << "Opcao: ";
            getline(cin >> ws, entrada);

            if (entrada == "1")
                papel.setPapel("GESTOR");
            else if (entrada == "2")
                papel.setPapel("DESENVOLVEDOR");
            else
                throw std::invalid_argument("Opcao de papel invalida.");

            pessoa.setEmail(email);
            pessoa.setNome(nome);
            pessoa.setSenha(senha);
            pessoa.setPapel(papel);
        }
        catch (const invalid_argument &excecao) {
            cout << "Dado invalido: " << excecao.what() << "\n";
            cout << "Tentar novamente? (s/n): ";
            cin >> entrada;
            if (entrada != "s" && entrada != "S")
                return false;
            continue;
        }

        // Delegação ao serviço: grava a pessoa (falha se o email já existe).
        if (cntrSPessoa->cadastrar(pessoa)) {
            cout << "Usuario cadastrado com sucesso.\n";
            return true;
        }

        cout << "Ja existe usuario com esse email.\n";
        cout << "Tentar novamente? (s/n): ";
        cin >> entrada;
        if (entrada != "s" && entrada != "S")
            return false;
    }
}

bool CntrIUPessoa::ler() {

    string entrada;
    Email email;
    Pessoa pessoa;

    cout << "\n=== Consultar usuário ===\n";

    try {
        // Lê e valida o identificador (a PK do projeto).
        cout << "Email: ";
        getline(cin >> ws, entrada);
        email.setEmail(entrada);
        pessoa.setEmail(email);
    }
    catch (const invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << "\n";
        return false;
    }

    // Delegação ao serviço: preenche o restante dos dados em 'pessoa'.
    if (!cntrSPessoa->ler(&pessoa)) {
        cout << "Pessao nao encontrada.\n";
        return false;
    }

    // Apresentação dos dados.
    cout << "\n--- Dados da pessoa ---\n"
         << "Email:         " << pessoa.getEmail().getEmail() << "\n"
         << "Nome:          " << pessoa.getNome().getNome() << "\n"
         << "Papel:         " << pessoa.getPapel().getPapel() << "\n"
         << "---------------------------\n";

    return true;
}

bool CntrIUPessoa::atualizar() {
    string entrada;
    Email email;
    Pessoa pessoa;

    cout << "\n=== Atualizar cadastro usuário ===\n";

    // 1. Identificador e busca do projeto atual.
    try {
        cout << "Email (PK): ";
        getline(cin >> ws, entrada);
        email.setEmail(entrada);
        pessoa.setEmail(email);
    }
    catch (const invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << "\n";
        return false;
    }

    if (!cntrSPessoa->ler(&pessoa)) {
        cout << "Pessoa nao encontrada.\n";
        return false;
    }

    // 2. Novos valores (ENTER mantém o atual).
    cout << "\nDeixe em branco e tecle ENTER para manter o valor atual.\n";

    try {
        Nome nome;
        Senha senha;
        Papel papel;

        cout << "Nome [" << pessoa.getNome().getNome() << "]: ";
        getline(cin, entrada);
        if (!entrada.empty()) {
            nome.setNome(entrada);
            pessoa.setNome(nome);
        }

        cout << "Senha [" << senha.getSenha() << "]: ";
        getline(cin, entrada);
        if (!entrada.empty()) {
            senha.setSenha(entrada);
            pessoa.setSenha(senha);
        }

        cout << "Papel [" << pessoa.getPapel().getPapel() << "]: ";
        getline(cin, entrada);
        if (!entrada.empty()) {
            papel.setPapel(entrada);
            pessoa.setPapel(papel);
        }


    }
    catch (const invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << "\n";
        cout << "Nenhuma alteracao foi gravada.\n";
        return false;
    }

    // 3. Delegação ao serviço.
    if (!cntrSPessoa->atualizar(pessoa)) {
        cout << "Nao foi possivel atualizar o pessoa.\n";
        return false;
    }

    cout << "Dados Pessoais atualizados com sucesso.\n";
    return true;
}

bool CntrIUPessoa::listar() {
    vector<Pessoa> lista;

    cout << "\n=== Usuários cadastrados ===\n" << endl;


    if (!cntrSPessoa->listar(&lista)) {
        cout << "Nao foi possivel listar as pessoas.\n";
        return false;
    }

    if (lista.empty()) {
        cout << "Nenhuma pessoa cadastrada.\n";
        return true;
    }

    for (Pessoa &pessoa : lista) {
        cout << "Email: " << pessoa.getEmail().getEmail() << "\n"
             << "Nome:  " << pessoa.getNome().getNome() << "\n"
             << "Papel: " << pessoa.getPapel().getPapel() << "\n"
             << "---------------------------\n";
    }

    return true;
}

bool CntrIUPessoa::excluir() {

cout << "\n=== Excluir usuário ===\n";

    string entrada;
    Email email;
    Pessoa pessoa;

    try {
        // Lê e valida o identificador (a PK do projeto).
        cout << "Email: ";
        getline(cin >> ws, entrada);
        email.setEmail(entrada);
        pessoa.setEmail(email);
    }
    catch (const invalid_argument &excecao) {
        cout << "Dado invalido: " << excecao.what() << "\n";
        return false;
    }

    if (!cntrSPessoa->ler(&pessoa)) {
        cout << "Pessoa não encontrada.\n";
        return false;
    }

    if (!cntrSPessoa->excluir(email)) {
        cout << "Falha ao excluir pessoa.\n";
        return false;
    }

    // Apresentação dos dados.
    cout << "\n--- Dados da pessoa excluída ---\n"
         << "Email:         " << pessoa.getEmail().getEmail() << "\n"
         << "Nome:          " << pessoa.getNome().getNome() << "\n"
         << "Papel:         " << pessoa.getPapel().getPapel() << "\n"
         << "---------------------------\n";

    return true;

}
