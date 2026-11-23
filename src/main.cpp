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
#include "cntrIUProjeto.h"
#include "cntrIUQuadro.h"

#include "stubs.h"

using namespace std;


int main() {


    // ---------------------------------------------------------------------
    // Instanciar controladoras de apresentação e stub de serviço.

    InterfaceApresentacaoAutenticacao   *cntrIUAutenticacao = new CntrIUAutenticacao();
    InterfaceApresentacaoPessoa         *cntrIUPessoa       = new CntrIUPessoa();
    InterfaceApresentacaoProjeto        *cntrIUProjeto      = new CntrIUProjeto();
    InterfaceApresentacaoQuadro         *cntrIUQuadro       = new CntrIUQuadro();

    StubCntrSPessoa                     *stubSPessoa        = new StubCntrSPessoa();
    StubCntrSProjeto                    *stubSProjeto       = new StubCntrSProjeto();
    StubCntrSQuadro                     *stubSQuadro        = new StubCntrSQuadro();

    // Ligar controladoras ao serviço (mesmo stub nas duas).
    cntrIUAutenticacao->setCntrSAutenticacao(stubSPessoa);
    cntrIUPessoa->setCntrSPessoa(stubSPessoa);
    cntrIUProjeto->setCntrSProjeto(stubSProjeto);
    cntrIUQuadro->setCntrSQuadro(stubSQuadro);

    Email email;
    Papel papel;
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
          << "  Professor  : Fernando A. de Araujo Chacon de Albuquerque\n"
          << "  Semestre   : 2026.2\n"
          << "\n"
          << "------------------------------------------------------------\n"
          << "  Desenvolvido por:\n"
          << "    - Antenor Bento da Silva Neto  (Mat. 252033425)\n"
          << "    - Diego Paz Oliveira Morais    (Mat. 252011070)\n"
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
                        cout << "\nSucesso na autenticacao.\n" << endl;
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
// Menu principal (só se autenticou).

    if (autenticado) {
        cout << "\n#### Bem-vindo, " << email.getEmail() << "! ####\n";

        bool voltar = false;
        while (!voltar) {
            cout << "\n=== Menu principal ===\n"
                 << "1 - Projetos\n"
                 << "2 - Pessoas\n"
                 << "3 - Quadros\n"
                 << "0 - Sair\n"
                 << "Opcao: ";

            int opcao;
            if (!(cin >> opcao)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Opcao invalida.\n";
                continue;
            }

            try {
                switch (opcao) {
                    case 1:
                        // TODO: permitir apenas se o papel for GESTOR.
                        cntrIUProjeto->executar(email);
                        break;
                    case 2:
                        cntrIUPessoa->executar(email);
                        break;
                    case 3:
                        cntrIUQuadro->executar(email);
                        break;
                    case 0:
                        voltar = true;
                        break;
                    default:
                        cout << "Opcao invalida.\n";
                }
            }
            catch (const runtime_error &exp) {
                cout << "Erro de sistema.\n";
                voltar = true;
            }
        }
    }



    // ---------------------------------------------------------------------
    // Destruir controladoras e stub.

    delete cntrIUAutenticacao;
    delete cntrIUPessoa;
    delete stubSPessoa;
    delete cntrIUProjeto;
    delete stubSProjeto;
    delete cntrIUQuadro;
    delete stubSQuadro;

    return 0;
}
