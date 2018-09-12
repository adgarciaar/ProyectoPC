#include "Pieza.h"
#include "Tablero.h"
#include "ColaT.h"
#include "ListaT.h"

#include <iostream>
#include <fstream>

#include <cstdlib>
#include <ctime>

using namespace std;

Tablero* tablero;
Lista<Pieza> listaPiezas; // guardar piezas restantes para el juego
Cola<Pieza> piezasAgregadas; // guardar en orden las piezas usadas

void inicializarEstructuras();
void inicializarListaPiezas(short modo);
void imprimirPiezas();
void insertarFicha(short modo);
short seleccionOpciones();
void ejecutarModo(short dificultad, short modo);
void nuevoJuego();
void cargarJuego();
void menuPrincipal();
Pieza seleccionarPieza();
bool validarEntradaPieza(Pieza& pieza);
Pieza elegirPieza();
void elegirPosicion(Pieza& pieza);
void aplicarRotacion(int rotacion, Pieza& pieza);
void liberarMemoria();
void guardarJuego(short dificultad, short modo);
Pieza cargarPieza(int tipo, int rotacion, int inversion, int fila, int columna);
bool verificarPiezasContiguas();
bool revisarLimite(Pieza& pieza, char buscado, Tablero* matrizFichas);

int main(){

    menuPrincipal();

    return 0;
}

void inicializarEstructuras(){
    tablero = new Tablero();
    tablero->inicializar();
    listaPiezas.inicializar(); // inicialización lista de piezas
    piezasAgregadas.inicializar(); // inicialización cola de piezas
}

void inicializarListaPiezas(short modo){

    Pieza pieza;

    if(modo == 1){ // modo secuencial

        srand((int)time(0));

        bool b;
        int r;

        for (int i=0; i<10; i++){

            r = (rand() % 10) + 1;

            if(i != 1){

                b = listaPiezas.buscarElemento(r);

                while(b == true){
                    r = (rand() % 10) + 1;
                    b = listaPiezas.buscarElemento(r);
                }
            }

            pieza.crear(r);
            listaPiezas.insertarNodo(pieza);
        }

    }else{ // modo aleatorio
        //inicializar la lista de piezas para modo aleatorio
        for (int i=1; i<11;i++){
            pieza.crear(i);
            listaPiezas.insertarNodo(pieza);
        }
    }
}

void liberarMemoria(){
    //liberar memoria
    tablero->liberarMemoria();
    listaPiezas.limpiar();
    piezasAgregadas.limpiar();
}

void imprimirPiezas(){ //imprimir piezas que se encuentren en listaPiezas
    Nodo<Pieza>* nodo = listaPiezas.cabezaL();
    for(int i=0; i<listaPiezas.longitud(); i++){
        cout<<"Ficha "<<nodo->data.tipo<<endl;
        nodo->data.restablecer();
        nodo->data.mostrar();
        nodo = nodo->siguiente;
    }
}

Pieza elegirPieza(){

    cout<<endl<<endl<<"Por favor seleccione una de las siguientes piezas"<<endl<<endl;

    imprimirPiezas();

    //usuario elige la ficha
    int ficha;
    cout<<endl<<"Escriba el numero de ficha para agregar en tablero: "<<endl;
    cin>>ficha;

    while (listaPiezas.buscarElemento(ficha) == false){
        cout<<endl<<endl<<"Numero de ficha no valido"<<endl;
        cout<<endl<<"Escriba el numero de ficha para agregar en tablero: "<<endl;
        cin>>ficha;
    }

    Pieza pieza = listaPiezas.obtenerPieza(ficha);
    return pieza;
}

void aplicarRotacion(int rotacion, Pieza& pieza){
    //de acuerdo a la posicion seleccionada se pone a la figura de la pieza en dicha posicion
    switch(rotacion){
        case 1:
            break;
        case 2:
            pieza.rotar(90);
            break;
        case 3:
            pieza.rotar(180);
            break;
        case 4:
            pieza.rotar(270);
            break;
    }
}

