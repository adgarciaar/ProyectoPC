#ifndef LISTAT_H
#define LISTAT_H

#include "NodoT.h"

template <class T>

struct Lista{
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    void inicializar();
    void insertarNodo(T nodo);
    bool esVacia();
    Nodo<T>* cabezaL();
    Nodo<T>* colaL();
    int longitud();
    Pieza obtenerPieza(int identificador); //obtiene el nodo con la identificacion
    void eliminarNodo(int identificador); //elimina el nodo con la identificacion
    void limpiar(); //limpia toda la lista
    bool buscarElemento(int identificador); //busca un elemento, devuelve true si lo encuentra
};

#include "ListaT.hpp"

#endif
