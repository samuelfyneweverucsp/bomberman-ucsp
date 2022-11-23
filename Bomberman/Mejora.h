#ifndef __MEJORA_H__
#define __MEJORA_H__
#include <ctime>
#include <stdlib.h>
using namespace System::Drawing;

class CMejora {
public:
	CMejora() {
		ubicado = false;

		i = rand() % 13 + 1;
		j = rand() % 15 + 1;

		ancho = 128 / 8;
		alto = 96 / 6;

		indiceX = 0;
		indiceY = 0;
		}
	~CMejora(){}
	void dibujar(Graphics^ g, Bitmap^ bmpMejora, int** matriz);
	virtual void animar();
	virtual void poder();
protected:
	int i;
	int j;

	//para animación
	int indiceX;
	int indiceY;

	//para saber la dimensión
	int ancho;
	int alto;

	bool ubicado;
};
#endif // !__MEJORA_H__