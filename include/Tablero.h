#ifndef TABLERO_H
#define TABLERO_H

#include "Pieza.h"

struct Tablero{

    char** matriz;

    void inicializar();
    void imprimir();
    void liberarMemoria();
    void agregarPieza(Pieza& pieza, int fila, int columna);
    bool validarCoordenada(Pieza& pieza, int fila, int columna);
    bool estaLleno();
};

#endif
