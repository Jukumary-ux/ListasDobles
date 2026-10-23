#ifndef NODO_H
#define NODO_H

#include <string>
using namespace std;

class Nodo {
private:
    string cedula;
    string nombre;
    string apellido;
    Nodo* siguiente;

public:
    Nodo();
    Nodo(string cedula, string nombre, string apellido);
    ~Nodo();

    string getCedula();
    void setCedula(string newCedula);
    string getNombre();
    void setNombre(string newNombre);
    string getApellido();
    void setApellido(string newApellido);
    Nodo* getSiguiente();
    void setSiguiente(Nodo* newSiguiente);
};

class ListaSimple {
private:
    Nodo* cola;
    Nodo* cabeza;

public:
    ListaSimple();
    ~ListaSimple();

    Nodo* getCola();
    void setCola(Nodo* newCola);
    Nodo* getCabeza();
    void setCabeza(Nodo* newCabeza);

   
    void insertar(string cedula, string nombre, string apellido);
    void imprimir();
    Nodo* buscar(string cedula);
    bool borrar(string cedula);
};

#endif
