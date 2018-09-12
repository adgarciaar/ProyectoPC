#include "Pieza.h"

#include <iostream>

using namespace std;

void Pieza::crear(int tipo){

    this->tipo = tipo;
    this->rotacion = 0;
    this->inversion = 0;

    switch (tipo){

        //figura de 1 cuadrado roja
        case 1:

            this->color = "Rojo";
            this->tamano = 1;
            this->filas = 1;
            this->columnas = 1;

            //inicializar figura

            //filas
            this->figura = new char*[this->filas];
            //columnas
            for (int i = 0; i < this->filas; i++){
                *(this->figura+i) = new char[this->columnas];
            }
            (*(*(this->figura+0)+0)) = '0';

            break;

        //figura de 2 cuadrados roja
        case 2:

            this->color = "Rojo";
            this->tamano = 2;
            this->filas = 1;
            this->columnas = 2;

            //inicializar figura

            //filas
            this->figura = new char*[this->filas];
            //columnas
            for (int i = 0; i < this->filas; i++){
                *(this->figura+i) = new char[this->columnas];
            }
            (*(*(this->figura+0)+0)) = '0';
            (*(*(this->figura+0)+1)) = '0';

            break;

        //figura de 3 cuadrados plana azul
        case 3:

            this->color = "Azul";
            this->tamano = 3;
            this->filas = 1;
            this->columnas = 3;

            //inicializar figura

            //filas
            this->figura = new char*[this->filas];
            //columnas
            for (int i = 0; i < this->filas; i++){
                *(this->figura+i) = new char[this->columnas];
            }
            (*(*(this->figura+0)+0)) = '0';
            (*(*(this->figura+0)+1)) = '0';
            (*(*(this->figura+0)+2)) = '0';

            break;

        //figura de 3 cuadrados en forma de frisby verde
        case 4:

            this->color = "Verde";
            this->tamano = 3;
            this->filas = 2;
            this->columnas = 2;

            //inicializar figura

            //filas
            this->figura = new char*[this->filas];
            //columnas
            for (int i = 0; i < this->filas; i++){
                *(this->figura+i) = new char[this->columnas];
            }

            (*(*(this->figura+0)+0)) = ' ';
            (*(*(this->figura+0)+1)) = '0';
            (*(*(this->figura+1)+0)) = '0';
            (*(*(this->figura+1)+1)) = '0';

            break;

        //figura de 4 cuadrados en forma de L roja
        case 5:

            this->color = "Rojo";
            this->tamano = 4;
            this->filas = 2;
            this->columnas = 3;

            //inicializar figura

            //filas
            this->figura = new char*[this->filas];
            //columnas
            for (int i = 0; i < this->filas; i++){
                *(this->figura+i) = new char[this->columnas];
            }

            (*(*(this->figura+0)+0)) = '0';
            (*(*(this->figura+0)+1)) = ' ';
            (*(*(this->figura+0)+2)) = ' ';
            (*(*(this->figura+1)+0)) = '0';
            (*(*(this->figura+1)+1)) = '0';
            (*(*(this->figura+1)+2)) = '0';

            break;

        //figura de 4 cuadrados verde
        case 6:

            this->color = "Verde";
            this->tamano = 4;
            this->filas = 2;
            this->columnas = 3;

            //inicializar figura

            //filas
            this->figura = new char*[this->filas];
            //columnas
            for (int i = 0; i < this->filas; i++){
                *(this->figura+i) = new char[this->columnas];
            }

            (*(*(this->figura+0)+0)) = '0';
            (*(*(this->figura+0)+1)) = '0';
            (*(*(this->figura+0)+2)) = '0';
            (*(*(this->figura+1)+0)) = ' ';
            (*(*(this->figura+1)+1)) = '0';
            (*(*(this->figura+1)+2)) = ' ';

            break;

        //figura de 4 cuadrados azul
        case 7:

            this->color = "Azul";
            this->tamano = 4;
            this->filas = 3;
            this->columnas = 2;

            //inicializar figura

            //filas
            this->figura = new char*[this->filas];
            //columnas
            for (int i = 0; i < this->filas; i++){
                *(this->figura+i) = new char[this->columnas];
            }

            (*(*(this->figura+0)+0)) = '0';
            (*(*(this->figura+0)+1)) = ' ';
            (*(*(this->figura+1)+0)) = '0';
            (*(*(this->figura+1)+1)) = '0';
            (*(*(this->figura+2)+0)) = ' ';
            (*(*(this->figura+2)+1)) = '0';

            break;

        //figura de 5 cuadrados roja
        case 8:

            this->color = "Rojo";
            this->tamano = 5;
            this->filas = 3;
            this->columnas = 3;

            //inicializar figura

            //filas
            this->figura = new char*[this->filas];
            //columnas
            for (int i = 0; i < this->filas; i++){
                *(this->figura+i) = new char[this->columnas];
            }

            (*(*(this->figura+0)+0)) = ' ';
            (*(*(this->figura+0)+1)) = '0';
            (*(*(this->figura+0)+2)) = ' ';
            (*(*(this->figura+1)+0)) = ' ';
            (*(*(this->figura+1)+1)) = '0';
            (*(*(this->figura+1)+2)) = ' ';
            (*(*(this->figura+2)+0)) = '0';
            (*(*(this->figura+2)+1)) = '0';
            (*(*(this->figura+2)+2)) = '0';

            break;

        //figura de 5 cuadrados en forma de serpiente verde
        case 9:

            this->color = "Verde";
            this->tamano = 5;
            this->filas = 3;
            this->columnas = 3;

            //inicializar figura

            //filas
            this->figura = new char*[this->filas];
            //columnas
            for (int i = 0; i < this->filas; i++){
                *(this->figura+i) = new char[this->columnas];
            }

            (*(*(this->figura+0)+0)) = '0';
            (*(*(this->figura+0)+1)) = '0';
            (*(*(this->figura+0)+2)) = ' ';
            (*(*(this->figura+1)+0)) = ' ';
            (*(*(this->figura+1)+1)) = '0';
            (*(*(this->figura+1)+2)) = ' ';
            (*(*(this->figura+2)+0)) = ' ';
            (*(*(this->figura+2)+1)) = '0';
            (*(*(this->figura+2)+2)) = '0';

            break;

        //figura de 5 cuadrados en forma de C azul
        case 10:

            this->color = "Azul";
            this->tamano = 5;
            this->filas = 2;
            this->columnas = 3;

            //inicializar figura

            //filas
            this->figura = new char*[this->filas];
            //columnas
            for (int i = 0; i < this->filas; i++){
                *(this->figura+i) = new char[this->columnas];
            }

            (*(*(this->figura+0)+0)) = '0';
            (*(*(this->figura+0)+1)) = ' ';
            (*(*(this->figura+0)+2)) = '0';
            (*(*(this->figura+1)+0)) = '0';
            (*(*(this->figura+1)+1)) = '0';
            (*(*(this->figura+1)+2)) = '0';

            break;

    }
}

