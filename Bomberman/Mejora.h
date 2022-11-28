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
	void dibujar(Graphics^ g, Bitmap^ bmpMejoras, int** matriz) {
		Rectangle porcionUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);

		while (ubicado == false) {
			if (matriz[i][j] == 3) {
				ubicado = true;
			}
			else {
				if (j < 16) {
					i++;
					if (i == 14) {
						i = 1;
						j++;
					}
				}
			}
		}
		Rectangle aumento = Rectangle(j * 50, i * 50, ancho * 3.125, alto * 3.125);
		g->DrawImage(bmpMejoras, aumento, porcionUsar, GraphicsUnit::Pixel);
	}
	virtual void animar(){}
	virtual void poder(){}
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