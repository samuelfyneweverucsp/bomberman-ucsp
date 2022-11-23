#include "Mejora.h"
#ifndef __MEJORAVIDA_H__
#define __MEJORAVIDA_H__

class CmejoraVida: public CMejora
{
public:
	CmejoraVida(){}
	~CmejoraVida(){}

	void animar() {
		CMejora::animar();
		indiceX = 9;
		if (indiceY >= 0 && indiceY < 1) {
			indiceY++;
		} else {
			indiceY = 0;
		}
	}

	void poder() {
		CMejora::poder();
		//aquí aparece lo que nos brinda
	}

private:

};
#endif // !__MEJORAVIDA_H__
