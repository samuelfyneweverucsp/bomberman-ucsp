#ifndef __ARRENEMIGOS_H__
#define __ARRENEMIGOS_H__

using namespace std;
#include <vector>
#include "Enemigo.h"

class CArrEnemigos {
    public:
        CArrEnemigos() {
            arregloEnemigos = vector<CEnemigo*>();
        }

        ~CArrEnemigos();
    
    private:
    friend class CControlador;
        vector<CEnemigo*> arregloEnemigos;

        void crearEnemigos() {
            CEnemigo* nuevo = new CEnemigo;
            arregloEnemigos.push_back(nuevo);
        }
        void dibujar(Graphics^g, Bitmap^bmpenemigo, int **matriz) {
            for(int i = 0; i < arregloEnemigos.size(); i++) {
                arregloEnemigos.at(i)->dibujar(g, bmpEnemigo, matriz);
                arregloEnemigos.at(i)->animar();
            }
        }

        vector<CEnemigo*> getArregloEnemigos() {return arregloEnemigos;}

};



#endif