#ifndef __JUGADOR_H__
#define __JUGADOR_H__

using namespace Sytem::Drawing;

/* Fuente: https://www.youtube.com/watch?v=VReulZBhSuI&list=PLNACkYS5556GB2C72RRWurw0DkoTHod-P&index=3 */

enum Direcciones{Arriba,Abajo,Izquierda,Derecha,Ninguna}; // Las direcciones a las cuáles se puede dirigir el jugador
// Para más información acerca del ENUM, véase aquí: https://learn.microsoft.com/es-es/cpp/cpp/enumerations-cpp?view=msvc-170
// o acá (más fácil con ejemplos, pero en inglés): https://www.programiz.com/cpp-programming/enumeration

class CJugador() {
public: 
    CJugador(int x, int y) {
        // Inicializar la posición del jugador
        this -> x = x;
        this -> y = y;
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

    }
    ~CJugador() {}

    void setDireccion(Direcciones direccion) {
        this -> direccion = direccion;
    }

    void dibujarJugador(Graphics^g, Bitmap^bmpJugador) {
        Rectangle PorcionAUsar = Rectangle(indiceX*ancho, indiceY*alto, ancho, alto);
        Rectangle Aumento = Rectangle(x, y, ancho*3, alto*3);
        g->DrawImage(bmpJugador, Aumento, PorcionAUsar, GraphicsUnit::Pixel);
        x += dx; // mover en el eje x
        y += dy; // mover en el eje y
    }

    void moverJugador(Graphics^g, Bitmap^bmpJugador) {
        direccion == Arriba ? ancho = 17 : ancho = 18;
        dibujarJugador(g, bmpJugador);
        switch (direccion) {
            case Direcciones::Arriba:
                indiceY = 0; // las imagenes de caminar hacía abajo están en el indiceY 0
                indiceX = 1; // para empezar el ciclo de caminar hacía arriba
                if(indiceX>=1 & indiceX < 3)
                    indiceX++; // para avanzar en el ciclo de caminar hacia arriba
                else
                    indiceX = 1; // para mantener el ciclo de caminar hacia arriba
                dx = 0; // no moviéndose en el eje x
                dy = -10; // moviéndose hacía arriba; su coordinado se está disminuyendo
                ultima = Arriba; // para animarlo
                break;
            case Direcciones::Abajo:
                indiceX = 0; // las imagenes de caminar hacía abajo están en el indiceX 0
                indiceY = 1; // para empezar el ciclo de caminar hacia abajo
                if(indiceY >= 1 & indiceY < 3)
                    indiceY++; // para avanzar en el ciclo de caminar hacia abajo
                else
                    indiceY = 1; // para mantener el ciclo de caminar hacia arriba
                dx = 0; // todavía no moviéndose en el eje x
                dy = 10; // moviéndose hacía abajo; su coordinado se está aumentando
                ultima = Abajo;
                break;
            case Direcciones::Izquierda:
                indiceY = 3; // las imagenes de caminar hacía la izquierda están en el indiceY 3
                indiceX = 1; // para empezar el ciclo de caminar hacía la izquierda
                if(indiceX >= 1 & indiceX < 3)
                    indiceX++; // para avanzar en el ciclo de caminar hacia la izquierda
                else
                    indiceX = 1; // para mantener el ciclo de caminar hacia la izquierda
                dx = -10; //  moviéndose hacía la izquierda; su coordinado se está diminuyendo
                dy = 0; // no moviéndose en el eje y
                ultima = Izquierda;
                break;
            case Direcciones::Derecha:
                indiceY = 1; // las imagenes de caminar hacía la izquierda están en el indiceY 1
                indiceX = 1; // para empezar el ciclo de caminar hacía la derecha
                if(indiceY >= 1 & indiceY < 3)
                    indiceY++; // para avanzar en el ciclo de caminar hacia abajo
                else
                    indiceY = 1; // para mantener el ciclo de caminar hacia arriba
                dx = -10; //  moviéndose hacía la izquierda; su coordinado se está diminuyendo
                dy = 0; // no moviéndose en el eje y
                ultima = Izquierda;
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
    }

private:
    int x;
    int y;
    int dx;
    int dy;
    int ancho;
    int alto; 
    int indiceX;
    int indiceY;
    Direcciones direccion; // dirección actual
    Direcciones ultima; // en qué posición estaba antes
}

#endif
