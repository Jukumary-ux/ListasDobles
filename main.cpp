#include <iostream>
#include <string>
#include <limits>
using namespace std;
#include "nodo.h"

bool validarLetras(string texto) {
    if (texto.empty()) {
        return false;
    }

    for (char letra : texto) {
        if (!((letra >= 'A' && letra <= 'Z') ||
              (letra >= 'a' && letra <= 'z'))) {
            return false;
        }
    }

    return true;
}
int main() {
    ListaDoble lista;
    int opcion;
    string cedula, nombre, apellido;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Imprimir" << endl;
        cout << "3. Buscar" << endl;
        cout << "4. Borrar" << endl;
        cout << "5. Imprimir Reversa" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Error, ingresar solo numeros" << endl;
            opcion = -1;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (opcion) {
        case 1:
            cout << "Cedula: ";
            getline(cin, cedula);

            do {
                cout << "Nombre: ";
                getline(cin, nombre);

                if (!validarLetras(nombre)) {
                    cout << "Error, ingrese solo letras" << endl;
                }

            } while (!validarLetras(nombre));

            do {
                cout << "Apellido: ";
                getline(cin, apellido);

                if (!validarLetras(apellido)) {
                    cout << "Error, ingrese solo letras" << endl;
                }

            } while (!validarLetras(apellido));

            lista.insertar(cedula, nombre, apellido);
            cout << "Registrado correctamente." << endl;
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
            case 5:
                if (lista.getCabeza() == nullptr) {
                    cout << "La lista esta vacia." << endl;
                } else {
                    cout << "\nLista en reversa:" << endl;
                    lista.imprimirReversa();
                }
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
