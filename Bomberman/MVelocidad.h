#ifndef __MEJORAVELOCIDAD_H__
#define __MEJORAVELOCIDAD_H__
#include "Mejora.h"

class CmejoraVelocidad: public CMejora
{
public:
	CmejoraVelocidad(){}
	~CmejoraVelocidad(){}

	void animar() {
		CMejora::animar();
		indiceX = 8;
		if (indiceY >= 0 && indiceY < 1) {
			indiceY++;
		}
		else {
			indiceY = 0;
		}
	}
	
	void poder() {
		CMejora::poder();
		//aquí aparece lo que nos brinda
	}

private:

};

#endif // !__MEJORAVELOCIDAD_H__

