#ifndef CNTRIUPESSOA_H_INCLUDED
#define CNTRIUPESSOA_H_INCLUDED


#include "interfaces.h"

/**
 * @brief Controladora de apresentação do cadastro de pessoa.
 */
class CntrIUPessoa : public InterfaceApresentacaoPessoa {
private:
    InterfaceServicoPessoa *cntrSPessoa = nullptr;
    bool atualizar ();
    bool ler();
public:
    bool cadastrar();
    bool executar (Email);
    void setCntrSPessoa(InterfaceServicoPessoa*);
};

inline void CntrIUPessoa::setCntrSPessoa(InterfaceServicoPessoa *cntrSPessoa) {
    this->cntrSPessoa = cntrSPessoa;
}


#endif // CNTRIUPESSOA_H_INCLUDED
