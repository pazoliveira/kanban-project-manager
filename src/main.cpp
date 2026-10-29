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

using namespace std;

void testarTimestamp() {
    cout << "\n--- Testando Timestamp ---" << endl;
    Timestamp t;
    
    // Teste válido
    try {
        t.setDataHora("29-FEV-2024-14:30");
        cout << "[SUCESSO] Timestamp valido: " << t.getDataHora() << endl;
    } catch (const exception &e) {
        cout << "[FALHA INESPERADA] " << e.what() << endl;
    }

    // Teste inválido (data inexistente)
    try {
        t.setDataHora("30-02-2026-16:35");
        cout << "[FALHA] Deveria ter rejeitado o timestamp invalido." << endl;
    } catch (const invalid_argument &e) {
        cout << "[SUCESSO AO REJEITAR] Excecao capturada corretamente: " << e.what() << endl;
    }
}

void testarSenha() {
    cout << "\n--- Testando Senha ---" << endl;
    Senha s;

    try {
        s.setSenha("Ab123");
        cout << "[SUCESSO] Senha valida: " << s.getSenha() << endl;
    } catch (const exception &e) {
        cout << "[FALHA INESPERADA] " << e.what() << endl;
    }

    try {
        s.setSenha("12345"); // Sem letras
        cout << "[FALHA] Deveria ter rejeitado a senha sem letras." << endl;
    } catch (const invalid_argument &e) {
        cout << "[SUCESSO AO REJEITAR] Excecao capturada corretamente: " << e.what() << endl;
    }
}

void testarEmail() {
    cout << "\n--- Testando Email ---" << endl;
    Email e;

    try {
        e.setEmail("usuario@dominio.com");
        cout << "[SUCESSO] Email valido: " << e.getEmail() << endl;
    } catch (const exception &ex) {
        cout << "[FALHA INESPERADA] " << ex.what() << endl;
    }

    try {
        e.setEmail("usuario@@dominio.com"); // Duplo arroba
        cout << "[FALHA] Deveria ter rejeitado o email com duplo arroba." << endl;
    } catch (const invalid_argument &ex) {
        cout << "[SUCESSO AO REJEITAR] Excecao capturada corretamente: " << ex.what() << endl;
    }
}

void testarNome() {
    cout << "\n--- Testando Nome ---" << endl;
    Nome n;

    try {
        n.setNome("Maria Silva");
        cout << "[SUCESSO] Nome valido: " << n.getNome() << endl;
    } catch (const exception &e) {
        cout << "[FALHA INESPERADA] " << e.what() << endl;
    }

    try {
        n.setNome(" Maria "); // Espaços nas pontas
        cout << "[FALHA] Deveria ter rejeitado espacos nas pontas." << endl;
    } catch (const invalid_argument &e) {
        cout << "[SUCESSO AO REJEITAR] Excecao capturada corretamente: " << e.what() << endl;
    }
}

void testarTexto() {
    cout << "\n--- Testando Texto ---" << endl;
    Texto txt;

    try {
        txt.setTexto("Este e um texto valido.");
        cout << "[SUCESSO] Texto valido: " << txt.getTexto() << endl;
    } catch (const exception &e) {
        cout << "[FALHA INESPERADA] " << e.what() << endl;
    }

    try {
        txt.setTexto("texto sem maiuscula ou ponto"); 
        cout << "[FALHA] Deveria ter rejeitado texto sem maiuscula/ponto." << endl;
    } catch (const invalid_argument &e) {
        cout << "[SUCESSO AO REJEITAR] Excecao capturada corretamente: " << e.what() << endl;
    }
}

void testarPrioridade() {
    cout << "\n--- Testando Prioridade ---" << endl;
    Prioridade p;

    try {
        p.setPrioridade("ALTA");
        cout << "[SUCESSO] Prioridade valida: " << p.getPrioridade() << endl;
    } catch (const exception &e) {
        cout << "[FALHA INESPERADA] " << e.what() << endl;
    }

    try {
        p.setPrioridade("URGENTE"); // Valor não permitido
        cout << "[FALHA] Deveria ter rejeitado prioridade invalida." << endl;
    } catch (const invalid_argument &e) {
        cout << "[SUCESSO AO REJEITAR] Excecao capturada corretamente: " << e.what() << endl;
    }
}

