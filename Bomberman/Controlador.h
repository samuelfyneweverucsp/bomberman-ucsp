#ifndef __CONTROLADOR_H__
#define __CONTROLADOR_H__
#include "Escenario.h"//con el nombre con que lo hayan puesto
#include "Jugador.h"
#include "ArrBombas.h"
#include "ArrMejoras.h"
#include "ArrEnemigos.h"
#include "Marcador.h"

class CControlador
{
private:
	CEscenario* oEscenario;
	CJugador* oJugador1;
	CJugador* oJugador2;
	CArrBombas* oArrBombas1;
	CArrBombas* oArrBombas2;
	CArrMejoras* oArrMejoras;
	CArrEnemigos* oArrEnemigos;
	CMarcador* oMarcador;
	int nivel;

public:
	CControlador(){ // constructor
		oEscenario = new CEscenario;
		oJugador1 = new CJugador(50, 50); // declarar jugador e inicializar en la posicion (50; 50)
		oArrBombas1 = new CArrBombas();
		oJugador2 = new CJugador(750, 600);
		oArrBombas2 = new CArrBombas();
		oArrMejoras = new CArrMejoras();
		oArrEnemigos = new CArrEnemigos();
		nivel = 1;
		}
	~CControlador(){} // destructor
	
	void agregarBomba(CArrBombas *oArrBombas, CJugador *oJugador) {
		oArrBombas->crear_una_bomba(oJugador->getX(), oJugador->getY());
	}
	void disminuir_Vidas_Por_Enemigo(CJugador *oJugador) {
		for (int i = 0; i < oArrEnemigos->getArregloEnemigos().size(); i++) {
			if (oJugador->retornarRectangulo().IntersectsWith(oArrEnemigos->getArregloEnemigos().at(i)->retornarRectangulo()))
				oJugador->disminuirvidas();
		}
	}

