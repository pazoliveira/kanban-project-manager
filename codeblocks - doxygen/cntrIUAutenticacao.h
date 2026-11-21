#ifndef CNTRIUAUTENTICACAO_H_INCLUDED
#define CNTRIUAUTENTICACAO_H_INCLUDED

#include "interfaces.h"
#include "email.h"
#include "senha.h"

#include <stdexcept>
#include <iostream>

using namespace std;

// ---------------------------------------------------------------------------------
// Declaração de classe controladora e implementação de método.

class CntrIUAutenticacao:public InterfaceApresentacaoAutenticacao {
private:
    InterfaceServicoAutenticacao *cntrSAutenticacao;        // Referência para servidor.
public:
    bool autenticar(Email*);
    void setCntrSAutenticacao(InterfaceServicoAutenticacao*);
};

void inline CntrIUAutenticacao::setCntrSAutenticacao(InterfaceServicoAutenticacao *cntrSAutenticacao){
        this->cntrSAutenticacao = cntrSAutenticacao;
}


#endif // CNTRIUAUTENTICACAO_H_INCLUDED
