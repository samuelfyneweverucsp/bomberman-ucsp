#ifndef __ARRMEJORAS_H__
#define __ARRMEJORAS_H__
#include "Mejora.h"
#include "MVelocidad.h"
#include "MCalavera.h"
#include "MVida.h"
#include <vector>
#include "stdlib.h"

using namespace std;

class CArrMejoras
{
public:
	CArrMejoras(){}
	~CArrMejoras(){}
	void crearMejora() {
		srand(time(NULL));
		tipo_de_mejora = rand() % 3 + 1;
		CmejoraVida* nueva_mejoraV = new CmejoraVida();
		CmejoraCalavera* nueva_mejoraC = new CmejoraCalavera;
		CmejoraVelocidad* nueva_mejoraVel = new CmejoraVelocidad;
		switch (tipo_de_mejora) {
		case 1:
			vector_mejoras.push_back(nueva_mejoraV);
			break;

		case 2:
			vector_mejoras.push_back(nueva_mejoraC);
			break;

		case 3:
			vector_mejoras.push_back(nueva_mejoraVel);
			break;
		}
	}

	void dibujar(Graphics^ g, Bitmap^ bmpMejoras, int **matriz) {
		for (int i = 0; i < vector_mejoras.size(); i++) {
			vector_mejoras.at(i)->dibujar(g, bmpMejoras, matriz);
			vector_mejoras.at(i)->animar();
		}
	}


private:
	vector<CMejora*>vector_mejoras;
	int tipo_de_mejora;

};

#endif // !__ARRMEJORAS_H__

