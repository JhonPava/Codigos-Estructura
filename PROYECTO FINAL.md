#include <iostream>
#include <string>
#include <malloc.h>
using namespace std;

struct NodoArbol {
    string nombre;
    int numero;
    int vueltas;
    float tiempo;
    float promedio;
    NodoArbol *izquierdo;
    NodoArbol *derecho;
};

void insertar(NodoArbol *&arbol, NodoArbol *nuevo_nodo) {
    if (arbol == NULL) {
        arbol = nuevo_nodo;
    } else if (nuevo_nodo->promedio < arbol->promedio) {
        insertar(arbol->izquierdo, nuevo_nodo);
    } else {
        insertar(arbol->derecho, nuevo_nodo);
    }
}

void agregarAtleta(NodoArbol *&arbol) {


     NodoArbol *nuevo_atleta = new NodoArbol();

    cout << "Ingrese el nombre del atleta: "<<endl;
    cin>> nuevo_atleta->nombre;
    getline(cin, nuevo_atleta->nombre);

    cout << "Ingrese el numero del atleta: "<<endl;
    cin >> nuevo_atleta->numero;

    int total_vueltas = 0;
    float total_tiempo = 0.0;
    int num_vueltas; 
    float tiempo;

    do {
        cout << "Ingrese el numero de vueltas del atleta (0 para terminar): "<<endl;
        cin >> num_vueltas;

        if (num_vueltas <3) {
            total_vueltas += num_vueltas;

            cout << "Ingrese el tiempo del atleta :"<<endl;
            cout<<"minutos:"<<endl;
            cin>>tiempo;
            cout<<"segundos: "<<endl;
           
            cin >> tiempo;
            total_tiempo += tiempo;
        }
    } while (num_vueltas <3);
   if (num_vueltas==0);

    if (total_vueltas >= 2) {
        nuevo_atleta->vueltas = total_vueltas;
        nuevo_atleta->tiempo = total_tiempo;
        nuevo_atleta->promedio = total_tiempo / total_vueltas;
        insertar(arbol, nuevo_atleta);
    } else {
        cout << "El atleta debe dar al menos dos vueltas para ser registrado.\n";
    }
    return;
}

void mostrarArbol(NodoArbol *arbol) {
    if (arbol == NULL) {
        return;
    }

    mostrarArbol(arbol->izquierdo);
    cout << arbol->nombre << ", Numero: " << arbol->numero << ", Promedio: " << arbol->promedio << endl;
    mostrarArbol(arbol->derecho);
}

int main() {
    NodoArbol *arbol = NULL;

    int opcion = 0;

    do {
        cout << "\nMenu de opciones:\n";
        cout << "1. Agregar atleta.\n";
        cout << "2. Mostrar atletas registrados.\n";
        cout << "3. Salir.\n";

        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarAtleta(arbol);
                break;

            case 2:
                cout << "\nAtletas registrados:\n";
                mostrarArbol(arbol);
                break;

            case 3:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
                break;
        }
    } while (opcion != 3);


return 0;



}
