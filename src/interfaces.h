#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "email.h"
#include "senha.h"
#include "pessoa.h"
#include "projeto.h"
#include "identificador.h"

#include <stdexcept>
#include <vector>

using namespace std;

// -------------------------------------------------------------------------------------------
// Declaração adiantada (forward declaration)

class InterfaceServicoAutenticacao;
class InterfaceServicoPessoa;
class InterfaceServicoProjeto;

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
    virtual bool autenticar(Email, Senha) = 0;    // Método por meio do qual é solicitado serviço.
    virtual ~InterfaceServicoAutenticacao(){}                                    // Método destrutor virtual.
};


// Camada de apresentação
class InterfaceApresentacaoPessoa {
public:
    virtual bool cadastrar() = 0;
    virtual bool executar (Email) = 0;
    virtual void setCntrSPessoa(InterfaceServicoPessoa*) = 0;
    virtual ~InterfaceApresentacaoPessoa() {}
};

// Camada de serviço
class InterfaceServicoPessoa {
public:
    // Retorna false se já existir Pessoa com o mesmo email (PK).
    virtual bool cadastrar(Pessoa&) = 0;
    virtual bool ler(Pessoa*) = 0;
    virtual bool atualizar (Pessoa) = 0;
    virtual bool listar(vector<Pessoa>*) = 0;
    virtual ~InterfaceServicoPessoa() {}
};

// camada apresentação
class InterfaceApresentacaoProjeto {
public:
    virtual void executar(Email) = 0;
    virtual void setCntrSProjeto(InterfaceServicoProjeto*) = 0;
    virtual ~InterfaceApresentacaoProjeto(){}
};
// camada serviço
class InterfaceServicoProjeto {
public:
    virtual bool criar(Projeto) = 0;
    virtual bool ler(Projeto*) = 0;
    virtual bool atualizar(Projeto) = 0;
    virtual bool excluir(Identificador) = 0;
    virtual bool listar(vector<Projeto>*) = 0;
    virtual ~InterfaceServicoProjeto() {}

};

#endif // INTERFACES_H_INCLUDED
