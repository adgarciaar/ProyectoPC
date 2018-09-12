#include "ColaT.h"

template <class T>
void Cola<T>::inicializar(){
    this->cabeza = NULL;
    this->cola = NULL;
}

template <class T>
bool Cola<T>::esVacia(){
    if (this->cabeza == NULL){
        return true;
    }else{
        return false;
    }
}

template <class T>
void Cola<T>::insertar(T dato){
    if(this->cabeza == NULL){
        this->cola = new Nodo<T>;
        this->cola->data = dato;
        this->cola->siguiente = NULL;
        this->cabeza = this->cola;
    }else{
        Nodo<T>* temp = new Nodo<T>;
        temp->data = dato;
        temp->siguiente = NULL;
        this->cola = temp;
        if(this->cabeza->siguiente == NULL){
            this->cabeza->siguiente = temp;
        }else{
            Nodo<T>* nodo = this->cabeza;
            while(nodo->siguiente != NULL){
                nodo = nodo->siguiente;
            }
            nodo->siguiente = temp;
        }
    }
}

template <class T>
Nodo<T>* Cola<T>::atenderCabeza(){
    Nodo<T>* temp = this->cabeza;
    if (this->cabeza->siguiente != NULL){
        this->cabeza = this->cabeza->siguiente;
    }else{
        this->cabeza = NULL;
        this->cola = NULL;
    }
    return temp;
}

template <class T>
Nodo<T>* Cola<T>::cabezaC(){
    return this->cabeza;
}

template <class T>
void Cola<T>::limpiar(){
    Nodo<T>* temp;
    while(this->esVacia() == false){
        temp = this->atenderCabeza();
        delete temp;
    }
    temp = NULL;
}
