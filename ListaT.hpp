#include "ListaT.h"

template <class T>
void Lista<T>::inicializar(){
    this->cabeza = NULL;
    this->cola = NULL;
}

template <class T>
void Lista<T>::insertarNodo(T info){
    if(this->cabeza == NULL){
        this->cabeza = new Nodo<T>;
        this->cabeza->data = info;
        this->cabeza->siguiente = NULL;
        this->cola = this->cabeza;
    }else{
        Nodo<T>* temp = new Nodo<T>;
        temp->data = info;
        temp->siguiente = NULL;
        this->cola->siguiente = temp;
        this->cola = temp;
        temp = NULL;
    }
}

template <class T>
bool Lista<T>::esVacia(){
    if(this->cabeza==NULL){
        return true;
    }else{
        return false;
    }
}

template <class T>
Nodo<T>* Lista<T>::cabezaL(){
    return this->cabeza;
}

template <class T>
Nodo<T>* Lista<T>::colaL(){
    return this->cola;
}

template <class T>
int Lista<T>::longitud(){

    int longitud = 0;

    if(this->esVacia() == false){
        Nodo<T>* temp = this->cabeza;
        if(temp->siguiente == NULL){
            longitud = 1;
        }else{
            while(temp->siguiente != NULL){
                longitud++;
                temp = temp->siguiente;
            }
            longitud++;
        }
    }
    return longitud;
}

template <class T>
Pieza Lista<T>::obtenerPieza(int identificador){
    Pieza pieza;
    Nodo<T>* temp = this->cabeza;
    bool b = false;
    while(temp->siguiente != NULL && b == false){
        if(temp->data.tipo == identificador){
            pieza = temp->data;
            b = true;
        }
        temp = temp->siguiente;
    }
    if(temp->data.tipo == identificador && b == false){
        pieza = temp->data;
    }
    return pieza;
}

template <class T>
void Lista<T>::eliminarNodo(int identificador){

    if(this->cabeza->data.tipo == identificador){
        if(this->longitud() == 1){
            delete this->cabeza;
            this->cabeza = NULL;
            this->cola = NULL;
        }else if(this->longitud() == 2){
            delete this->cabeza;
            this->cabeza = this->cola;
        }else if(this->longitud() > 2){
            Nodo<T>* temp = this->cabeza;
            this->cabeza = temp->siguiente;
            delete temp;
        }
    }else if(this->cola->data.tipo == identificador){
        Nodo<T>* penultimo = this->cabeza;
        for(int i=0; i<this->longitud()-2;i++){
            penultimo = penultimo->siguiente;
        }
        penultimo->siguiente = NULL;
        delete this->cola;
        this->cola = penultimo;
    }else{
        Nodo<T>* temp = this->cabeza;
        bool b = false;
        while(temp->siguiente != NULL && b == false){
            if(temp->siguiente->data.tipo == identificador){
                Nodo<T>* siguiente = temp->siguiente;
                temp->siguiente = siguiente->siguiente;
                delete siguiente;
                b = true;
            }
            temp = temp->siguiente;
        }
    }
}

template <class T>
void Lista<T>::limpiar(){
    if(this->esVacia() == false){
        Nodo<Pieza>* nodo = this->cabeza;
        while(nodo->siguiente != NULL){
            Nodo<Pieza>* temp = nodo;
            nodo = nodo->siguiente;
            delete temp;
        }
    }
    this->cabeza = NULL;
    this->cola = NULL;
}

template <class T>
bool Lista<T>::buscarElemento(int identificador){
    bool b = false;
    if(this->longitud() != 0){
        Nodo<T>* nodo = this->cabeza;
        for(int i=0; i<this->longitud();i++){
            if(nodo->data.tipo == identificador){
                b = true;
            }
            nodo = nodo->siguiente;
        }
    }
    return b;
}
