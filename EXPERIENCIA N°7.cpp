#include <iostream>
#include <string>

using namespace std;

// Clase base: Vehiculo
class Vehiculo {
protected:
    string marca;  // Marca del vehículo
    int anio;      // Año de fabricación

public:
    Vehiculo(const string& marca, int anio) : marca(marca), anio(anio) {}

    void iniciar() {
        cout << "Encendiendo el vehículo..." << endl;
    }

    void detener() {
        cout << "Apagando el vehículo..." << endl;
    }
};

// Clase derivada: Automovil (hereda de Vehiculo)
class Automovil : public Vehiculo {
private:
    int numPuertas;  // Número de puertas

public:
    Automovil(const string& marca, int anio, int numPuertas)
        : Vehiculo(marca, anio), numPuertas(numPuertas) {}

    void mostrarInformacion() {
        cout << "Marca del automóvil: " << marca << ", Año: " << anio << ", Puertas: " << numPuertas << endl;
    }
};

// Clase derivada: Camion (hereda de Vehiculo)
class Camion : public Vehiculo {
private:
    double capacidadCarga;  // Capacidad de carga en toneladas

public:
    Camion(const string& marca, int anio, double capacidadCarga)
        : Vehiculo(marca, anio), capacidadCarga(capacidadCarga) {}

    void mostrarInformacion() {
        cout << "Marca del camión: " << marca << ", Año: " << anio << ", Capacidad de carga: " << capacidadCarga << " toneladas" << endl;
    }
};

int main() {
    // Crear un objeto Automovil y usar métodos heredados
    Automovil miAutomovil("Toyota", 2020, 4);
    miAutomovil.iniciar();
    miAutomovil.mostrarInformacion();
    miAutomovil.detener();

    cout << endl;

    // Crear un objeto Camion y usar métodos heredados
    Camion miCamion("Ford", 2018, 2.5);
    miCamion.iniciar();
    miCamion.mostrarInformacion();
    miCamion.detener();

    return 0;
}
