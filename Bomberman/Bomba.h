#ifndef __BOMBA_H__
#define __BOMBA_H__

using namespace System::Drawing;

/* Fuente para implementar la bomba:
https://www.youtube.com/watch?v=RfWfvZ7mgNg&list=PLNACkYS5556GB2C72RRWurw0DkoTHod-P&index=6
*/

enum Estado{normal, explosion, desaparecer};
// Para más acerca de ENUM, váse acá: 
// https://learn.microsoft.com/es-es/cpp/cpp/enumerations-cpp?view=msvc-170
// o aquí: https://www.programiz.com/cpp-programming/enumeration

class CBomba {
public:
    CBomba(int x, int y) {
        // Datos iniciales para la bomba
        this->x = x;
        this->y = y;
        estado = Estado::normal;

        ancho = 22; // 66 (anchura de la imagen de 3 bombas) entre 3 (para retornar una bomba)
        alto = 24; // altura de cada bomba

        indiceX = 0;
        tiempo_antes_de_explotar = 0;

        // Datos iniciales para la explosion
        indiceEX = 0;
        indiceEY = 0;
        altoExplosion = 160/8; // 160/8??
        anchoExplosion = 80 / 4; // 80/4??
    };
    ~CBomba() {}

    bool validarLugar(int xJugador, int yJugador, int **matriz) { // comprobar si puedes poner una bomba allí donde estás o no
        if(matriz[yJugador/50][xJugador/50] == 0 || matriz[yJugador/50][xJugador/50] == 2) // si es vacío
            return true; // puedes poner bomba
        else // si no es vacío
            return false; // no puedes
    }

    void dibujarBomba(Graphics^g, Bitmap^bmpBomba, int xJugador, int yJugador, int** matriz) {
        if(validarLugar(xJugador, yJugador, matriz) == true) {
            Rectangle porcionAUsar = Rectangle(indiceX * ancho, 0, ancho, alto);
            Rectangle aumento = Rectangle(x, y, 40, 40);
            g->DrawImage(bmpBomba, aumento, porcionAUsar, GraphicsUnit::Pixel);
        }
        if(tiempo_antes_de_explotar == 6) {estado = Estado::explosion;}
        
    }

