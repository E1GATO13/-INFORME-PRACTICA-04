#include <iostream>
#include <string>

using namespace std;

class Objeto {
public:
    Objeto(int id, const string atributo) : id_(id), atributo_(atributo) {}

    int getId()  { return id_; }
    string getAtributo()  { return atributo_; }

private:
    int id_;
    string atributo_;
};

class Coleccion {
public:
    Coleccion(int capacidad) : capacidad_(capacidad), tamano_(0), objetos_(new Objeto*[capacidad_]) {}

    void agregarObjeto() {
        if (tamano_ < capacidad_) {
            int id;
            string atributo;

            cout << "Ingrese el ID del objeto: ";
            cin >> id;
            cin.ignore();

            cout << "Ingrese el objeto: ";
            getline(cin, atributo);

            objetos_[tamano_] = new Objeto(id, atributo);
            ++tamano_;

            cout << "Objeto agregado correctamente." << endl;
        } else {
            cout << "No se puede agregar mas objetos. La coleccion esta llena." << endl;
        }
    }

    void eliminarObjeto() {
        int id;
        cout << "Ingrese el ID del objeto a eliminar: ";
        cin >> id;

        for (int i = 0; i < tamano_; ++i) {
            if (objetos_[i]->getId() == id) {
                delete objetos_[i];
                for (int j = i; j < tamano_ - 1; ++j) {
                    objetos_[j] = objetos_[j + 1];
                }
                --tamano_;
                cout << "Objeto eliminado correctamente." << endl;
                return;
            }
        }

        cout << "No se encontro ningun objeto con el ID especificado." << endl;
    }

    void obtenerObjeto() {
        int id;
        cout << "Ingrese el ID del objeto a obtener: ";
        cin >> id;

        for (int i = 0; i < tamano_; ++i) {
            if (objetos_[i]->getId() == id) {
                cout << "Atributo del objeto con ID " << id << ": " << objetos_[i]->getAtributo() << endl;
                return;
            }
        }

        cout << "No se encontro ningun objeto con el ID especificado." << endl;
    }

    void imprimirColeccion() const {
        cout << "Objetos en la coleccion:" << endl;
        for (int i = 0; i < tamano_; ++i) {
            cout << "ID: " << objetos_[i]->getId() << ", Atributo: " << objetos_[i]->getAtributo() << endl;
        }
    }

    ~Coleccion() {
        for (int i = 0; i < tamano_; ++i) {
            delete objetos_[i];
        }
        delete[] objetos_;
    }

private:
    int capacidad_;
    int tamano_;
    Objeto** objetos_;
};

int main() {
    int capacidad;
    cout << "Ingrese la capacidad inicial de la coleccion: ";
    cin >> capacidad;
    cin.ignore();

    Coleccion coleccion(capacidad);

    char opcion;
    do {
        cout << "\n--- Menú ---" << endl;
        cout << "1. Agregar objeto" << endl;
        cout << "2. Eliminar objeto" << endl;
        cout << "3. Obtener objeto por ID" << endl;
        cout << "4. Imprimir colección" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case '1':
                coleccion.agregarObjeto();
                break;
            case '2':
                coleccion.eliminarObjeto();
                break;
            case '3':
                coleccion.obtenerObjeto();
                break;
            case '4':
                coleccion.imprimirColeccion();
                break;
            case '5':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no valida. Por favor, seleccione una opcion valida." << endl;
                break;
        }
    } while (opcion != '5');

    return 0;
}



