#ifndef __MEJORACALAVERA_H__
#define __MEJORACALAVERA_H__
#include "Mejora.h"

class CmejoraCalavera : public CMejora
{
public:
	CmejoraCalavera(){}
	~CmejoraCalavera(){}

	void animar() {
		CMejora::animar();
		indiceX = 5;
		if (indiceY >= 0 && indiceY < 1) {
			indiceY++;
		}
		else {
			indiceY = 0;
		}
	}
	
	void poder(CJugador* oJugador) {
		CMejora::poder(oJugador);
		oJugador->setVidas(oJugador->getVidas()-1);
	}

private:

};

#endif // !__MEJORACALAVERA_H__

