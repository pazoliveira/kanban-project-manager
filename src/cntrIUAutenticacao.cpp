#include "cntrIUAutenticacao.h"

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

bool CntrIUAutenticacao::autenticar(Email *email) {
    Senha senha;
    string entrada;

    while (true) {
        cout << "\n=== Autenticacao ===\n";

        try {
            // Leitura e validação do email (o domínio se valida no set).
            cout << "Email: ";
            cin >> entrada;
            email->setEmail(entrada);

            // Leitura e validação da senha.
            cout << "Senha: ";
            cin >> entrada;
            senha.setSenha(entrada);
        }
        catch (const invalid_argument &excecao) {
            // Formato inválido: informa e pergunta se quer tentar de novo.
            cout << "Dado invalido: " << excecao.what() << "\n";
            cout << "Tentar novamente? (s/n): ";
            cin >> entrada;
            if (entrada != "s" && entrada != "S")
                return false;
            continue;
        }

        // Delegação ao serviço: verifica se as credenciais existem.
        if (cntrSAutenticacao->autenticar(*email, senha))
            return true;

        cout << "Email ou senha incorretos.\n";
        cout << "Tentar novamente? (s/n): ";
        cin >> entrada;
        if (entrada != "s" && entrada != "S")
            return false;
    }
}