void testarEstado() {
    cout << "\n--- Testando Estado ---" << endl;
    Estado est;

    try {
        est.setEstado("FAZENDO");
        cout << "[SUCESSO] Estado valido: " << est.getEstado() << endl;
    } catch (const exception &e) {
        cout << "[FALHA INESPERADA] " << e.what() << endl;
    }

    try {
        est.setEstado("PENDENTE"); // Valor não permitido
        cout << "[FALHA] Deveria ter rejeitado estado invalido." << endl;
    } catch (const invalid_argument &e) {
        cout << "[SUCESSO AO REJEITAR] Excecao capturada corretamente: " << e.what() << endl;
    }
}

void testarLimite() {
    cout << "\n--- Testando Limite ---" << endl;
    Limite lim;

    try {
        lim.setLimite(15);
        cout << "[SUCESSO] Limite valido: " << lim.getLimite() << endl;
    } catch (const exception &e) {
        cout << "[FALHA INESPERADA] " << e.what() << endl;
    }

    try {
        lim.setLimite(50); // Fora do intervalo (1 a 25)
        cout << "[FALHA] Deveria ter rejeitado limite fora do intervalo." << endl;
    } catch (const invalid_argument &e) {
        cout << "[SUCESSO AO REJEITAR] Excecao capturada corretamente: " << e.what() << endl;
    }
}

int main() {
    cout << "========================================" << endl;
    cout << " INICIANDO BATERIA DE TESTES DE DOMINIO " << endl;
    cout << "========================================" << endl;

    testarTimestamp();
    testarSenha();
    testarEmail();
    testarNome();
    testarTexto();
    testarPrioridade();
    testarEstado();
    testarLimite();

    cout << "\n========================================" << endl;
    cout << "          FIM DOS TESTES                " << endl;
    cout << "========================================" << endl;

    return 0;
}

/*

#include <iostream>
#include "domain/headers/senha.h"
#include "domain/headers/prioridade.h"
#include "domain/headers/estado.h"
#include "domain/headers/limite.h"
#include <limits>
#include "domain/headers/nome.h"
#include "domain/headers/timestamp.h"

using namespace std;

int main()
{
    string valor;
    Senha senha;

    cout << "Cadastramento de Senha." << endl;
    cout << endl;
    cout << "Atencao!" << endl;
    cout << "A senha deve ter tamanho igual a 5 caracteres." << endl;
    cout << "A senha deve conter pelo menos uma letra e um numero." << endl;

    cout << endl;
    cout << "Digite sua senha: ";
    cin >> valor;

    try {
        senha.setSenha(valor); // Corrigido aqui
        cout << "Senha cadastrada com sucesso." << endl;
    }
    catch (invalid_argument &e) {
        cout << "Excecao: " << e.what() << endl;
    }

    Prioridade prioridade;
    string s;

    cout << endl;
    cout << "Prioridade [ALTA, MEDIA ou BAIXA]: ";
    cin >> s;

    prioridade.setPrioridade(s);
    cout << prioridade.getPrioridade() << endl;

    Estado estado;
    string s2;

    cout << endl;
    cout << "Estado [A FAZER, FAZENDO ou FEITO]: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, s2);

    estado.setEstado(s2);
    cout << estado.getEstado() << endl;

    Limite limite;
    int s3;

    cout << endl;
    cout << "Limite [digite um valor entre 1 e 25]: ";
    cin >> s3;

    limite.setLimite(s3);
    cout << limite.getLimite() << endl;

    Nome nome;
    string s4;

    cout << endl;
    cout << "Digite nome: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s4);

    try {
        nome.setNome(s4);
        cout << nome.getNome() << endl;
    }
    catch (invalid_argument &e) {
        cout << "Excecao: " << e.what() << endl;
    }

    Timestamp t;

    t.setDataHora("30-02-2026-16:35"); // Corrigido aqui

    cout << "Timestamp: " << t.getDataHora() << endl; // Corrigido aqui

    return 0;
}

*/