	void disminuir_Vidas_Por_Bomba(CArrBombas *oArrBombas, CJugador *oJugador) {
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
	void CambiarNivel() {
		oEscenario->generarMatriz();
	}
	void agarrarMejoras(CJugador* oJugador) {
		for (int i = 0; i < oArrMejoras->getvector_mejoras().size(); i++) {
			if (oJugador->retornarRectangulo().IntersectsWith(oArrMejoras->getvector_mejoras().at(i)->devolverRectangulo())) {
				oArrMejoras->getvector_mejoras().at(i)->poder(oJugador);
				oArrMejoras->eliminarMejora(i);
			}
		}
	}
	void matarEnemigo(CArrBombas* oArrBombas) {
		int PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY,
			PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX;
		for (int i = 0; i < oArrBombas->getarregloBombas().size(); i++) {
			if (oArrBombas->getarregloBombas().at(i)->getEstado() == Estado::explosion) { // si hay una explosion
				PuntaIzquierda = oArrBombas->getarregloBombas().at(i)->getX() - 100; // definiendo la extrema mas a la izquierda donde hay muerte por causa de la explosion de la bomba
				PuntaDerecha = oArrBombas->getarregloBombas().at(i)->getX() + 150; // y mas a la derecha
				PuntaSuperior = oArrBombas->getarregloBombas().at(i)->getY() - 100; // y mas alto
				PuntaInferior = oArrBombas->getarregloBombas().at(i)->getY() + 150; // y mas bajo
				CentroInicioX = oArrBombas->getarregloBombas().at(i)->getX();
				CentroInicioY = oArrBombas->getarregloBombas().at(i)->getY();
				CentroFinalX = oArrBombas->getarregloBombas().at(i)->getX() + 50;
				CentroFinalY = oArrBombas->getarregloBombas().at(i)->getY() + 50;
				oArrEnemigos->eliminarEnemigo(PuntaIzquierda, PuntaDerecha, CentroInicioY, CentroFinalY,
					PuntaSuperior, PuntaInferior, CentroInicioX, CentroFinalX);
			}
		}
	}
	void dibujarOnePlayer(Graphics ^ g, Bitmap ^ bmpBase, Bitmap ^ bmpSolido, Bitmap ^ bmpBomba, 
				Bitmap ^ bmpExplosion, Bitmap ^ bmpDestruible, Bitmap ^ bmpJugador,Bitmap^ bmpMejoras, 
				Bitmap ^ bmpEnemigo, Bitmap^ bmpFondo, Bitmap^ bmpCabezaPer1, Bitmap^ bmpVida3, 
				Bitmap^ bmpVida2, Bitmap^ bmpVida1, Bitmap^ bmpVida0, Bitmap^ bmpganar, Bitmap^ bmpperder)
	{
		oEscenario->PintarBase(g, bmpBase);
		oArrMejoras->dibujar(g, bmpMejoras, oEscenario->getMatriz());
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador1->moverJugador(g, bmpJugador, oEscenario->getMatriz()); 
		oArrBombas1->dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador1->getX(), oJugador1->getY(), oEscenario->getMatriz());
		oArrEnemigos->dibujar(g, bmpEnemigo, oEscenario->getMatriz());
		matarEnemigo(oArrBombas1);
		agarrarMejoras(oJugador1);
		oMarcador->pintarMarcador(g, bmpFondo);
		oMarcador->pintarJugador(g, bmpCabezaPer1);
		oMarcador->pintarVidas(g, bmpVida3, bmpVida2, bmpVida1, bmpVida0, oJugador1->getVidas(), ((15 / 2) * 50) + 63);
		disminuir_Vidas_Por_Bomba(oArrBombas1, oJugador1);
		disminuir_Vidas_Por_Enemigo(oJugador1);
		ganarSolitario(g, bmpganar, bmpperder);

	}
	void ganarSolitario(Graphics^ g, Bitmap^ bmpganar, Bitmap^ bmpperder) {
		if (oArrEnemigos->getArregloEnemigos().size() == 0 && oJugador1->getEstado(oJugador1) == vivo) {
			g->DrawImage(bmpganar, 50, 50, 750, 650);
		}
		if (oJugador1->getEstado(oJugador1)==muerto) {
			g->DrawImage(bmpperder, 50, 50, 750, 650);
		}
	}
	void ganarMultiplayer(Graphics^ g, Bitmap^ bmpganaJ1, Bitmap^ bmpganaJ2) {
		if (oJugador1->getEstado(oJugador1) == muerto && oJugador2->getEstado(oJugador2) == vivo) {
			g->DrawImage(bmpganaJ2, 50, 50, 750, 650);
		}
		if (oJugador1->getEstado(oJugador1) == vivo && oJugador2->getEstado(oJugador2) == muerto) {
			g->DrawImage(bmpganaJ1, 50, 50, 750, 650);
		}
	}
	void dibujarMultiPlayer(Graphics^ g, Bitmap^ bmpBase, Bitmap^ bmpSolido, Bitmap^ bmpBomba,Bitmap^ bmpExplosion,
				Bitmap^ bmpDestruible, Bitmap^ bmpJugador, Bitmap^ bmpJugador2, Bitmap^ bmpMejoras, Bitmap^ bmpFondo,
				Bitmap^ bmpCabezaPer1, Bitmap^ bmpCabezaPer2, Bitmap^ bmpVida3,Bitmap^ bmpVida2, Bitmap^ bmpVida1, 
				Bitmap^ bmpVida0, Bitmap^ bmpganaJ1, Bitmap^ bmpganaJ2)
	{
		oEscenario->PintarBase(g, bmpBase);
		oArrMejoras->dibujar(g, bmpMejoras, oEscenario->getMatriz());
		oEscenario->PintarMatriz(g, bmpSolido, bmpDestruible);
		oJugador1->moverJugador(g, bmpJugador, oEscenario->getMatriz());
		oJugador2->moverJugador(g, bmpJugador2, oEscenario->getMatriz());
		oArrBombas1->dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador1->getX(), oJugador1->getY(), oEscenario->getMatriz());
		oArrBombas2->dibujar_una_bomba(g, bmpBomba, bmpExplosion, oJugador2->getX(), oJugador2->getY(), oEscenario->getMatriz());
		disminuir_Vidas_Por_Bomba(oArrBombas2, oJugador1);
		disminuir_Vidas_Por_Bomba(oArrBombas1, oJugador1);
		disminuir_Vidas_Por_Bomba(oArrBombas1, oJugador2);
		disminuir_Vidas_Por_Bomba(oArrBombas2, oJugador2);
		agarrarMejoras(oJugador1);
		agarrarMejoras(oJugador2);
		oMarcador->pintarMarcador(g, bmpFondo);
		oMarcador->pintarJugador(g, bmpCabezaPer1, bmpCabezaPer2);
		oMarcador->pintarVidas(g, bmpVida3, bmpVida2, bmpVida1, bmpVida0, oJugador1->getVidas(), ((11 / 2) * 50) + 63);
		oMarcador->pintarVidas(g, bmpVida3, bmpVida2, bmpVida1, bmpVida0, oJugador2->getVidas(), (((11 / 2) + 4) * 50) + 63);
		ganarMultiplayer(g, bmpganaJ1, bmpganaJ2);
	}
	void crear_enemigos_y_mejoras() {
		oArrEnemigos->crearEnemigos();
		oArrMejoras->crearMejoras();
	}
	void crear_mejoras() {
		oArrMejoras->crearMejoras();
	}
	CJugador* getoJugador1 () {
		return oJugador1;
	}
	CArrBombas* getoArrBombas1() {
		return oArrBombas1;
	}
	CJugador* getoJugador2() {
		return oJugador2;
	}
	CArrBombas* getoArrBombas2() {
		return oArrBombas2;
	}
	CArrMejoras* getoArrMejoras() {
		return oArrMejoras;
	}
	CArrEnemigos* getoArrEnemigos() {
		return oArrEnemigos;
	}
	int getNivel() {
		return nivel;
	}
};

#endif // !__CONTROLADOR_H__