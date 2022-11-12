#ifndef __CONTROLADOR_H__
#define __CONTROLADOR_H__
#include "Escenario.h"//con el nombre con que lo hayan puesto
#include "Jugador.h"
#include "ArrBombas.h"

class CControlador
{
private:
	CEscenario* oEscenario;
	CJugador* oJugador;
	CArrBombas* oArrBombas;
public:
	CControlador(){ // constructor
		oEscenario = new CEscenario;
		oJugador = new CJugador(50, 50); // declarar jugador e inicializar en la posicion (50; 50)
		oArrBombas = new CArrBombas();

		}
	~CControlador(){} // destructor
	

	void CambiarNivel() {
		oEscenario->generarMatriz();
	}

	void agregarBomba() {
		oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY());
	}

	void dibujar(Graphics ^ g, Bitmap ^ bmpBase, Bitmap ^ bmpSolido, Bitmap ^ bmpBomba, Bitmap ^ bmpExplosion, Bitmap ^ bmpDestruible, Bitmap ^ bmpJugador) {
		oEscenario->PintarBase(g, bmpBase);
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador->moverJugador(g, bmpJugador, oEscenario->getMatriz()); 
		oArrBombas->dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador->getX(), oJugador->getY(), oEscenario->getMatriz());
	} 

	CJugador* getoJugador () {
		return oJugador;
	}
};

#endif // !__CONTROLADOR_H__

