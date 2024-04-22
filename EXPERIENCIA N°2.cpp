#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Curso; // Declaración anticipada para resolver la dependencia circular

class Estudiante {
private:
    string nombre;
    string apellido;
    string id;
    string correo;
    vector<Curso*> cursos;

public:
    Estudiante(string nombre, string apellido, string id, string correo)
        : nombre(nombre), apellido(apellido), id(id), correo(correo) {}

    string getNombre() const { return nombre + " " + apellido; }
    string getId() const { return id; }
    string getCorreo() const { return correo; }

    void agregarCurso(Curso* curso);
    void eliminarCurso(Curso* curso);
    vector<Curso*> getCursos() const; // Método para obtener la lista de cursos

    void mostrarInfo() const;
};

class Curso {
private:
    string nombre;
    string codigo;
    string descripcion;
    string fechaInicio;
    string fechaFin;
    vector<Estudiante*> estudiantes;

public:
    Curso(string nombre, string codigo, string descripcion, string fechaInicio, string fechaFin)
        : nombre(nombre), codigo(codigo), descripcion(descripcion), fechaInicio(fechaInicio), fechaFin(fechaFin) {}

    const string& getNombre() const { return nombre; }
    const string& getCodigo() const { return codigo; }
    const string& getDescripcion() const { return descripcion; }
    const string& getFechaInicio() const { return fechaInicio; }
    const string& getFechaFin() const { return fechaFin; }

    void agregarEstudiante(Estudiante* estudiante);
    void eliminarEstudiante(Estudiante* estudiante);
    vector<Estudiante*> getEstudiantes() const; // Método para obtener la lista de estudiantes

    void mostrarInfo() const;
};

void Estudiante::agregarCurso(Curso* curso) {
    cursos.push_back(curso);
}

void Estudiante::eliminarCurso(Curso* curso) {
    for (auto it = cursos.begin(); it != cursos.end(); ++it) {
        if (*it == curso) {
            cursos.erase(it);
            break;
        }
    }
}

vector<Curso*> Estudiante::getCursos() const {
    return cursos;
}

void Estudiante::mostrarInfo() const {
    cout << "NOMBRE: " << getNombre() << endl;
    cout << "ID: " << getId() << endl;
    cout << "CORREO: " << getCorreo() << endl;
    cout << "CURSOS:" << endl;
    for (size_t i = 0; i < cursos.size(); ++i) {
        cout << "- " << cursos[i]->getNombre() << endl;
    }
}

void Curso::agregarEstudiante(Estudiante* estudiante) {
    estudiantes.push_back(estudiante);
    estudiante->agregarCurso(this);
}

void Curso::eliminarEstudiante(Estudiante* estudiante) {
    for (auto it = estudiantes.begin(); it != estudiantes.end(); ++it) {
        if (*it == estudiante) {
            estudiantes.erase(it);
            break;
        }
    }
    estudiante->eliminarCurso(this);
}

vector<Estudiante*> Curso::getEstudiantes() const {
    return estudiantes;
}

void Curso::mostrarInfo() const {
    cout << "NOMBRE: " << nombre << endl;
    cout << "CODIGO: " << codigo << endl;
    cout << "DESCRIPCION: " << descripcion << endl;
    cout << "FECHA DE INICIO: " << fechaInicio << endl;
    cout << "FECHA DE FIN: " << fechaFin << endl;
    cout << "ESTUDIANTES MATRICULADOS:" << endl;
    for (size_t i = 0; i < estudiantes.size(); ++i) {
        cout << "- " << estudiantes[i]->getNombre() << endl;
    }
}

int main() {
    // Crear estudiantes
    Estudiante estudiante1("Maria", "Vilca", "54321", "maria@example.com");
    Estudiante estudiante2("Pedro", "Ruiz", "12345", "juan@example.com");

    // Crear cursos
    Curso curso1("Algoritmos", "CSCI301", "Curso sobre algoritmos", "01/02/2024", "01/05/2024");
    Curso curso2("Estructuras de Datos", "CSCI201", "Curso avanzado sobre estructuras de datos", "15/01/2024", "15/04/2024");

    // Agregar estudiantes a cursos
    curso1.agregarEstudiante(&estudiante1);
    curso1.agregarEstudiante(&estudiante2);
    curso2.agregarEstudiante(&estudiante1);

    // Mostrar información de los estudiantes
    cout << "----ESTUDIANTES----" << endl;
    estudiante1.mostrarInfo();
    cout << endl;
    estudiante2.mostrarInfo();
    cout << endl;

    // Mostrar información de los cursos
    cout << "----CURSOS----" << endl;
    curso1.mostrarInfo();
    cout << endl;
    curso2.mostrarInfo();
    cout << endl;

    return 0;
}


