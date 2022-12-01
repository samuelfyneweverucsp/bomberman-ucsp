#ifndef __ARRENEMIGOS_H__
#define __ARRENEMIGOS_H__
#include "Enemigo.h"
#include <vector>
using namespace std;

class CArrEnemigos {
    public:

        CArrEnemigos() {
            arregloEnemigos = vector<CEnemigo*>();
        }
        ~CArrEnemigos(){}
        void crearEnemigos() {
            CEnemigo* nuevo_enemigo = new CEnemigo;
            arregloEnemigos.push_back(nuevo_enemigo);
        }
        void dibujar(Graphics^ g, Bitmap^ bmpEnemigo, int** matriz) {
            for (int i = 0; i < arregloEnemigos.size(); i++) {
                arregloEnemigos.at(i)->dibujar(g, bmpEnemigo, matriz);
                arregloEnemigos.at(i)->animar();
            }
        }

        vector<CEnemigo*> getArregloEnemigos() { return arregloEnemigos; }

        void eliminarEnemigo(int PuntaIzquierda, int PuntaDerecha, int CentroInicioY, int CentroFinalY,
            int PuntaSuperior, int PuntaInferior, int CentroInicioX, int CentroFinalX) {
            for (int i = 0; i < arregloEnemigos.size(); i++) {
                if (arregloEnemigos.at(i)->getX() >= PuntaIzquierda && arregloEnemigos.at(i)->getX() <= PuntaDerecha
                   && arregloEnemigos.at(i)->getY() >= CentroInicioY && arregloEnemigos.at(i)->getY() <= CentroFinalY) 
                {
                    arregloEnemigos.erase(arregloEnemigos.begin() + i);
                }
                if (arregloEnemigos.at(i)->getY() >= PuntaSuperior && arregloEnemigos.at(i)->getY() <= PuntaInferior 
                    && arregloEnemigos.at(i)->getX() >= CentroInicioX && arregloEnemigos.at(i)->getX() <= CentroFinalX) 
                {
                    arregloEnemigos.erase(arregloEnemigos.begin() + i);
                }
            }
        }

    private:
        vector<CEnemigo*> arregloEnemigos;
};



#endif