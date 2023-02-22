#include <iostream>
#include <queue>
using namespace std;
#define CANTIDAD_PACIENTES 100

struct Paciente {
  string nombre;
  int documento;
};


struct Paciente pt[CANTIDAD_PACIENTES];
int main() {
  
  queue<Paciente> cola_pacientes;

  
  
  int N;
  cout<< "Ingrese el numero de pacientes a registrar "<<endl;
  cin>>N;

  string nombre;
  int documento;

  for (size_t i = 0; i < N ;i++)
  {
    cout <<"Ingresa el nombre del paciente "<<endl;
    cin.ignore();
    getline(cin,nombre);
    pt[i].nombre=nombre;
    cout<<"Ingresa el documento del paciente"<<endl;
   	fflush(stdout);
    cin>>documento;
    pt[i].documento=documento;

    cola_pacientes.push(pt[i]);
  }

  
  int contador = 1;
  while (!cola_pacientes.empty()) {
    
    Paciente p = cola_pacientes.front();

    
    cout << contador << ". ";
    cout << "Nombre: " << p.nombre << ", ";
    cout << "Documento: " << p.documento << ", " << endl;

    
    cola_pacientes.pop();

    
    contador++;
  }

  return 0;
}