void Pieza::mostrar(){

    char color = ' ';
    if (this->color == "Azul"){
        color = 'X';
    }else if (this->color == "Verde"){
        color = 'O';
    }else if(this->color == "Rojo"){
        color = 'H';
    }

    for (int i = 0; i<this->filas; i++){
        cout<<endl;
        for (int j = 0; j<this->columnas; j++){
            if ( (*(*(this->figura+i)+j)) == '0'){
                cout<<color<<color;
            }else{
                cout<<(*(*(this->figura+i)+j));
                cout<<(*(*(this->figura+i)+j));
            }
        }

        cout<<endl;
        for (int j = 0; j<this->columnas; j++){
            if ( (*(*(this->figura+i)+j)) == '0'){
                cout<<color<<color;
            }else{
                cout<<(*(*(this->figura+i)+j));
                cout<<(*(*(this->figura+i)+j));
            }
        }
    }
    cout<<endl<<endl;
}

void Pieza::limpiarMemoria(){
    for (int j = 0; j < this->filas; j++){
        delete[] *(this->figura+j);
    }
    delete[] this->figura;
    this->figura = NULL;
}

void Pieza::restablecer(){
    this->limpiarMemoria();
    this->rotacion = 0;
    this->inversion = 0;
    this->crear(this->tipo);
}