void elegirPosicion(Pieza& pieza){

    pieza.mostrarRotaciones();

    //usuario elige la rotación para la pieza
    int rotacion;
    cout<<endl<<"Digite el numero respectivo para la rotacion de la pieza: "<<endl;
    cin>>rotacion;

    while (rotacion<1 || rotacion>4){
        cout<<endl<<endl<<"Numero de rotacion no valido"<<endl;
        cout<<endl<<"Digite el numero respectivo para la rotacion de la pieza: "<<endl;
        cin>>rotacion;
    }

    aplicarRotacion(rotacion, pieza);

    //se muestran diferentes posiciones para la ficha seleccionada

    cout<<endl<<endl<<"Posibles inversiones para ubicar la ficha"<<endl<<endl;

    cout<<"Sin inversion (digite 1 para elegir esta inversion)"<<endl;
    pieza.mostrar();

    cout<<"Invertida horizontalmente (digite 2 para elegir esta inversion)"<<endl;
    pieza.invertirHorizontalmente();
    pieza.mostrar();
    pieza.restablecer();

    aplicarRotacion(rotacion, pieza);

    cout<<"Invertida verticalmente (digite 3 para elegir esta inversion)"<<endl;
    pieza.invertirVerticalmente();
    pieza.mostrar();
    pieza.restablecer();

    aplicarRotacion(rotacion, pieza);

    //usuario elige la inversión para la pieza
    int inversion;
    cout<<endl<<"Digite el numero respectivo para la inversion de la pieza: "<<endl;
    cin>>inversion;

    while (inversion<1 || inversion>3){
        cout<<endl<<endl<<"Numero de inversion no valido"<<endl;
        cout<<endl<<"Digite el numero respectivo para la inversion de la pieza: "<<endl;
        cin>>inversion;
    }

    switch(inversion){
        case 1:
            break;
        case 2:
            pieza.invertirHorizontalmente();
            break;
        case 3:
            pieza.invertirVerticalmente();
            break;
    }

}

Pieza seleccionarPieza(){

    Pieza pieza = elegirPieza();

    elegirPosicion(pieza);

    return pieza;
}

bool validarEntradaPieza(Pieza& pieza){ //devuelve true si la pieza puede ubicarse en alguna coordenada del tablero
    bool b = false;
    for (int i = 1; i < 8-pieza.filas; i++){
        for (int j = 1; j < 8-pieza.columnas; j++){
            if(tablero->validarCoordenada(pieza, i, j) == true){
                b = true;
            }
        }
    }
    return b;
}

void insertarFicha(short modo){

    Pieza pieza;

    if(modo == 1){
        pieza = listaPiezas.cabezaL()->data;
        cout<<endl<<endl<<endl<<"Ficha "<<pieza.tipo<<endl;
        elegirPosicion(pieza);
    }else{
        pieza = seleccionarPieza();
    }

    bool b = validarEntradaPieza(pieza);

    if (b == true){ //si la pieza puede ubicarse en el tablero
        //se piden coordenadas donde se va a ubicar esquina superior de la figura
        int fila, columna;
        cout<<endl<<endl;
        cout<<"Digite coordenada para ubicar la esquina superior de la ficha en el tablero, con el formato: fila-columna"<<endl;
        cout<<"Recuerde que los valores tanto para filas como para columnas deben estar entre 1 y 6"<<endl;

        char coordenada[3];
        cin>>coordenada;

        //la coordenada correspondiente al número de fila
        fila = coordenada[0] - '0';
        //la coordenada correspondiente al número de columna
        columna = coordenada[2] - '0';

        //mientras esa coordenada se salgan de los limites se vuelven a solicitar

        while( columna<1 || columna>6 || fila<1 || fila>6 ){
            cout<<endl<<endl<<"Coordenadas no validas"<<endl<<endl;
            cout<<"Digite coordenada para ubicar la esquina superior de la ficha en el tablero, con el formato: fila-columna"<<endl;
            cout<<"Recuerde que los valores tanto para filas como para columnas deben estar entre 1 y 6"<<endl;

            cin>>coordenada;

            //la coordenada correspondiente al número de fila
            fila = coordenada[0] - '0';
            //la coordenada correspondiente al número de columna
            columna = coordenada[2] - '0';
        }

        //ahora se valida si toda la pieza puede ubicarse dentro del tablero
        bool b = tablero->validarCoordenada(pieza, fila, columna);

        //mientras no se puede insertar la ficha en la coordenada se vuelve a pedir otra

        while (b == false){
            cout<<endl<<endl<<"No se pudo insertar la ficha"<<endl<<endl;
            cout<<"Digite coordenada para ubicar la esquina superior de la ficha en el tablero, con el formato: fila-columna"<<endl;
            cout<<"Recuerde que los valores tanto para filas como para columnas deben estar entre 1 y 6"<<endl;

            cin>>coordenada;

            //la coordenada correspondiente al número de fila
            fila = coordenada[0] - '0';
            //la coordenada correspondiente al número de columna
            columna = coordenada[2] - '0';

            b = tablero->validarCoordenada(pieza, fila, columna);
        }

        //se inserta la ficha
        cout<<endl<<endl<<"Esquina superior izquierda de la pieza se situara en coordenada "<<fila<<"-"<<columna<<endl<<endl;
        //agregar pieza al tablero
        tablero->agregarPieza(pieza, fila, columna);
        piezasAgregadas.insertar(pieza);
        //imprimir el tablero con esa pieza
        tablero->imprimir();
        cout<<endl<<endl;

        listaPiezas.eliminarNodo(pieza.tipo); // eliminar la pieza de la lista

        pieza.limpiarMemoria(); // liberar memoria de pieza

    }else{ //si la pieza no puede ubicarse en el tablero
        cout<<endl<<endl<<"La pieza con esta posicion no puede ubicarse en ningun espacio del tablero"<<endl<<endl;
    }

}

