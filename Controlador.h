#ifndef__CONTROLADOR_H__
#define__CONTROLADOR_H__
#include "Escenario.h"//con el nombre con que lo hayan puesto

class CControlador
{
private:
    CEscenario*oEscenario;
public:
    Controlador(){
        oEscenario=new CEscenario()
    }
    ~Controlador(){}
    void dibujar(Graphics^g, bitmap^bmpBase, bitmap^bmpSolido, bitmap^bmpDestruible){
        oEscenario->PintarBase(g,bmpBase);
        oEscenario->PintarMatriz(g,bmpSolido, bmpDestruible);
    }
};


