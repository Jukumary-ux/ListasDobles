#include <iostream>
#include "nodo.h"

Nodo::Nodo() {
    cedula = string();
    nombre = string();
    apellido = string();
    siguiente = nullptr;
    anterior = nullptr;
}

Nodo::Nodo(string cedula, string nombre, string apellido) {
    this->cedula = cedula;
    this->nombre = nombre;
    this->apellido = apellido;
    siguiente = nullptr;
    anterior = nullptr;
}

Nodo::~Nodo() {

}

string Nodo::getCedula() { 
    return cedula; 
}
void Nodo::setCedula(string newCedula) { 
    cedula = newCedula; 
}
string Nodo::getNombre() { 
    return nombre; 
}
void Nodo::setNombre(string newNombre) { 
    nombre = newNombre; 
}
string Nodo::getApellido() { 
    return apellido;
 }
void Nodo::setApellido(string newApellido) { 
    apellido = newApellido; 
}
Nodo* Nodo::getSiguiente() { 
    return siguiente; 
}
void Nodo::setSiguiente(Nodo* newSiguiente) { 
    siguiente = newSiguiente; 
}

ListaSimple::ListaSimple() {
    cabeza = nullptr;
    cola = nullptr;
}

ListaSimple::~ListaSimple() {
    while (cabeza != nullptr) {
        Nodo* aux = cabeza;
        cabeza = cabeza->getSiguiente();
        delete aux;
    }
}

Nodo* ListaSimple::getCola() { 
    return cola;
 }
void ListaSimple::setCola(Nodo* newCola) { 
    cola = newCola;
 }
Nodo* ListaSimple::getCabeza() { 
    return cabeza; 
}
void ListaSimple::setCabeza(Nodo* newCabeza) { 
    cabeza = newCabeza;
}

void ListaSimple::insertar(string cedula, string nombre, string apellido) {
    Nodo* nuevo = new Nodo(cedula, nombre, apellido);
    if (cabeza == nullptr) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cola->setSiguiente(nuevo);
        cola = nuevo;
    }
}

void ListaSimple::imprimir() {
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        cout << aux->getCedula() << " - "
             << aux->getNombre() << " "
             << aux->getApellido() << endl;
        aux = aux->getSiguiente();
    }
}

Nodo* ListaSimple::buscar(string cedula) {
    Nodo* aux = cabeza;
    while (aux != nullptr) {
        if (aux->getCedula() == cedula) return aux;
        aux = aux->getSiguiente();
    }
    return nullptr;
}

bool ListaSimple::borrar(string cedula) {
    Nodo* aux = cabeza;
    Nodo* anterior = nullptr;

    while (aux != nullptr && aux->getCedula() != cedula) {
        anterior = aux;
        aux = aux->getSiguiente();
    }
    if (aux == nullptr) return false;   // no se encontró

    if (anterior == nullptr) cabeza = aux->getSiguiente();   // era la cabeza
    else anterior->setSiguiente(aux->getSiguiente());

    if (aux == cola) cola = anterior;   // era la cola

    delete aux;
    return true;
}
