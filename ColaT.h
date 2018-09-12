#ifndef COLAT_H
#define COLAT_H

#include "NodoT.h"

template <class T>
struct Cola{
    Nodo<T>* cabeza;
    Nodo<T>* cola;

    void inicializar();
    bool esVacia();
    void insertar(T dato);
    Nodo<T>* atenderCabeza(); //elimina la cabeza de la cola y la devuelve
    Nodo<T>* cabezaC();
    void limpiar();
};

#include "ColaT.hpp"

#endif
