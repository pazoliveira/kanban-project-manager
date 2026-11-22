#ifndef CNTRIUPROJETO_H_INCLUDED
#define CNTRIUPROJETO_H_INCLUDED


#include "interfaces.h"


class CntrIUProjeto : public InterfaceApresentacaoProjeto {
private:
    InterfaceServicoProjeto *cntrSProjeto = nullptr;
    bool criar(Email &gestor);
    bool ler(Projeto*);
    bool atualizar(Projeto);
    bool excluir ();
    bool listar ();

public:
    void executar(Email);
    void setCntrSProjeto(InterfaceServicoProjeto*);
};

inline void CntrIUProjeto::setCntrSProjeto(InterfaceServicoProjeto *cntrSProjeto) {
    this->cntrSProjeto = cntrSProjeto;
}

#endif // CNTRIUPROJETO_H_INCLUDED