short seleccionOpciones(){

    short opcion;

    cout<<endl<<endl<<"Por favor seleccione una opcion"<<endl<<endl;
    cout<<"1. Ubicar una pieza"<<endl;
    cout<<"2. Guardar el juego"<<endl;
    cout<<"3. Terminar el juego"<<endl;
    cout<<endl<<"Ingrese la opcion: ";
    cin>>opcion;

    while(opcion < 1 || opcion > 3){
        cout<<endl<<endl<<"Ha digitado una opcion incorrecta"<<endl<<endl;
        cout<<"Por favor seleccione una opcion"<<endl<<endl;
        cout<<"1. Ubicar una pieza"<<endl;
        cout<<"2. Guardar el juego"<<endl;
        cout<<"3. Terminar el juego"<<endl;
        cout<<endl<<"Ingrese la opcion: ";
        cin>>opcion;
    }

    return opcion;
}

void ejecutarModo(short dificultad, short modo){
    short opcion = seleccionOpciones();
    if(opcion == 1){
        tablero->imprimir();
        while(opcion == 1 && tablero->estaLleno() == false){
            insertarFicha(modo);
            if(tablero->estaLleno() == false){ // no se han cumplido requisitos para ganar
                opcion = seleccionOpciones();
            }else{
                if(dificultad == 1){
                    cout<<endl<<endl<<"Has ganado. Felicitaciones"<<endl<<endl;
                    opcion = 3;
                }else{
                    if(verificarPiezasContiguas() == false){
                        cout<<endl<<endl<<"El tablero se ha llenado pero las piezas de cada color no han quedado contiguas. Has perdido"<<endl<<endl;
                        opcion = 3;
                    }else{
                        cout<<endl<<endl<<"Has ganado. Felicitaciones"<<endl<<endl;
                        opcion = 3;
                    }
                }
            }
        }
    }
    if(opcion == 2){
        guardarJuego(dificultad, modo);
        ejecutarModo(dificultad, modo);
    }else if(opcion == 3){
        liberarMemoria();
        cout<<endl<<endl<<"Juego terminado"<<endl<<endl<<endl<<endl;
        menuPrincipal();
    }
}

void nuevoJuego(){

    short dificultad, modo;
    cout<<endl<<endl<<"Por favor seleccione la dificultad del juego"<<endl<<endl;
    cout<<"1. Version facil"<<endl;
    cout<<"2. Version avanzada"<<endl;
    cout<<endl<<"Ingrese la dificultad del juego: ";
    cin>>dificultad;

    while(dificultad != 1 && dificultad != 2){
        cout<<endl<<endl<<"Ha digitado una opcion incorrecta"<<endl<<endl;
        cout<<"Por favor seleccione una opcion"<<endl<<endl;
        cout<<endl<<endl<<"Por favor seleccione la dificultad del juego"<<endl<<endl;
        cout<<"1. Version facil"<<endl;
        cout<<"2. Version avanzada"<<endl;
        cout<<endl<<"Ingrese la dificultad del juego: ";
        cin>>dificultad;
    }

    cout<<endl<<endl<<"Por favor seleccione el modo de juego"<<endl<<endl;
    cout<<"1. Modo secuencial"<<endl;
    cout<<"2. Modo aleatorio"<<endl;
    cout<<endl<<"Ingrese el modo de juego: ";
    cin>>modo;

    while(modo != 1 && modo != 2){
        cout<<endl<<endl<<"Ha digitado una opcion incorrecta"<<endl<<endl;
        cout<<"Por favor seleccione el modo de juego"<<endl<<endl;
        cout<<"1. Modo secuencial"<<endl;
        cout<<"2. Modo aleatorio"<<endl;
        cout<<endl<<"Ingrese el modo de juego: ";
        cin>>modo;
    }

    inicializarEstructuras();
    inicializarListaPiezas(modo);

    ejecutarModo(dificultad, modo);
}

