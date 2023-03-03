#include <iostream>
using namespace std;

struct Paciente {
    string nombre;
    int documento;
};

struct Nodo {
    Paciente paciente;
    Nodo* siguiente;
};

class PacientesCola {
private:
    Nodo* cabeza;
    Nodo* cola;
public:
    PacientesCola() {
        cabeza = NULL;
        cola = NULL;
    }

    void agregarPaciente() {
        Paciente p;
        cout << "\nNombre del paciente -> ";
        cin >> p.nombre;
        cout << "\nNumero de documento ->  ";
        cin >> p.documento;

        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->paciente = p;
        nuevoNodo->siguiente = NULL;

        if (cabeza == NULL) {
            cabeza = nuevoNodo;
        } else {
            cola->siguiente = nuevoNodo;
        }
        cola = nuevoNodo;

        cout << "\nEl paciente ha sido registrado exitosamente." << endl;
    }
    
    
    
    /Para mostrar los pacientes, recorremos la cola desde la cabeza y mostramos los datos de cada paciente./
    void mostrarPacientes() {
        if (cabeza == NULL) {
            cout << "\nNo hay pacientes registrados." << endl;
        } else {
            int contador = 1;
            cout << "\nPacientes registrados:" << endl;
            Nodo* actual = cabeza;
            while (actual != NULL) {
                Paciente p = actual->paciente;
                cout << contador << ". " << p.nombre << " - " << p.documento << endl;
                actual = actual->siguiente;
                contador++;
            }
        }
    }
    
    /En el destructor, liberamos la memoria de todos los nodos antes de que la instancia de la clase sea destruida/
    ~PacientesCola() {
        Nodo* actual = cabeza;
        while (actual != NULL) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
};

int main() {
    PacientesCola cola;

    int opcion;
    do {
        cout << "\nAdd and List (colas) pacientes" << endl;
        cout << "1) Registrar Paciente A La Cola" << endl;
        cout << "2) Mostrar Pacientes De La Cola" << endl;
        cout << "Su opcion :  ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cola.agregarPaciente();
                break;
            }
            case 2: {
                cola.mostrarPacientes();
                break;
            }
            case 0: {
                break;
            }
            default: {
                cout << "\n Opcion Incorrecta " << endl;
                break;
            }
        }
    } while (opcion != 0);

    return 0;
}