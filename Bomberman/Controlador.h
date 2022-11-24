#ifndef __CONTROLADOR_H__
#define __CONTROLADOR_H__
#include "Escenario.h"//con el nombre con que lo hayan puesto
#include "Jugador.h"
#include "ArrBombas.h"
#include "ArrMejoras.h"
// #include "ArrEnemigos.h"

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
		oArrMejoras = new CArrMejoras();

		}
	~CControlador(){} // destructor
	
	void agregarBomba() {
		oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY());
	}

	void disminuir_Vidas_Por_Enemigo() {

	}

	void disminuir_Vidas_Por_Bomba() {
		int PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY, 
        PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;
		for(int i = 0; i < oArrBombas->getarregloBombas().size(); i++) {
			if(oArrBombas->getarregloBombas().at(i)->getEstado() == Estado::explosion) { // si hay una explosion
				PuntaIzquierda = oArrBombas->getarregloBombas().at(i)->getX() - 100; // definiendo la extrema mas a la izquierda donde hay muerte por causa de la explosion de la bomba
				PuntaDerecha = oArrBombas->getarregloBombas().at(i)->getX() + 150; // y mas a la derecha
				PuntaSuperior = oArrBombas->getarregloBombas().at(i)->getY() - 100; // y mas alto
				PuntaInferior = oArrBombas->getarregloBombas().at(i)->getY() + 150; // y mas bajo
				CentroInicioX = oArrBombas->getarregloBombas().at(i)->getX();
				CentroInicioY = oArrBombas->getarregloBombas().at(i)->getY();
				CentroFinalX = oArrBombas->getarregloBombas().at(i)->getX() + 50;
				CentroFinalY = oArrBombas->getarregloBombas().at(i)->getY() + 50;

				oJugador->disminuirvidas(PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY, 
        									PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX);
				
			}
		}
	}


	void crear_enemigos_y_mejoras() {
		// oArrEnemigos->crearEnemigos();
		oArrMejoras->crearMejoras();
	}

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