Pieza cargarPieza(int tipo, int rotacion, int inversion, int fila, int columna){
    Pieza pieza;
    pieza.crear(tipo);
    if (rotacion != 0){
        pieza.rotar(rotacion);
    }
    if (inversion != 0){
        if(inversion == 1){
            pieza.invertirHorizontalmente();
        }else{
            pieza.invertirVerticalmente();
        }
    }
    pieza.inicializarCoordenada(fila, columna);
    return pieza;
}

void cargarJuego(){

    string nombreArchivo;
    cout<<endl<<endl<<"Digite el nombre del archivo donde esta guardado el juego"<<endl<<endl;
    cin.ignore();
    getline (cin, nombreArchivo);

    nombreArchivo = nombreArchivo + ".txt";
    ifstream archivo (nombreArchivo.c_str());

    if (archivo.is_open()){

        inicializarEstructuras();
        short dificultad, modo, numJugadas;

        archivo>>dificultad>>modo>>numJugadas;

        // guardar en la cola las piezas que están en el tablero, en el orden jugado
        Pieza pieza;
        Cola<Pieza> piezasJugadas;
        piezasJugadas.inicializar();

        int tipo, rotacion, inversion, fila, columna;

        for (int i=0; i<numJugadas; i++){
            archivo>>tipo>>rotacion>>inversion>>fila>>columna;
            pieza = cargarPieza(tipo, rotacion, inversion, fila, columna);
            piezasAgregadas.insertar(pieza);
            piezasJugadas.insertar(pieza);
        }

        // guardar en la lista de piezas las restantes para jugar, en el orden establecido

        for (int i=0; i<10-numJugadas; i++){
            archivo>>tipo;
            pieza.crear(tipo);
            listaPiezas.insertarNodo(pieza);
        }

        archivo.close();

        cout<<endl<<endl<<"A continuacion se muestran las jugadas realizadas en el juego guardado";
        tablero->imprimir();

        short contador = 1;
        while(piezasJugadas.esVacia() != true){
            pieza = piezasJugadas.atenderCabeza()->data;
            cout<<endl<<endl<<"Jugada "<<contador<<endl;
            cout<<"Se agrego ficha "<<pieza.tipo<<", rotada "<<pieza.rotacion<<" grados a la derecha";
            switch(pieza.inversion){
                case 0:
                    cout<<" y sin invertir";
                    break;
                case 1:
                    cout<<" e invertida horizontalmente";
                    break;
                case 2:
                    cout<<" e invertida verticalmente";
                    break;
            }
            cout<<endl<<"Con la esquina superior izquierda ubicada en la fila "<<pieza.coordenada_f<<" y en la columna "<<pieza.coordenada_c;
            tablero->agregarPieza(pieza, pieza.coordenada_f, pieza.coordenada_c);
            tablero->imprimir();
            contador++;
        }

        //si las condiciones para la victoria ya se cumplieron

        if(tablero->estaLleno() == false){ // no se han cumplido condiciones para la victoria
            ejecutarModo(dificultad, modo);
        }else{
             if(dificultad == 1){
                cout<<endl<<endl<<"Has ganado. Felicitaciones"<<endl<<endl;
                menuPrincipal();
            }else{
                if(verificarPiezasContiguas() == false){
                    cout<<endl<<endl<<"El tablero se ha llenado pero las piezas de cada color no han quedado contiguas. Has perdido"<<endl<<endl;
                    menuPrincipal();
                }else{
                    cout<<endl<<endl<<"Has ganado. Felicitaciones"<<endl<<endl;
                    menuPrincipal();
                }
            }
        }

    }else{
        cout<<endl<<endl<<"No se pudo cargar el juego en el archivo"<<endl<<endl;
    }
}

