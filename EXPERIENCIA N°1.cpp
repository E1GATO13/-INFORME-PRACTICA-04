#include <iostream>
#include <string>

using namespace std;

const int MAX_HIJOS = 5; // Tamaño máximo del arreglo de objetos "Hijo"

class Hijo {
private:
    string nombre;

public:
    Hijo() : nombre("") {}

    string getNombre() const {
        return nombre;
    }

    void setNombre(const string& nombre) {
        this->nombre = nombre;
    }
};

class Padre {
private:
    string nombre;
    Hijo hijos[MAX_HIJOS];
    int numHijos;

public:
    Padre(const string& nombre) : nombre(nombre), numHijos(0) {}

    string getNombre() const {
        return nombre;
    }

    void setNombre(const string& nombre) {
        this->nombre = nombre;
    }

    void agregarHijo() {
        if (numHijos < MAX_HIJOS) {
            string nombreHijo;
            cout << "Ingrese el nombre del hijo: ";
            getline(cin, nombreHijo);
            hijos[numHijos].setNombre(nombreHijo);
            numHijos++;
        } else {
            cout << "No se pueden agregar más hijos al padre " << nombre << endl;
        }
    }

    void imprimirInfo() const {
        cout << "Padre: " << nombre << ", Número de hijos: " << numHijos << endl;
        for (int i = 0; i < numHijos; i++) {
            cout << "Hijo " << i + 1 << ": " << hijos[i].getNombre() << endl;
        }
    }
};

int main() {
    Padre padre("Juan");

    for (int i = 0; i < MAX_HIJOS; i++) {
        padre.agregarHijo();
    }

    padre.imprimirInfo();

    return 0;
}

/*Uso 

INGRESE EL NOMBRE DEL HIJO: PEPE 
INGRESE EL NOMBRE DEL HIJO: SANTIAGO 
INGRESE EL NOMBRE DEL HIJO: JAVIER 
INGRESE EL NOMBRE DEL HIJO: KEVIN 
INGRESE EL NOMBRE DEL HIJO: JEAN PIERO 
PADRE: JUAN, NÚMERO DE HIJOS: 5 
HIJO 1: PEPE 
HIJO 2: SANTIAGO 
HIJO 3: JAVIER 
HIJO 4: KEVIN 
HIJO 5: JEAN PIERO */