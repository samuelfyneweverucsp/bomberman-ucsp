#ifndef __ENEMIGO_H__
#define __ENEMIGO_H__
#include <ctime>
#include <cstdlib>
using namespace System::Drawing;
enum Estado_enemigo{Eliminado, Normal};
class CEnemigo
{
public:
    CEnemigo(){
        srand(time(NULL));
        i=rand()%13 + 1;
        j=rand()%13 + 2;
        x=715;
        y=650;
        dx=5;
        indiceX=0;
        indiceY=0;
        ancho= 96/6;
        alto=16;
        ubicado=false;
        estado=Normal;
    }
    void dibujar(Graphics^g, Bitmap^bmpenemigo, int **matriz){
        Rectangle porcionAusar = Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
    }
    void animar(){
        if(indiceX >=0 && indiceX<5){
            indiceX++;
        }
        if(indiceX == 5){
            indiceX--;
        }
    }
private:
    int x;
    int y;

    int i;
    int j;

    int dx;

    int indiceX;
    int indiceY;

    int ancho;
    int alto;

    bool ubicado;


};
#endif