void guardarJuego(short dificultad, short modo){

    string nombreArchivo;
    cout<<endl<<endl<<"Digite un nombre de archivo para guardar el juego"<<endl<<endl;
    cin.ignore();
    getline (cin, nombreArchivo);
    nombreArchivo = nombreArchivo + ".txt";

    ofstream archivo(nombreArchivo.c_str());

    if (archivo.is_open()){

        short numJugadas = 10-listaPiezas.longitud();

        archivo<<dificultad<<" "<<modo<<" "<<numJugadas<<endl;

        //escribir las piezas que ya se agregaron, en orden de pieza jugada
        Pieza p;
        while(piezasAgregadas.esVacia() != true){
            p = piezasAgregadas.atenderCabeza()->data;
            archivo<<p.tipo<<" "<<p.rotacion<<" "<<p.inversion<<" "<<p.coordenada_f<<" "<<p.coordenada_c<<endl;
        }

        //escribir las piezas restantes, en el orden que viene la lista
        Nodo<Pieza>* nodo = listaPiezas.cabezaL();
        for(int i=0; i<listaPiezas.longitud(); i++){
            p = nodo->data;
            archivo<<p.tipo<<" ";
            nodo = nodo->siguiente;
        }
        archivo<<endl;

        archivo.close();

        cout<<endl<<endl<<"Se guardo el juego en el archivo"<<endl<<endl;

    }else{
        cout<<endl<<endl<<"No se pudo guardar el juego en el archivo"<<endl<<endl;
    }

}

void menuPrincipal(){

    short opcion;
    cout<<"Por favor seleccione una opcion"<<endl<<endl;
    cout<<"1. Nuevo juego"<<endl;
    cout<<"2. Cargar juego guardado"<<endl;
    cout<<"3. Salir del programa"<<endl;
    cout<<endl<<"Ingrese la opcion: ";
    cin>>opcion;

    while(opcion < 1 || opcion > 3){
        cout<<endl<<endl<<"Ha digitado una opcion incorrecta"<<endl<<endl;
        cout<<"Por favor seleccione una opcion"<<endl<<endl;
        cout<<"1. Nuevo juego"<<endl;
        cout<<"2. Cargar juego guardado"<<endl;
        cout<<"3. Salir del programa"<<endl;
        cout<<endl<<"Ingrese la opcion: ";
        cin>>opcion;
    }

    switch(opcion){
        case 1:
            nuevoJuego();
            break;
        case 2:
            cargarJuego();
            break;
        case 3:
            cout<<endl<<endl<<"Hasta pronto"<<endl<<endl;
            break;
    }
}

