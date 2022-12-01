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
        x=0; // posicion por defecto
        y=0; // ya vamos a sobreescribirlo pronto
        dx=5; // empieza moviendose a la derecha
        indiceX=0; // para animaciones
        indiceY=0;
        ancho= 96/6;
        alto=16;
        ubicado=false;  // hasta ahora no lo hemos ubicado
        estado=Normal;  // ni hemos eliminadok
    }
    void dibujar(Graphics^g, Bitmap^bmpEnemigo, int **matriz) {
        Rectangle porcionAusar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
        while ((matriz[i][j-1] != 2 || matriz[i][j] != 2 || matriz[i][j+1] !=2 ) && ubicado == false && i<14) {
            j++;
            if (j == 15) {
                i++;
                j = 0;
                if (i == 14) {
                    i = 1;
                }
            }
            x = j * 50;
            y = i * 50;
        }
        Rectangle Aumento = Rectangle(x, y, 40, 40); 
        g->DrawImage(bmpEnemigo, Aumento, porcionAusar, GraphicsUnit::Pixel);
        ubicado = true;
        x += dx;
        if ((matriz[y / 50][(x + 50) / 50] == 3 || matriz[y / 50][(x + 50) / 50] == 1 || 
            matriz[y / 50][(x - 10) / 50] == 3 || matriz[y / 50][(x - 10) / 50] == 1))
            dx *= -1;
    }
    void animar(){
        if(indiceX >=0 && indiceX<5){
            indiceX++; //va a paseando por las imagenes de la primera a la ultima
        }
        if(indiceX == 5){
            while(indiceX != 0)
                indiceX--; //ahora va a regresar del ultimo al primero (animaci�n bonita)
        }
    }
    Rectangle retornarRectangulo() {
        return Rectangle(x, y, 50, 50);
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
protected:
    int x; // posicion
    int y;

    int i; // posicion en la matriz
    int j;

    int dx; // movimiento (solamente horizontal)

    int indiceX; //para animar
    int indiceY;

    int ancho; //imagen
    int alto;

    bool ubicado; 

    Estado_Enemigo estado;


};
#endif