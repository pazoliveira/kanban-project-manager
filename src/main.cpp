#include <iostream>
#include <stdexcept>
#include <string>

#include "domain/headers/timestamp.h"
#include "domain/headers/senha.h"
#include "domain/headers/email.h"
#include "domain/headers/nome.h"
#include "domain/headers/texto.h"
#include "domain/headers/prioridade.h"
#include "domain/headers/estado.h"
#include "domain/headers/limite.h"
#include "interfaces.h"

#include "cntrIUAutenticacao.h"
#include "cntrIUPessoa.h"

#include "stubs.h"

using namespace std;


int main() {


    // ---------------------------------------------------------------------
    // Instanciar controladoras de apresentação e stub de serviço.

    InterfaceApresentacaoAutenticacao *cntrIUAutenticacao = new CntrIUAutenticacao();
    InterfaceApresentacaoPessoa     *cntrIUPessoa     = new CntrIUPessoa();
    StubCntrSPessoa *stubSPessoa       = new StubCntrSPessoa();

    // Ligar controladoras ao serviço (mesmo stub nas duas).
    cntrIUAutenticacao->setCntrSAutenticacao(stubSPessoa);
    cntrIUPessoa->setCntrSPessoa(stubSPessoa);

    Email email;
    bool autenticado = false;
    bool sair = false;


          cout << "\n"
          << "============================================================\n"
          << "                  SISTEMA KANBAN                            \n"
          << "============================================================\n"
          << "\n"
          << "  Universidade de Brasilia (UnB)\n"
          << "  Curso      : Licenciatura em Computacao\n"
          << "  Disciplina : CIC0197 - Tecnicas de Programacao 1\n"
          << "  Professor  : Fernando\n"
          << "  Semestre   : 2026.2\n"
          << "\n"
          << "------------------------------------------------------------\n"
          << "  Desenvolvido por:\n"
          << "    - Antenor Bento Silva Neto  (Mat. 252033425)\n"
          << "    - Diego Paz                 (Mat. 252022123)\n"
          << "============================================================\n"
          << endl;


    while (!autenticado && !sair) {
        std::cout << "\n=== Menu inicial ===\n"
                  << "1 - Autenticar\n"
                  << "2 - Cadastrar usuario\n"
                  << "0 - Sair\n"
                  << "Opcao: ";

        int opcao;
        if (!(cin >> opcao)) {         // entrada não numérica
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Opcao invalida.\n";
            continue;
        }

        try {
            switch (opcao) {
                case 1:
                    autenticado = cntrIUAutenticacao->autenticar(&email);
                    if (autenticado) {
                        cout << "\nSucesso na autenticacao.\n"
                                  << "Email = " << email.getEmail() << "\n";
                    }
                    break;
                case 2:
                    cntrIUPessoa->cadastrar();   // volta ao menu em seguida
                    break;
                case 0:
                    sair = true;
                    break;
                default:
                    cout << "Opcao invalida.\n";
            }
        }
        catch (const runtime_error &exp) {
            cout << "Erro de sistema.\n";
            break;
        }
    }

    // ---------------------------------------------------------------------
    // Destruir controladoras e stub.

    delete cntrIUAutenticacao;
    delete cntrIUPessoa;
    delete stubSPessoa;

    return 0;
}
