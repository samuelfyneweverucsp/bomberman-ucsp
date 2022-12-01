#include <iostream>
#ifndef __JUGADOR_H__
#define __JUGADOR_H__

using namespace System::Drawing;

/* Fuente para establecer el jugador: 
https://www.youtube.com/watch?v=VReulZBhSuI&list=PLNACkYS5556GB2C72RRWurw0DkoTHod-P&index=3 
   Fuente para validar los muros y paredes: 
https://www.youtube.com/watch?v=ewFiVTtnZSg&list=PLNACkYS5556GB2C72RRWurw0DkoTHod-P&index=4 
   (es decir, prohibir que los jugadores caminaran encima de los muros/paredes)
   Fuente para disminución de las vidas:
https://www.youtube.com/watch?v=ytGeCR9s924&list=PLNACkYS5556GB2C72RRWurw0DkoTHod-P&index=8

*/

enum Direcciones{Arriba,Abajo,Izquierda,Derecha,Ninguna}; 
// Las direcciones a las cuáles se puede dirigir el jugador
// Para más información acerca del ENUM, véase aquí: https://learn.microsoft.com/es-es/cpp/cpp/enumerations-cpp?view=msvc-170
// o acá (más fácil con ejemplos, pero en inglés): https://www.programiz.com/cpp-programming/enumeration

