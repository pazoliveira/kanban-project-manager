#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "email.h"
#include "senha.h"

#include <stdexcept>

using namespace std;

// -------------------------------------------------------------------------------------------
// Declaração adiantada (forward declaration)

class InterfaceServicoAutenticacao;

// -------------------------------------------------------------------------------------------
// Declaração de interface para serviço de autenticação provido pela camada de apresentação.

class InterfaceApresentacaoAutenticacao {
public:

    virtual bool autenticar(Email*) = 0;                        // Método por meio do qual é solicitado serviço.
    virtual void setCntrSAutenticacao(InterfaceServicoAutenticacao *) = 0;      // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.
    virtual ~InterfaceApresentacaoAutenticacao(){}                                     // Método destrutor virtual.
};

// -------------------------------------------------------------------------------------------
// Declaração de interface para serviço de autenticação provido pela camada de serviço.

class InterfaceServicoAutenticacao {
public:
    virtual bool autenticar(const Email, const Senha) = 0;    // Método por meio do qual é solicitado serviço.
    virtual ~InterfaceServicoAutenticacao(){}                                    // Método destrutor virtual.
};

#endif // INTERFACES_H_INCLUDED
