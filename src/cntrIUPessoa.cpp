#include "cntrIUPessoa.h"
#include "pessoa.h"

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

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

bool CntrIUPessoa::executar(Email email) {
    // TODO: menu de operações sobre a pessoa autenticada
    // (visualizar, editar, excluir conta).
    cout << "\nPessoa autenticada: " << email.getEmail() << "\n";
    return true;
}