class CJugador {
public:
    CJugador(){}
    CJugador(int posx, int posy) {
        initial_posx = posx;
        initial_posy = posy;
        // Inicializar la posición del jugador
        x = posx;
        y = posy;
        // Inicializar su movimiento en CERO (no está moviéndose al momento de crearse)
        dx = 0;
        dy = 0;
        // Animación del sprite: necesitamos colocar cuán alto y cuán ancho es para luego animarlo
        ancho = 18;
        alto = 26;
        indiceX = 0;
        indiceY = 0;
        // y ahora colocamos adonde se dirige
        direccion = Direcciones::Ninguna; 
        ultima = Direcciones::Abajo; // empieza dirigido hacía abajo
        this->CAA=CAA;
        this->CDI=CDI;

        vidas = 3;
        aceleracion = 0;
    }
    ~CJugador() {}
    void setVidas(int v) { vidas = v; }
    int getVidas() { return vidas; }
    void setAceleracion(int a) { aceleracion = a; }
    int getAceleracion() { return aceleracion; }
    int getX() { return x + 2 * 3;}
    int getY() { return y + 15 * 3 + dy;}
    Rectangle retornarRectangulo() {
        return Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3);
    }

    void setDireccion(Direcciones direccion) {
        this -> direccion = direccion;
    }

    void ValidarMovimiento(int **matriz) {
        int X = 0;
        int Y = 0;
        for (int i = 0; i < filas; i++)
        {
            X = 0; // al empezar en una nueva fila, nos ubicamos en la primera columna
            for (int j = 0; j < columnas; j++)
            {
                 Rectangle c1 = Rectangle(X, Y, 50, 50); // el rectangulo del bloque actual
                 if (matriz[i][j] == 1 || matriz[i][j] == 3) {
                    if (CDI.IntersectsWith(c1))dx = 0;  // si el jugador choca horizontalmente con un bloque, no debe poder seguir horizontalmente
                    if (CAA.IntersectsWith(c1))dy = 0;  // si el jugador choca verticalmente con un bloque, no debe poder seguir vertialmente
                }

                X += 50; // cambiar de columna (mover hacia la derecha)
            }
            Y += 50; // cambiar de fila (mover hacia abajo)
        }
        
    }

    void disminuirvidas() {
        x = initial_posx;
        y = initial_posy;
        vidas--;
    }

    void disminuirvidas(int PuntaIzquierda, int PuntaDerecha, int CentroInicioY, int CentroFinalY, 
                        int PuntaSuperior, int PuntaInferior, int CentroInicioX, int CentroFinalX) {
        if(getX() >= PuntaIzquierda && getX() <= PuntaDerecha && getY() >= CentroInicioY && getY() <= CentroFinalY) {
            x = initial_posx;
            y = initial_posy;
            vidas--;
        }
        if(getY() >= PuntaSuperior && getY() <= PuntaInferior && getX() >= CentroInicioX && getX() <= CentroFinalX) {
            x = initial_posx;
            y = initial_posy;
            vidas--;
        }
    }

    void dibujarJugador(Graphics^g, Bitmap^bmpJugador,int **matriz) {
        CDI = Rectangle(x + 2 * 3 + dx, y + 15 * 3, (ancho - 4) * 3, (alto - 15) * 3);  
            // multiplicando por tres porque el jugador es más pequeño que los bloques
        CAA = Rectangle(x + 2 * 3, y + 15 * 3 + dy, (ancho - 4) * 3, (alto - 15) * 3);

        g->DrawRectangle(Pens::Red, CDI); // originalmente Red
        g->DrawRectangle(Pens::Orange, CAA); // originalmente Orange
        // para poder ver los Rectangles

        ValidarMovimiento(matriz);

        Rectangle PorcionAUsar = Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
        Rectangle Aumento = Rectangle(x, y, ancho*3, alto*3);
        g->DrawImage(bmpJugador, Aumento, PorcionAUsar, GraphicsUnit::Pixel);
        x += dx; // mover en el eje x
        y += dy; // mover en el eje y
    }

    void moverJugador(Graphics^g, Bitmap^bmpJugador, int **matriz) {
        direccion == Arriba ? ancho = 17 : ancho = 18;
        dibujarJugador(g, bmpJugador,matriz);           
        switch (direccion) {
            case Direcciones::Arriba:
                indiceY = 0; // las imagenes de caminar hacía abajo están en el indiceY 0
               
                if(indiceX>=1 && indiceX < 3)
                    indiceX++; // para avanzar en el ciclo de caminar hacia arriba
                else
                    indiceX = 1; // para mantener el ciclo de caminar hacia arriba
                dx = 0; // no moviéndose en el eje x
                dy = -10 - aceleracion; // moviéndose hacía arriba; su coordinado se está disminuyendo
                ultima = Arriba; // para animarlo
                break;
            case Direcciones::Abajo:
                indiceX = 0; // las imagenes de caminar hacía abajo están en el indiceX 0
                
                if(indiceY >= 1 && indiceY < 3)
                    indiceY++; // para avanzar en el ciclo de caminar hacia abajo
                else
                    indiceY = 1; // para mantener el ciclo de caminar hacia arriba
                    dx = 0; // todavía no moviéndose en el eje x
                    dy = 10 + aceleracion; // moviéndose hacía abajo; su coordinado se está aumentando
                    ultima = Abajo;
                    break;
            case Direcciones::Izquierda:
                indiceY = 3; // las imagenes de caminar hacía la izquierda están en el indiceY 3
                
                if(indiceX >= 1 && indiceX < 3)
                    indiceX++; // para avanzar en el ciclo de caminar hacia la izquierda
                else
                    indiceX = 1; // para mantener el ciclo de caminar hacia la izquierda
                    dx = -10 - aceleracion; //  moviéndose hacía la izquierda; su coordinado se está diminuyendo
                    dy = 0; // no moviéndose en el eje y
                    ultima = Izquierda;
                    break;
            case Direcciones::Derecha:
                indiceY = 1; // las imagenes de caminar hacía la izquierda están en el indiceY 1
                
                if(indiceX >= 1 && indiceX < 3)
                    indiceX++; // para avanzar en el ciclo de caminar hacia abajo
                else
                    indiceX = 1; // para mantener el ciclo de caminar hacia arriba
                dx = 10 + aceleracion; //  moviéndose hacía la izquierda; su coordinado se está diminuyendo
                dy = 0; // no moviéndose en el eje y
                ultima = Derecha;
                break;
            case Direcciones::Ninguna:
                dx = 0;
                dy = 0;
                if (ultima == Direcciones::Abajo) {
                    indiceX = 0; // para quedarse dirigido abajo sin animar movimiento,
                    indiceY = 2; // seguir en la imagen de indiceX 0, indiceY 2
                }
                if (ultima == Direcciones::Arriba) {
                    indiceX = 0; // para quedarse dirigido arriba sin animar movimiento,
                    indiceY = 0; // seguir en la imagen de indiceX 0, indiceY 0
                }
                if (ultima == Direcciones::Derecha) {
                    indiceX = 1; // para quedarse dirigido a la derecha sin animar movimiento,
                    indiceY = 1; // seguir en la imagen de indiceX 1, indiceY 1
                }
                if (ultima == Direcciones::Izquierda) {
                    indiceX = 1; // para quedarse dirigido a la izquierda sin animar movimiento,
                    indiceY = 3; // seguir en la imagen de indiceX 1, indiceY 3
                }
                break;
            default:
                break;
        }
        dibujarJugador(g, bmpJugador,matriz);
    }

private:
    int initial_posx;//guaradrá la posición de inicio
    int initial_posy;

    int x; // posición
    int y; // posición
    int dx; // movimiento (velocidad)
    int dy; // movimiento (velocidad)
    int ancho; // anchura del jugador
    int alto;  // altura del jugador
    int indiceX; // índices para usar para la animación
    int indiceY; // (qué imagen usar para el sprite)

    int vidas;
    int aceleracion;

    Direcciones direccion; // dirección actual
    Direcciones ultima; // en qué posición estaba antes

    Rectangle CDI; // derecha-izquierda
    Rectangle CAA; // arriba-abajo

};

#endif
