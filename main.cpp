#include <iostream>
#include "nodo.h"

int main() {
    ListaSimple lista;
    int opcion;
    string cedula, nombre, apellido;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Imprimir" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. Borrar" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();   

        switch (opcion) {
            case 1:
                cout << "Cedula: ";
                getline(cin, cedula);
                cout << "Nombre: ";
                getline(cin, nombre);
                cout << "Apellido: ";
                getline(cin, apellido);
                lista.insertar(cedula, nombre, apellido);
                cout << "Insertado." << endl;
                break;

            case 2:
                if (lista.getCabeza() == nullptr)
                    cout << "La lista esta vacia." << endl;
                else
                    lista.imprimir();
                break;

            case 3: {
                cout << "Cedula a buscar: ";
                getline(cin, cedula);
                Nodo* encontrado = lista.buscar(cedula);
                if (encontrado != nullptr)
                    cout << "Encontrado: " << encontrado->getNombre()
                         << " " << encontrado->getApellido() << endl;
                else
                    cout << "No existe esa cedula." << endl;
                break;
            }

            case 4:
                cout << "Cedula a borrar: ";
                getline(cin, cedula);
                if (lista.borrar(cedula))
                    cout << "Borrado." << endl;
                else
                    cout << "No existe esa cedula." << endl;
                break;

            case 0:
                cout << "Salir" << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