bool verificarPiezasContiguas(){ // retorna true si las piezas de cada color están contiguas

        bool azulesContiguas = false, verdesContiguas = false, rojasContiguas = false;

        // inicializar un tablero que contendrá el tipo de la pieza en los lugares donde esté cada ficha

        Tablero* matrizFichas = new Tablero();
        matrizFichas->inicializar();

        // usar lista temporal para conocer las piezas ya jugadas

        Lista<Pieza> listaTemporal;
        listaTemporal.inicializar();

        // crear la matriz con los tipos de ficha
        Pieza pieza, p;
        int fila, columna;

        for(int i=0; i<10; i++){
            p = piezasAgregadas.atenderCabeza()->data;
            pieza = cargarPieza(p.tipo, p.rotacion, p.inversion, p.coordenada_f, p.coordenada_c);
            listaTemporal.insertarNodo(pieza);
            fila = pieza.coordenada_f;
            columna = pieza.coordenada_c;
            for (int i = 0; i<pieza.filas; i++){
                for (int j = 0; j<pieza.columnas; j++){
                    if ( (*(*(pieza.figura+i)+j)) == '0' ){
                        if (pieza.tipo == 10){
                            (*(*(matrizFichas->matriz+fila)+columna)) = ' ';
                        }else{
                            (*(*(matrizFichas->matriz+fila)+columna)) = '0' + pieza.tipo;
                        }
                    }
                    columna++;
                }
                fila++;
                columna = columna - pieza.columnas;
            }
        }

        // validar si azules están contiguas (fichas 3, 7 y 10)

        bool limite10con3 = false, limite10con7 = false;

        pieza = listaTemporal.obtenerPieza(10);
        limite10con3 = revisarLimite(pieza, '3', matrizFichas);
        limite10con7 = revisarLimite(pieza, '7', matrizFichas);

        if(limite10con3 == true && limite10con7 == true){ // 10 limita con 3 y 7
            azulesContiguas = true;
        }else if(limite10con3 == false && limite10con7 == false){ // ni 3 ni 7 limitan con 10
            azulesContiguas = false;
        }else{ // 10 limita con 7 o con 3
            pieza = listaTemporal.obtenerPieza(7);
            bool limite7con3 = revisarLimite(pieza, '3', matrizFichas);
            if (limite7con3 == true){
                azulesContiguas = true;
            }else{
                azulesContiguas = false;
            }
        }

        // validar si verdes están contiguas (fichas 4, 6 y 9)

        bool limite9con4 = false, limite9con6 = false;

        pieza = listaTemporal.obtenerPieza(9);
        limite9con4 = revisarLimite(pieza, '4', matrizFichas);
        limite9con6 = revisarLimite(pieza, '6', matrizFichas);

        if(limite9con4 == true && limite9con6 == true){ // 9 limita con 4 y 6
            verdesContiguas = true;
        }else if(limite9con4 == false && limite9con6 == false){ // ni 4 ni 6 limitan con 9
            verdesContiguas = false;
        }else{ // 9 limita con 4 o con 6
            pieza = listaTemporal.obtenerPieza(6);
            bool limite6con4 = revisarLimite(pieza, '4', matrizFichas);
            if (limite6con4 == true){
                verdesContiguas = true;
            }else{
                verdesContiguas = false;
            }
        }

        // validar si rojas están contiguas (fichas 1, 2, 5 y 8)

        bool limite1con2 = false, limite1con5 = false, limite1con8 = false;

        pieza = listaTemporal.obtenerPieza(1);

        limite1con2 = revisarLimite(pieza, '2', matrizFichas);
        limite1con5 = revisarLimite(pieza, '5', matrizFichas);
        limite1con8 = revisarLimite(pieza, '8', matrizFichas);

        if(limite1con2 == false && limite1con5 == false && limite1con8 == false){ //1 limita con 2, 5 y 8
            rojasContiguas = false;
        }else if (limite1con2 == true && limite1con5 == true && limite1con8 == true){ //1 no limita con 2, 5 y 8
            rojasContiguas = true;
        }else if(limite1con2 == true && limite1con5 == true){ //1 no limita con 8
            pieza = listaTemporal.obtenerPieza(2);
            bool limite2con8 = revisarLimite(pieza, '8', matrizFichas);
            pieza = listaTemporal.obtenerPieza(5);
            bool limite5con8 = revisarLimite(pieza, '8', matrizFichas);
            if(limite2con8 == true || limite5con8 == true){
                rojasContiguas = true;
            }else{
                rojasContiguas = false;
            }
        }else if(limite1con2 == true && limite1con8 == true){ //1 no limita con 5
            pieza = listaTemporal.obtenerPieza(2);
            bool limite2con5 = revisarLimite(pieza, '5', matrizFichas);
            pieza = listaTemporal.obtenerPieza(8);
            bool limite8con5 = revisarLimite(pieza, '5', matrizFichas);
            if(limite2con5 == true || limite8con5 == true){
                rojasContiguas = true;
            }else{
                rojasContiguas = false;
            }
        }else if(limite1con5 == true && limite1con8 == true){ //1 no limita con 2
            pieza = listaTemporal.obtenerPieza(5);
            bool limite5con2 = revisarLimite(pieza, '2', matrizFichas);
            pieza = listaTemporal.obtenerPieza(8);
            bool limite8con2 = revisarLimite(pieza, '2', matrizFichas);
            if(limite5con2 == true || limite8con2 == true){
                rojasContiguas = true;
            }else{
                rojasContiguas = false;
            }
        }else if(limite1con2 == true){  //1 limita solo con 2
            bool limite2con5 = false, limite2con8 = false;
            pieza = listaTemporal.obtenerPieza(2);
            limite2con5 = revisarLimite(pieza, '5', matrizFichas);
            limite2con8 = revisarLimite(pieza, '8', matrizFichas);
            if(limite2con5 == true && limite2con8 == true){ //2 limita con 5 y con 8
                rojasContiguas = true;
            }else if(limite2con5 == false && limite2con8 == false){ //2 no limita ni con 5 ni con 8
                rojasContiguas = false;
            }else{ //2 limita con 5 pero no con 8 o 2 limita con 8 pero no con 5
                pieza = listaTemporal.obtenerPieza(5);
                bool limite5con8 = revisarLimite(pieza, '8', matrizFichas);
                if(limite5con8 == true){
                    rojasContiguas = true;
                }else{
                    rojasContiguas = false;
                }
            }
        }else if(limite1con5 == true){  //1 limita solo con 5
            bool limite5con2 = false, limite5con8 = false;
            pieza = listaTemporal.obtenerPieza(5);
            limite5con2 = revisarLimite(pieza, '2', matrizFichas);
            limite5con8 = revisarLimite(pieza, '8', matrizFichas);
            if(limite5con2 == true && limite5con8 == true){ //5 limita con 2 y con 8
                rojasContiguas = true;
            }else if(limite5con2 == false && limite5con8 == false){ //5 no limita ni con 2 ni con 8
                rojasContiguas = false;
            }else{ //5 limita con 2 pero no con 8 o 5 limita con 8 pero no con 2
                pieza = listaTemporal.obtenerPieza(2);
                bool limite2con8 = revisarLimite(pieza, '8', matrizFichas);
                if(limite2con8 == true){
                    rojasContiguas = true;
                }else{
                    rojasContiguas = false;
                }
            }
        }else if(limite1con8 == true){   //1 limita solo con 8
            bool limite8con2 = false, limite8con5 = false;
            pieza = listaTemporal.obtenerPieza(8);
            limite8con2 = revisarLimite(pieza, '2', matrizFichas);
            limite8con5 = revisarLimite(pieza, '5', matrizFichas);
            if(limite8con2 == true && limite8con5 == true){ //8 limita con 2 y con 5
                rojasContiguas = true;
            }else if(limite8con2 == false && limite8con5 == false){ //8 no limita ni con 2 ni con 5
                rojasContiguas = false;
            }else{ //8 limita con 2 pero no con 5 u 8 limita con 5 pero no con 2
                pieza = listaTemporal.obtenerPieza(2);
                bool limite2con5 = revisarLimite(pieza, '5', matrizFichas);
                if(limite2con5 == true){
                    rojasContiguas = true;
                }else{
                    rojasContiguas = false;
                }
            }
        }

        matrizFichas->liberarMemoria();
        delete matrizFichas;

        if(azulesContiguas == true && verdesContiguas == true && rojasContiguas == true){
            // para las piezas de diferentes colores se cumple que están contiguas
            return true;
        }else{
            return false;
        }
}

