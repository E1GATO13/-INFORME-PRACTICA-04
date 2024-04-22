#include <iostream>
#include <string>

using namespace std;

class Trabajador {
protected:
    string nombre;
    Trabajador* companeros[100];
    int numCompaneros;
public:
    Trabajador(string nombre) : nombre(nombre), numCompaneros(0) {}

    string obtenerNombre() const { return nombre; }

    void agregarCompanero(Trabajador* companero) {
        companeros[numCompaneros++] = companero;
    }

    void imprimirCompaneros() const {
        cout << "Compañeros de " << nombre << ":" << endl;
        for (int i = 0; i < numCompaneros; i++) {
            cout << "- " << companeros[i]->obtenerNombre() << endl;
        }
    }
};

class Gerente : public Trabajador {
private:
    Trabajador* trabajadores[100];
    int numTrabajadores;
public:
    Gerente(string nombre) : Trabajador(nombre), numTrabajadores(0) {}

    void agregarTrabajador(Trabajador* trabajador) {
        trabajadores[numTrabajadores++] = trabajador;
    }

    void imprimirTrabajadores() const {
        cout << "Gerente " << nombre << ": " << obtenerNombre() << endl;
        cout << "Grupo de trabajo:" << endl;
        for (int i = 0; i < numTrabajadores; i++) {
            cout << "- " << trabajadores[i]->obtenerNombre() << endl;
        }
    }
};

int main() {
    Gerente gerente1("Carlos");
    Gerente gerente2("José");

    Trabajador* maria = new Trabajador("María");
    Trabajador* pepe = new Trabajador("Pepe");
    Trabajador* pablo = new Trabajador("Pablo");
    Trabajador* juan = new Trabajador("Juan");
    Trabajador* roy = new Trabajador("Roy");
    Trabajador* gian = new Trabajador("Gian");

    gerente1.agregarTrabajador(maria);
    gerente1.agregarTrabajador(pepe);
    gerente1.agregarTrabajador(pablo);
    gerente1.agregarTrabajador(juan);

    gerente2.agregarTrabajador(roy);
    gerente2.agregarTrabajador(gian);

    // Establecer relaciones entre los trabajadores
    maria->agregarCompanero(pepe);
    maria->agregarCompanero(pablo);
    maria->agregarCompanero(juan);

    roy->agregarCompanero(gian);

    // Obtener información sobre los trabajadores de cada gerente
    gerente1.imprimirTrabajadores();
    gerente2.imprimirTrabajadores();

    // Imprimir las relaciones de un trabajador específico
    maria->imprimirCompaneros();
    roy->imprimirCompaneros();

    return 0;
}

/*USO

Gerente Carlos: Carlos
Grupo de trabajo:
- María
- Pepe
- Pablo
- Juan
Gerente José: José
Grupo de trabajo:
- Roy
- Gian
Compañeros de María:
- Pepe
- Pablo
- Juan
Compañeros de Roy:
- Gian
*/
