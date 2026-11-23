#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "email.h"
#include "senha.h"
#include "pessoa.h"
#include "projeto.h"
#include "quadro.h"
#include "identificador.h"

#include <stdexcept>
#include <vector>

using namespace std;

// -------------------------------------------------------------------------------------------
// Declaração adiantada (forward declaration)

    class InterfaceServicoAutenticacao;
    class InterfaceServicoPessoa;
    class InterfaceServicoProjeto;
    class InterfaceServicoQuadro;
// -------------------------------------------------------------------------------------------

/// Camada de apresentação Autenticação
class InterfaceApresentacaoAutenticacao {
public:

    virtual bool autenticar(Email*) = 0;                        // Método por meio do qual é solicitado serviço.
    virtual void setCntrSAutenticacao(InterfaceServicoAutenticacao *) = 0;      // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.
    virtual ~InterfaceApresentacaoAutenticacao(){}                                     // Método destrutor virtual.
};

/// Camada de serviço Autenticação
class InterfaceServicoAutenticacao {
public:
    virtual bool autenticar(Email, Senha) = 0;    // Método por meio do qual é solicitado serviço.
    virtual ~InterfaceServicoAutenticacao(){}                                    // Método destrutor virtual.
};

/// Camada de apresentação Pessoa
class InterfaceApresentacaoPessoa {
public:
    virtual bool cadastrar() = 0;
    virtual bool executar (Email) = 0;
    virtual void setCntrSPessoa(InterfaceServicoPessoa*) = 0;
    virtual ~InterfaceApresentacaoPessoa() {}
};

/// Camada de serviço Pessoa
class InterfaceServicoPessoa {
public:

    virtual bool cadastrar(Pessoa&) = 0;
    virtual bool ler(Pessoa*) = 0;
    virtual bool atualizar (Pessoa) = 0;
    virtual bool listar(vector<Pessoa>*) = 0;
    virtual bool excluir(Email) = 0;
    virtual ~InterfaceServicoPessoa() {}
};

/// Camada de apresentação Projeto
class InterfaceApresentacaoProjeto {
public:
    virtual void executar(Email) = 0;
    virtual void setCntrSProjeto(InterfaceServicoProjeto*) = 0;
    virtual ~InterfaceApresentacaoProjeto(){}
};

/// Camada de serviço Projeto
class InterfaceServicoProjeto {
public:
    virtual bool criar(Projeto) = 0;
    virtual bool ler(Projeto*) = 0;
    virtual bool atualizar(Projeto) = 0;
    virtual bool excluir(Identificador) = 0;
    virtual bool listar(vector<Projeto>*) = 0;
    virtual ~InterfaceServicoProjeto() {}

};

/// Camada de apresentação Quadro
class InterfaceApresentacaoQuadro {
public:
    virtual void executar(Email) = 0;
    virtual void setCntrSQuadro(InterfaceServicoQuadro*) = 0;
    virtual ~InterfaceApresentacaoQuadro(){}
};

/// Camada de serviço Quadro
class InterfaceServicoQuadro {
public:
    virtual bool criar(Quadro) = 0;
    virtual bool ler(Quadro*) = 0;
    virtual bool atualizar(Quadro) = 0;
    virtual bool excluir(Identificador) = 0;
    virtual bool listar(vector<Quadro>*) = 0;
    virtual ~InterfaceServicoQuadro() {}
};


#endif // INTERFACES_H_INCLUDED
