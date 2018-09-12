#ifndef PIEZA_H
#define PIEZA_H

#include <string>

using namespace std;

struct Pieza{

    int tamano;
    string color;
    int coordenada_f;
    int coordenada_c;
    int rotacion;
    char** figura;
    int inversion;
    int filas;
    int columnas;
    int tipo;

    void crear (int tipo);
    void mostrar();
    void limpiarMemoria();
    void restablecer();
    void inicializarCoordenada(int fila, int columna);
    void rotar (int rotacion);
    void invertirHorizontalmente();
    void invertirVerticalmente();
    void mostrarRotaciones();
};

#endif
