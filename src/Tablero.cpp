#include "Tablero.h"

#include <iostream>

using namespace std;

void Tablero::inicializar(){

    //inicialización matriz

    this->matriz = new char*[8];

    for (int i = 0; i < 8; i++){
        *(this->matriz+i) = new char[8];
    }

    int i, j;

    //inicializar primera columnna
    j = 0;
    for (i = 0; i<8; i++){
        (*(*(this->matriz+i)+j)) = '#';
    }

    //inicializar última columna
    j = 7;
    for (i = 0; i<8; i++){
        (*(*(this->matriz+i)+j)) = '#';
    }

    //inicializar primera fila
    i = 0;
    for (j = 0; j<8; j++){
        (*(*(this->matriz+i)+j)) = '#';
    }

    //inicializar última fila
    i = 7;
    for (j = 0; j<8; j++){
        (*(*(this->matriz+i)+j)) = '#';
    }

    //inicializar espacio disponible para fichas
    for (i = 1; i<7; i++){
        for (j = 1; j<7; j++){
            (*(*(this->matriz+i)+j)) = ' ';
        }
    }
}

void Tablero::imprimir(){

    cout<<endl<<endl<<"  TABLERO DE JUEGO"<<endl;

    for (int i = 0; i<8; i++){
        cout<<endl;
        for (int j = 0; j<8; j++){
            if(j==0){
                cout<<"   ";
            }
            if(j>0 && j<7){
                cout<<(*(*(this->matriz+i)+j));
            }
            cout<<(*(*(this->matriz+i)+j));
        }
        if (i>0 && i<7){
            cout<<endl;
            for (int j = 0; j<8; j++){
                if(j==0){
                    cout<<"   ";
                }
                if(j>0 && j<7){
                    cout<<(*(*(this->matriz+i)+j));
                }
                cout<<(*(*(this->matriz+i)+j));
            }
        }
    }
}

void Tablero::liberarMemoria(){
    //liberar memoria para la matriz
    for (int j = 0; j < 8; j++){
        delete[] *(this->matriz+j);
    }
    delete[] this->matriz;
    this->matriz = NULL;
}

void Tablero::agregarPieza(Pieza& pieza, int fila, int columna){

    char color = ' ';
    if (pieza.color == "Azul"){
        color = 'X';
    }else if (pieza.color == "Verde"){
        color = 'O';
    }else if(pieza.color == "Rojo"){
        color = 'H';
    }

    pieza.inicializarCoordenada(fila,columna);

    for (int i = 0; i<pieza.filas; i++){
        for (int j = 0; j<pieza.columnas; j++){
            if ( (*(*(pieza.figura+i)+j)) == '0' ){
                (*(*(this->matriz+fila)+columna)) = color;
            }
            columna++;
        }
        fila++;
        columna = columna - pieza.columnas;
    }
}

bool Tablero::validarCoordenada(Pieza& pieza, int fila, int columna){
    bool b1, b2 = true;
    //primero, verificar que quede dentro del tablero
    if (columna>=1 && columna<=4 && fila>=1 && fila<=4){ //se garantiza que va a quedar dentro sin importar la pieza
        b1 = true;
    }else{
        if (pieza.tamano == 1){ //si es la pieza de 1 cuadrado no tiene riesgo de quedar por fuera
            b1 = true;
        }else{ //se suman filas y columnas de la pieza para determinar si puede quedar dentro
            int tamano_columnas, tamano_filas;
            tamano_columnas = columna + pieza.columnas;
            tamano_filas = fila + pieza.filas;
            tamano_columnas--;
            tamano_filas--;
            if (tamano_columnas>6 || tamano_filas > 6){
                b1 = false;
            }else{
                b1 = true;
            }
        }
    }

    //ahora verificar que no sobrelape otras piezas, sólo si queda dentro del tablero

    if(b1 == true){
        int tamano_columnas, tamano_filas;
        tamano_columnas = columna + pieza.columnas;
        tamano_filas = fila + pieza.filas;

        int x = 0, y = 0;

        for (int i = fila; i<tamano_filas; i++){
            x = 0;
            for (int j = columna; j<tamano_columnas; j++){
                if ( (*(*(this->matriz+i)+j)) != ' ' ){
                    if((*(*(pieza.figura+y)+x)) != ' '){
                        b2 = false;
                    }
                }
                x++;
            }
            y++;
        }
    }

    //por último verificar si la pieza cumplió ambas condiciones

    if(b1 == true && b2 == true){
        return true;
    }else{
        return false;
    }
}

bool Tablero::estaLleno(){
    short contador = 0;
    for (int i = 1; i<7; i++){
        for (int j = 1; j<7; j++){
            if ( (*(*(this->matriz+i)+j)) != ' ' ){
                contador++;
            }
        }
    }
    if(contador == 36){ //significa que está lleno con las piezas
        return true;
    }else{
        return false; //aún no se ha llenado
    }
}
