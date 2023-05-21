#include <iostream>
#include <string>
using namespace std;

struct Atleta {
    string nombre;
    int numero;
};

class Nodo {
public:
    Atleta atleta;
    double promedio;
    Nodo* izquierda;
    Nodo* derecha;
    int altura;

    Nodo(Atleta atleta, double promedio) {
        this->atleta = atleta;
        this->promedio = promedio;
        this->izquierda = nullptr;
        this->derecha = nullptr;
        this->altura = 1;
    }
};

class ArbolAVL {
private:
    Nodo* raiz;

    int obtenerAltura(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        return nodo->altura;
    }

    int obtenerBalance(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        return obtenerAltura(nodo->izquierda) - obtenerAltura(nodo->derecha);
    }

    Nodo* rotacionDerecha(Nodo* nodo) {
        Nodo* nodoIzquierda = nodo->izquierda;
        Nodo* nodoDerecha = nodoIzquierda->derecha;

        nodoIzquierda->derecha = nodo;
        nodo->izquierda = nodoDerecha;

        nodo->altura = max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha)) + 1;
        nodoIzquierda->altura = max(obtenerAltura(nodoIzquierda->izquierda), obtenerAltura(nodoIzquierda->derecha)) + 1;

        return nodoIzquierda;
    }

    Nodo* rotacionIzquierda(Nodo* nodo) {
        Nodo* nodoDerecha = nodo->derecha;
        Nodo* nodoIzquierda = nodoDerecha->izquierda;

        nodoDerecha->izquierda = nodo;
        nodo->derecha = nodoIzquierda;

        nodo->altura = max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha)) + 1;
        nodoDerecha->altura = max(obtenerAltura(nodoDerecha->izquierda), obtenerAltura(nodoDerecha->derecha)) + 1;

        return nodoDerecha;
    }

    Nodo* insertarNodo(Nodo* nodo, Atleta atleta, double tiempo) {
        if (nodo == nullptr) {
            return new Nodo(atleta, tiempo);
        }

        if (tiempo < nodo->promedio) {
            nodo->izquierda = insertarNodo(nodo->izquierda, atleta, tiempo);
        } else if (tiempo > nodo->promedio) {
            nodo->derecha = insertarNodo(nodo->derecha, atleta, tiempo);
        } else {
            // Ignorar duplicados (en este ejemplo)
            return nodo;
        }

        nodo->altura = max(obtenerAltura(nodo->izquierda), obtenerAltura(nodo->derecha)) + 1;

        int balance = obtenerBalance(nodo);

        // Caso de rotación doble a la izquierda-derecha
        if (balance > 1 && tiempo > nodo->izquierda->promedio) {
            nodo->izquierda = rotacionIzquierda(nodo->izquierda);
            return rotacionDerecha(nodo);
        }

        // Caso de rotación doble a la derecha-izquierda
        if (balance < -1 && tiempo < nodo->derecha->promedio) {
            nodo->derecha = rotacionDerecha(nodo->derecha);
            return rotacionIzquierda(nodo);
        }

        return nodo;
    }

    // ...

    void mostrarMenorAMayor(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrarMenorAMayor(nodo->izquierda);
            cout << "Nombre: " << nodo->atleta.nombre << ", Número: " << nodo->atleta.numero << ", Promedio: "  << nodo->promedio << endl;
            mostrarMenorAMayor(nodo->derecha);
        }
    }

public:
    ArbolAVL() {
        raiz = nullptr;
    }

    void insertar(Atleta atleta, double tiempo) {
        raiz = insertarNodo(raiz, atleta, tiempo);
    }

    void mostrarDatosMenorAMayor() {
        mostrarMenorAMayor(raiz);
    }
};

int main() {
    ArbolAVL arbol;

    int opcion;
    do {
        cout << "** MENÚ **" << endl;
        cout << "1. Registrar datos de un atleta" << endl;
        cout << "2. Mostrar datos de menor a mayor promedio" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese la opción deseada: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                int numero;
                double tiempo;

                cout << "Ingrese el nombre del atleta: ";
                cin >> nombre;
                cout << "Ingrese el número del atleta: ";
                cin >> numero;
                cout << "Ingrese el tiempo del atleta: ";
                cin >> tiempo;

                Atleta atleta;
                atleta.nombre = nombre;
                atleta.numero = numero;

                arbol.insertar(atleta, tiempo);
                cout << "Datos del atleta registrados correctamente." << endl;
                break;
            }
            case 2: {
                cout << "Datos de los atletas de menor a mayor promedio: " << endl;
                arbol.mostrarDatosMenorAMayor();
                break;
            }
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, intente nuevamente." << endl;
                break;
        }

        cout << endl;

    } while (opcion != 3);

    return 0;
}
