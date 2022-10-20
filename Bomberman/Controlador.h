#ifndef __CONTROLADOR_H__
#define __CONTROLADOR_H__
#include "Escenario.h"//con el nombre con que lo hayan puesto

class CControlador
{
private:
	CEscenario* oEscenario;
public:
	CControlador(){
		oEscenario = new CEscenario;
		}
	~CControlador(){}
	void CambiarNivel() {
		oEscenario->generarMatriz();
	}
	void dibujar(Graphics ^ g, Bitmap ^ bmpBase, Bitmap ^ bmpSolido, Bitmap ^ bmpDestruible) {
		oEscenario->PintarBase(g, bmpBase);
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
	}
};

#endif // !__CONTROLADOR_H__

