#include <iostream>
#include "senha.h"
#include "prioridade.h"
#include "estado.h"
#include "limite.h"
#include <limits>
#include "nome.h"
#include "timestamp.h"

using namespace std;

int main()
{

string valor;
Senha senha;

cout << "Cadastramento de Senha." << endl;
cout << endl;
cout << "Atenção!" << endl;
cout << "A senha deve ter tamanho igual a 5 caracteres." << endl;
cout << "A senha deve conter pelo menos uma letra e um número." << endl;

cout << endl;
cout << "Digite sua senha: ";
cin >> valor;

try {

senha.setSenha(valor);
cout << "Senha cadastrada com sucesso." << endl;

}

catch (invalid_argument &e) {

cout << "Exceção: " << e.what() << endl;

};

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
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limpa o buffer removendo o \n que fica no final
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
    cout << "Exceção: " << e.what() << endl;
}


 Timestamp t;

    t.setDataHora("30-02-2026-16:35");

    cout << "Timestamp: " << t.getDataHora() << endl;

    return 0;
}
