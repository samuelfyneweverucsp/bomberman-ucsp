#ifndef __CONTROLADOR_H__
#define __CONTROLADOR_H__
#include "Escenario.h"//con el nombre con que lo hayan puesto
#include "Jugador.h"

class CControlador
{
private:
	CEscenario* oEscenario;
	CJugador* oJugador;
public:
	CControlador(){ // constructor
		oEscenario = new CEscenario;
		oJugador = new CJugador(50, 50); // declarar jugador e inicializar en la posicion (50; 50)

		}
	~CControlador(){} // destructor
	

	void CambiarNivel() {
		oEscenario->generarMatriz();
	}
	void dibujar(Graphics ^ g, Bitmap ^ bmpBase, Bitmap ^ bmpSolido, Bitmap ^ bmpDestruible, Bitmap ^ bmpJugador) {
		oEscenario->PintarBase(g, bmpBase);
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador->moverJugador(g, bmpJugador);
	}

	CJugador* getoJugador () {
		return oJugador;
	}
};

#endif // !__CONTROLADOR_H__

