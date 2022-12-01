#ifndef __MARCADOR_H__
#define __MARCADOR_H__

using namespace System::Drawing;

class CMarcador
{
public:
	CMarcador() {
		IndiceX = 0;
		IndiceY = 0;
	}
	~CMarcador(){}

	void pintarMarcador(Graphics^ g, Bitmap^ bmpfondo) {
		for (int i = 0; i < 17; i++)
			g->DrawImage(bmpfondo, i * 50, 0, 50, 50);
	}
	void pintarJugador(Graphics^ g, Bitmap^ bmpPersonaje) {
		g->DrawImage(bmpPersonaje, (15/2)*50, 0, 63, 50);
	}
	void pintarJugador(Graphics^ g, Bitmap^ bmpPersonaje1, Bitmap^ bmpPersonaje2) {
		g->DrawImage(bmpPersonaje1, (11 / 2)*50, 0, 63, 50);
		g->DrawImage(bmpPersonaje2, ((11 / 2) + 4)*50, 0, 63, 50);
	}
	void pintarVidas(Graphics^ g, Bitmap^ bmpVida3, Bitmap^ bmpVida2, Bitmap^ bmpVida1, 
						Bitmap^ bmpVida0, int vidas, int x) {
		Bitmap^ bmpVidas;
		switch (vidas) {
		case 3:
			bmpVidas = bmpVida3;
			break;
		case 2:
			bmpVidas = bmpVida2;
			break;
		case 1:
			bmpVidas = bmpVida1;
			break;
		default:
			bmpVidas = bmpVida0;
		}
		g->DrawImage(bmpVidas, x, 5, 40, 40);
	}
private:
	int IndiceX;
	int IndiceY;
};
#endif // !__MARCADOR_H__
