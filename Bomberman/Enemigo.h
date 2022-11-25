#ifndef __ENEMIGO_H__
#define __ENEMIGO_H__
#include <ctime>
#include <cstdlib>
using namespace System::Drawing;
enum Estado_Enemigo{Eliminado, Normal};
class CEnemigo
{
public:
    CEnemigo(){
        srand(time(NULL));
        i=rand()%13 + 1; // Fila del enemigo: de 1 a 13
        j=rand()%13 + 2; // Columna del enemigo: de 2 a 14
        x=715; // posicion por defecto
        y=650; // ya vamos a sobreescribirlo pronto
        dx=5; // empieza moviendose a la derecha
        indiceX=0; // para animaciones
        indiceY=0;
        ancho= 96/6;
        alto=16;
        ubicado=false;  // hasta ahora no lo hemos ubicado
        estado=Normal;  // ni hemos eliminadok
    }
    void dibujar(Graphics^g, Bitmap^bmpenemigo, int **matriz) {
        Rectangle porcionAusar = Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
        while((matriz[i][j-1] != 2 || matriz[i][j] != 2 || matriz[i][j+1] != 2) && ubicado == false) { // mientras no lo hemos ubicado
            j++; // lo intentamos encontrar sitio
            if(j == 15) { // al fin de la fila
                i++;    // vamos al siguiente fila
                j = 1;  // y empezamos al principio de la columna
            }
            if(i >= 14) {break;} // no hemos encontrado sitio :(
        }
        x = i * 50;     // actualizar su posicion
        y = j * 50;
        Rectangle Aumento = Rectangle(x, y, 40, 40); 
        g->DrawImage(bmpEnemigo, Aumento, porcionAUsar, GraphicsUnit::Pixel);
        ubicado = true;
        x += dx;
        if(matriz[y/50][(x+50)/50] == 3 || matriz[y/50][(x+50)/50] == 1 || matriz[y/50][(x-10)/50] == 3 || matriz[y/50][(x-10)/50] == 1) {
            dx *= -1;
        } // CHEQUEAR ESTO MAS ALLA, los resultados de esta division por enteros son adecuados??
    }
    void animar(){
        if(indiceX >=0 && indiceX<5){
            indiceX++;
        }
        if(indiceX == 5){
            while(indiceX != 0)
                {indiceX--;}
        }
    }
private:
    int x; // posicion
    int y;

    int i; // posicion en la matriz
    int j;

    int dx; // movimiento (solamente horizontal)

    int indiceX;
    int indiceY;

    int ancho;
    int alto;

    bool ubicado;
    Estado_Enemigo estado;


};
#endif