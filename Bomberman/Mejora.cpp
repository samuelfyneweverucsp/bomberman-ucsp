#include "Mejora.h"

void CMejora::dibujar(Graphics^ g, Bitmap^ bmpMejora, int** matriz) {
	Rectangle porcionUsar = Rectangle(indiceX, indiceY, ancho, alto);

	while (ubicado == false) {
		if (matriz[i][j] == 3) {
			ubicado = true;
		}
		else {
			if (j < 16){
				i++;
				if (i==14) {
					i = 1;
					j++;
				}
			}
		}
	}
	Rectangle aumento = Rectangle(j * 50, i * 50, 50, 50);
	g->DrawImage(bmpMejora, aumento, porcionUsar, GraphicsUnit::Pixel);
}
void CMejora::animar(){}
void CMejora::poder(){}
