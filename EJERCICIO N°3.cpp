#include <iostream>
#include <string>

using namespace std;

// Constantes para tamaños máximos de arreglos
const int MAX_ESTUDIANTES = 100;
const int MAX_PROFESORES = 50;
const int MAX_ASIGNATURAS = 100;

// Estructura para representar una asignatura
struct Asignatura {
    int codigo;
    string nombre;
    string descripcion;
    int profesorAsociado; // Índice del profesor en el arreglo de profesores
};

// Estructura para representar un estudiante
struct Estudiante {
    string nombre;
    string direccion;
    int numeroMatricula;
    int asignaturasMatriculadas[MAX_ASIGNATURAS]; // Códigos de asignaturas
    float notas[MAX_ASIGNATURAS]; // Notas del estudiante por asignatura
    int faltas[MAX_ASIGNATURAS]; // Faltas de asistencia por asignatura
    int numAsignaturas; // Número de asignaturas matriculadas
};

// Estructura para representar un profesor
struct Profesor {
    string nombre;
    string direccion;
    string numeroTelefono;
    int asignaturasImpartidas[MAX_ASIGNATURAS]; // Códigos de asignaturas
    int numAsignaturas; // Número de asignaturas impartidas
};

// Arreglos para almacenar estudiantes, profesores y asignaturas
Estudiante estudiantes[MAX_ESTUDIANTES];
Profesor profesores[MAX_PROFESORES];
Asignatura asignaturas[MAX_ASIGNATURAS];

int numEstudiantes = 0;
int numProfesores = 0;
int numAsignaturas = 0;

// Función para mostrar el menú y manejar las opciones
void mostrarMenu() {
    cout << "=== Sistema de Gestión Universitaria ===" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Registrar profesor" << endl;
    cout << "3. Registrar asignatura" << endl;
    cout << "4. Matricular estudiante en asignatura" << endl;
    cout << "5. Asignar profesor a asignatura" << endl;
    cout << "6. Registrar nota de estudiante en asignatura" << endl;
    cout << "7. Registrar falta de estudiante en asignatura" << endl;
    cout << "8. Mostrar datos de estudiantes" << endl;
    cout << "9. Mostrar datos de profesores" << endl;
    cout << "10. Mostrar datos de asignaturas" << endl;
    cout << "11. Salir" << endl;
    cout << "Ingrese una opción: ";
}

// Función para registrar un estudiante
void registrarEstudiante() {
    if (numEstudiantes < MAX_ESTUDIANTES) {
        Estudiante nuevoEstudiante;
        cout << "Nombre del estudiante: ";
        cin >> ws;
        getline(cin, nuevoEstudiante.nombre);
        cout << "Dirección: ";
        getline(cin, nuevoEstudiante.direccion);
        cout << "Número de matrícula: ";
        cin >> nuevoEstudiante.numeroMatricula;
        nuevoEstudiante.numAsignaturas = 0; // Inicialmente no está matriculado en ninguna asignatura
        estudiantes[numEstudiantes++] = nuevoEstudiante;
        cout << "Estudiante registrado correctamente." << endl;
    } else {
        cout << "No es posible registrar más estudiantes. Límite alcanzado." << endl;
    }
}

// Función para registrar un profesor
void registrarProfesor() {
    if (numProfesores < MAX_PROFESORES) {
        Profesor nuevoProfesor;
        cout << "Nombre del profesor: ";
        cin >> ws;
        getline(cin, nuevoProfesor.nombre);
        cout << "Dirección: ";
        getline(cin, nuevoProfesor.direccion);
        cout << "Número de teléfono: ";
        getline(cin, nuevoProfesor.numeroTelefono);
        nuevoProfesor.numAsignaturas = 0; // Inicialmente no imparte ninguna asignatura
        profesores[numProfesores++] = nuevoProfesor;
        cout << "Profesor registrado correctamente." << endl;
    } else {
        cout << "No es posible registrar más profesores. Límite alcanzado." << endl;
    }
}

// Función para registrar una asignatura
void registrarAsignatura() {
    if (numAsignaturas < MAX_ASIGNATURAS) {
        Asignatura nuevaAsignatura;
        cout << "Código de asignatura: ";
        cin >> nuevaAsignatura.codigo;
        cout << "Nombre de la asignatura: ";
        cin >> ws;
        getline(cin, nuevaAsignatura.nombre);
        cout << "Descripción: ";
        getline(cin, nuevaAsignatura.descripcion);
        asignaturas[numAsignaturas++] = nuevaAsignatura;
        cout << "Asignatura registrada correctamente." << endl;
    } else {
        cout << "No es posible registrar más asignaturas. Límite alcanzado." << endl;
    }
}

// Función para matricular un estudiante en una asignatura
void matricularEstudiante() {
    int indiceEstudiante, codigoAsignatura;
    cout << "Ingrese el número de matrícula del estudiante: ";
    cin >> indiceEstudiante;
    cout << "Ingrese el código de la asignatura: ";
    cin >> codigoAsignatura;

    if (indiceEstudiante >= 0 && indiceEstudiante < numEstudiantes && codigoAsignatura >= 0 && codigoAsignatura < numAsignaturas) {
        estudiantes[indiceEstudiante].asignaturasMatriculadas[estudiantes[indiceEstudiante].numAsignaturas++] = codigoAsignatura;
        cout << "Estudiante matriculado en la asignatura correctamente." << endl;
    } else {
        cout << "Error: Estudiante o asignatura no encontrados." << endl;
    }
}

