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
        this->x = x;
        this->y = y;
        estado = Estado::normal;

        ancho = 22; // 66 (anchura de la imagen de 3 bombas) entre 3 (para retornar una bomba)
        alto = 24; // altura de cada bomba

        indiceX = 0;
        tiempo_antes_de_explotar = 0;
    };

    bool validarLugar(int xJugador, int yJugador, int **matriz) { // comprobar si podemos poner una bomba allí o no
        if(matriz[yJugador/50][xJugador/50] == 0 || matriz[yJugador/50][xJugador/50] == 2) // si es vacío
            return true; // puedes poner bomba
        else // si no es vacío
            return false; // no puedes
    }

    void dibujarBomba(Graphics^g, Bitmap^bmpBomba) {
        if(validarLugar(x, y, CEscenario.getMatriz()) == true) {
            Rectangle porcionAUsar = Rectangle(indiceX * ancho, 0, ancho, alto);
            Rectangle aumento = Rectangle(x, y, 40, 40);
            g->DrawImage(bmpBomba, aumento, porcionAUsar, GraphicsUnit::Pixel);
        }
        if(tiempo_antes_de_explotar == 6) {estado = Estado::explosion;}
        
    }

    ~CBomba();

private:
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