#ifndef CNTRIUQUADRO_H_INCLUDED
#define CNTRIUQUADRO_H_INCLUDED


#include "interfaces.h"


class CntrIUQuadro : public InterfaceApresentacaoQuadro {
private:
    InterfaceServicoQuadro *cntrSQuadro = nullptr;
    bool criar(Email &gestor);
    bool ler(Quadro*);
    bool atualizar(Quadro);
    bool excluir ();
    bool listar ();

public:
    void executar(Email);
    void setCntrSQuadro(InterfaceServicoQuadro*);
};

inline void CntrIUQuadro::setCntrSQuadro(InterfaceServicoQuadro *cntrSQuadro) {
    this->cntrSQuadro = cntrSQuadro;
}


#endif // CNTRIUQUADRO_H_INCLUDED