// Función para asignar un profesor a una asignatura
void asignarProfesor() {
    int indiceProfesor, codigoAsignatura;
    cout << "Ingrese el índice del profesor: ";
    cin >> indiceProfesor;
    cout << "Ingrese el código de la asignatura: ";
    cin >> codigoAsignatura;

    if (indiceProfesor >= 0 && indiceProfesor < numProfesores && codigoAsignatura >= 0 && codigoAsignatura < numAsignaturas) {
        profesores[indiceProfesor].asignaturasImpartidas[profesores[indiceProfesor].numAsignaturas++] = codigoAsignatura;
        asignaturas[codigoAsignatura].profesorAsociado = indiceProfesor;
        cout << "Profesor asignado a la asignatura correctamente." << endl;
    } else {
        cout << "Error: Profesor o asignatura no encontrados." << endl;
    }
}

// Función para registrar nota de estudiante en una asignatura
void registrarNotaEstudiante() {
    int indiceEstudiante, codigoAsignatura;
    float nota;
    cout << "Ingrese el número de matrícula del estudiante: ";
    cin >> indiceEstudiante;
    cout << "Ingrese el código de la asignatura: ";
    cin >> codigoAsignatura;

    if (indiceEstudiante >= 0 && indiceEstudiante < numEstudiantes && codigoAsignatura >= 0 && codigoAsignatura < numAsignaturas) {
        cout << "Ingrese la nota del estudiante para esta asignatura: ";
        cin >> nota;
        estudiantes[indiceEstudiante].notas[codigoAsignatura] = nota;
        cout << "Nota registrada correctamente." << endl;
    } else {
        cout << "Error: Estudiante o asignatura no encontrados." << endl;
    }
}

// Función para registrar falta de estudiante en una asignatura
void registrarFaltaEstudiante() {
    int indiceEstudiante, codigoAsignatura, faltas;
    cout << "Ingrese el número de matrícula del estudiante: ";
    cin >> indiceEstudiante;
    cout << "Ingrese el código de la asignatura: ";
    cin >> codigoAsignatura;

    if (indiceEstudiante >= 0 && indiceEstudiante < numEstudiantes && codigoAsignatura >= 0 && codigoAsignatura < numAsignaturas) {
        cout << "Ingrese la cantidad de faltas del estudiante para esta asignatura: ";
        cin >> faltas;
        estudiantes[indiceEstudiante].faltas[codigoAsignatura] += faltas;
        cout << "Faltas registradas correctamente." << endl;
    } else {
        cout << "Error: Estudiante o asignatura no encontrados." << endl;
    }
}

// Función para mostrar los datos de estudiantes
void mostrarDatosEstudiantes() {
    cout << "=== Datos de Estudiantes ===" << endl;
    for (int i = 0; i < numEstudiantes; ++i) {
        cout << "Estudiante #" << i + 1 << ":" << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Dirección: " << estudiantes[i].direccion << endl;
        cout << "Número de matrícula: " << estudiantes[i].numeroMatricula << endl;
        cout << "Asignaturas matriculadas: ";
        for (int j = 0; j < estudiantes[i].numAsignaturas; ++j) {
            cout << asignaturas[estudiantes[i].asignaturasMatriculadas[j]].nombre;
            if (j != estudiantes[i].numAsignaturas - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "-------------------------------------" << endl;
    }
}

// Función para mostrar los datos de profesores
void mostrarDatosProfesores() {
    cout << "=== Datos de Profesores ===" << endl;
    for (int i = 0; i < numProfesores; ++i) {
        cout << "Profesor #" << i + 1 << ":" << endl;
        cout << "Nombre: " << profesores[i].nombre << endl;
        cout << "Dirección: " << profesores[i].direccion << endl;
        cout << "Número de teléfono: " << profesores[i].numeroTelefono << endl;
        cout << "Asignaturas impartidas: ";
        for (int j = 0; j < profesores[i].numAsignaturas; ++j) {
            cout << asignaturas[profesores[i].asignaturasImpartidas[j]].nombre;
            if (j != profesores[i].numAsignaturas - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "-------------------------------------" << endl;
    }
}

// Función para mostrar los datos de asignaturas
void mostrarDatosAsignaturas() {
    cout << "=== Datos de Asignaturas ===" << endl;
    for (int i = 0; i < numAsignaturas; ++i) {
        cout << "Asignatura #" << i + 1 << ":" << endl;
        cout << "Código: " << asignaturas[i].codigo << endl;
        cout << "Nombre: " << asignaturas[i].nombre << endl;
        cout << "Descripción: " << asignaturas[i].descripcion << endl;
        cout << "Profesor asociado: " << profesores[asignaturas[i].profesorAsociado].nombre << endl;
        cout << "-------------------------------------" << endl;
    }
}

// Función principal
int main() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch(opcion) {
            case 1:
                registrarEstudiante();
                break;
            case 2:
                registrarProfesor();
                break;
            case 3:
                registrarAsignatura();
                break;
            case 4:
                matricularEstudiante();
                break;
            case 5:
                asignarProfesor();
                break;
            case 6:
                registrarNotaEstudiante();
                break;
            case 7:
                registrarFaltaEstudiante();
                break;
            case 8:
                mostrarDatosEstudiantes();
                break;
            case 9:
                mostrarDatosProfesores();
                break;
            case 10:
                mostrarDatosAsignaturas();
                break;
            case 11:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }

    } while(opcion != 11);

    return 0;
}