void Pieza::inicializarCoordenada(int fila, int columna){
    this->coordenada_c = columna;
    this->coordenada_f = fila;
}

//rotación de grados hacia la derecha
void Pieza::rotar (int rotacion){

    int n;
    int m;

    this->rotacion = rotacion;

    int ciclos = 0;

    switch (rotacion){
        case 90:
            ciclos = 1;
        break;
        case 180:
            ciclos = 2;
        break;
        case 270:
            ciclos = 3;
        break;
    }

    char** figura_rotada = NULL;

    //dependiendo de veces que se va a rotar 90 grados
    for(int c=0; c<ciclos; c++){

        n = this->filas;
        m = this->columnas;

        //declaración de filas (intercambiadas por columnas)
        figura_rotada = new char*[m];

        //declaración de columnas (intercambiadas por filas)
        for (int i = 0; i < m; i++){
            *(figura_rotada+i) = new char[n];
        }

        //asignación valores figura rotada
        int contador;
        for (int i = 0; i<m; i++){
            contador = n-1;
            for (int j = 0; j<n; j++){
                (*(*(figura_rotada+i)+j))=(*(*(this->figura+contador)+i));
                contador--;
            }
        }

        //liberar memoria dinámica para la anterior figura (sin rotar)

        for (int j = 0; j < n; j++){
            delete[] *(this->figura+j);
        }

        delete[] this->figura;

        //asignarle a la pieza la figura rotada
        this->figura = figura_rotada;

        //cambiar filas y columnas
        this->filas = m;
        this->columnas = n;

        figura_rotada = NULL;

    }

}

void Pieza::invertirHorizontalmente (){

    this->inversion = 1; // 1 para las piezas invertidas horizontalmente

    if (this->tamano != 1 && this->tamano != 2){

        int ultimaColumna;

        char temp;
        for (int i = 0; i<this->filas; i++){
            ultimaColumna = this->columnas-1;
            for (int j = 0; j<(this->columnas)/2; j++){
                temp = (*(*(this->figura+i)+j));
                (*(*(this->figura+i)+j)) = (*(*(this->figura+i)+ultimaColumna));
                (*(*(this->figura+i)+ultimaColumna)) = temp;
                ultimaColumna--;
            }
        }

    }
}

void Pieza::invertirVerticalmente (){

    this->inversion = 2; // 2 para las piezas invertidas verticalmente

    if (this->tamano != 1 && this->tamano != 2){

        int ultimaFila;

        char temp;
        for (int j = 0; j<this->columnas; j++){
            ultimaFila = this->filas-1;
            for (int i = 0; i<(this->filas)/2; i++){
                temp = (*(*(this->figura+i)+j));
                (*(*(this->figura+i)+j)) = (*(*(this->figura+ultimaFila)+j));
                (*(*(this->figura+ultimaFila)+j)) = temp;
                ultimaFila--;
            }
        }

    }
}

void Pieza::mostrarRotaciones(){
    //se muestran diferentes posiciones para la ficha seleccionada

    cout<<endl<<endl<<"Diferentes rotaciones para ubicar la ficha"<<endl<<endl;

    cout<<"Rotada 0 grados hacia la derecha (digite 1 para elegir esta rotaciones)"<<endl;
    this->mostrar();

    cout<<"Rotada 90 grados hacia la derecha (digite 2 para elegir esta rotaciones)"<<endl;
    this->rotar(90);
    this->mostrar();
    this->restablecer();

    cout<<"Rotada 180 grados hacia la derecha (digite 3 para elegir esta rotaciones)"<<endl;
    this->rotar(180);
    this->mostrar();
    this->restablecer();

    cout<<"Rotada 270 grados hacia la derecha (digite 4 para elegir esta rotaciones)"<<endl;
    this->rotar(270);
    this->mostrar();
    this->restablecer();
}