bool revisarLimite(Pieza& pieza, char buscado, Tablero* matrizFichas){ //devuelve true si limita con el buscado
    bool b = false;
    char comparado;

    switch(pieza.tipo){
        case 1:
            comparado = '1';
            break;
        case 2:
            comparado = '2';
            break;
        case 3:
            comparado = '3';
            break;
        case 4:
            comparado = '4';
            break;
        case 5:
            comparado = '5';
            break;
        case 6:
            comparado = '6';
            break;
        case 7:
            comparado = '7';
            break;
        case 8:
            comparado = '8';
            break;
        case 9:
            comparado = '9';
            break;
        case 10:
            comparado = ' ';
            break;
    }

    for (int i = pieza.coordenada_f; i<pieza.coordenada_f+pieza.filas; i++){
        for (int j = pieza.coordenada_c; j<pieza.coordenada_c+pieza.columnas; j++){
            if( (*(*(matrizFichas->matriz+i)+j)) == comparado ){
                if( (*(*(matrizFichas->matriz+i)+j+1)) == buscado ){
                    b = true;
                }
                if( (*(*(matrizFichas->matriz+i)+j-1)) == buscado ){
                    b = true;
                }
                if( (*(*(matrizFichas->matriz+i+1)+j)) == buscado ){
                    b = true;
                }
                if( (*(*(matrizFichas->matriz+i-1)+j)) == buscado ){
                    b = true;
                }
            }
        }
    }
    return b;
}