    void animar() {
        if(indiceX >= 0 && indiceX < 2) 
        indiceX++; 
        else {
            tiempo_antes_de_explotar++;
            indiceX = 0; 
            }

    }
    void DibujarExplosion(Graphics^ g, Bitmap^ bmpExplosionCentro, int** matriz) {

        Rectangle porcionUsarCentro = Rectangle(indiceEX * anchoExplosion, indiceEY * altoExplosion, anchoExplosion, altoExplosion); // indiceY=0
        Rectangle centro = Rectangle(x, y, 50, 50);
        g->DrawImage(bmpExplosionCentro, centro, porcionUsarCentro, GraphicsUnit::Pixel);
        if (matriz[y / 50][(x - 50) / 50] != 1) {
            Rectangle porcionUsarIzquierda = Rectangle(indiceEX * anchoExplosion, indiceEY + 2 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 2
            Rectangle izquierda = Rectangle(x - 50, y, 50, 50);
            g->DrawImage(bmpExplosionCentro, izquierda, porcionUsarIzquierda, GraphicsUnit::Pixel);

            if (matriz[y / 50][(x - 50) / 50] == 3) { matriz[y / 50][(x - 50) / 50] = 2; }
        }


        if (matriz[y / 50][(x + 50) / 50] != 1) {
            Rectangle porcionUsarDerecha = Rectangle(indiceEX * anchoExplosion, indiceEY + 4 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 4
            Rectangle derecha = Rectangle(x + 50, y, 50, 50);
            g->DrawImage(bmpExplosionCentro, derecha, porcionUsarDerecha, GraphicsUnit::Pixel);

            if (matriz[y / 50][(x + 50) / 50] == 3) { matriz[y / 50][(x + 50) / 50] = 2; }

        }
        if (matriz[y / 50][(x + 50) / 50] != 1) {
            Rectangle porcionUsarPuntaDerecha = Rectangle(indiceEX * anchoExplosion, indiceEY + 3 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 3
            Rectangle Puntaderecha = Rectangle(x + 100, y, 50, 50);
            g->DrawImage(bmpExplosionCentro, Puntaderecha, porcionUsarPuntaDerecha, GraphicsUnit::Pixel);

            if (matriz[y / 50][(x + 100) / 50] == 3 && matriz[y / 50][(x + 50) / 50] != 1)
            {

                matriz[y / 50][(x + 100) / 50] = 2;
            }
        }

        if (matriz[y / 50][(x - 50) / 50] != 1) {
            Rectangle porcionUsarPuntaIzquierda = Rectangle(indiceEX * anchoExplosion, indiceEY + 1 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 1
            Rectangle Puntaizquierda = Rectangle(x - 100, y, 50, 50);
            g->DrawImage(bmpExplosionCentro, Puntaizquierda, porcionUsarPuntaIzquierda, GraphicsUnit::Pixel);

            if (matriz[y / 50][(x - 100) / 50] == 3 && matriz[y / 50][(x - 50) / 50] != 1)
            {
                matriz[y / 50][(x - 100) / 50] = 2;
            }
        }

        Rectangle porcionUsarVerticales = Rectangle(indiceEX * anchoExplosion, indiceEY + 6 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 1
        Rectangle VerticalSuperior = Rectangle(x, y - 50, 50, 50);
        Rectangle VerticalInferior = Rectangle(x, y + 50, 50, 50);

        if (matriz[(y - 50) / 50][x / 50] != 1) { g->DrawImage(bmpExplosionCentro, VerticalSuperior, porcionUsarVerticales, GraphicsUnit::Pixel); }
        if (matriz[(y - 50) / 50][x / 50] == 3) { matriz[(y - 50) / 50][x / 50] = 2; }
        if (matriz[(y + 50) / 50][x / 50] != 1) { g->DrawImage(bmpExplosionCentro, VerticalInferior, porcionUsarVerticales, GraphicsUnit::Pixel); }
        if (matriz[(y + 50) / 50][x / 50] == 3) { matriz[(y + 50) / 50][x / 50] = 2; }


        if (matriz[(y - 50) / 50][x / 50] != 1) {
            Rectangle porcionUsarPuntaSuperior = Rectangle(indiceEX * anchoExplosion, indiceEY + 5 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 5
            Rectangle PuntaSuperior = Rectangle(x, y - 100, 50, 50);
            g->DrawImage(bmpExplosionCentro, PuntaSuperior, porcionUsarPuntaSuperior, GraphicsUnit::Pixel);

            if (matriz[(y - 100) / 50][x / 50] == 3 && matriz[(y - 50) / 50][x / 50] != 1) { matriz[(y - 100) / 50][x / 50] = 2; }
        }


        if (matriz[(y + 50) / 50][x / 50] != 1) {
            Rectangle porcionUsarPuntaInferior = Rectangle(indiceEX * anchoExplosion, indiceEY + 7 * altoExplosion, anchoExplosion, altoExplosion); //indiceY = 7
            Rectangle PuntaInferior = Rectangle(x, y + 100, 50, 50);
            g->DrawImage(bmpExplosionCentro, PuntaInferior, porcionUsarPuntaInferior, GraphicsUnit::Pixel);
            if (matriz[(y + 100) / 50][x / 50] == 3 && matriz[(y + 50) / 50][x / 50] != 1) {
                matriz[(y + 100) / 50][x / 50] = 2;
            }
        }
    }
    /*void dibujarExplosion(Graphics^ g, Bitmap^ bmpBomba) {

        Rectangle porcionAUsar = Rectangle(indiceEX*anchoExplosion, indiceEY*altoExplosion, anchoExplosion, altoExplosion); // indiceY = 0
        Rectangle centro = Rectangle(x, y, 50, 50);
        g->DrawImage(bmpBomba, centro, porcionAUsar, GraphicsUnit::Pixel);

        if (tiempo_antes_de_explotar == 6){estado = Estado::explosion;}


    }
    */
    void animarExplosion() {
        if(indiceEX >= 0 && indiceEX < 3) {
            indiceEX++;
        } else {
            estado = Estado::desaparecer;
        }
    }

    Estado getEstado() {
        return estado;
    }

    int getX() {return x;}
    int getY() {return y;}

private: // de la explosión de la bomba
    int indiceEX;
    int indiceEY;

    int altoExplosion;
    int anchoExplosion;


private: // de la bomba
    int x;
    int y;

    int ancho;
    int alto;

    int indiceX; // para la animación
    // no hace falta indiceY porque todas las imágenes están en la misma fila

    int tiempo_antes_de_explotar;

    Estado estado;

};

#endif __BOMBA_H__