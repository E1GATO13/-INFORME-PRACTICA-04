#include <iostream>

using namespace std;

class Estudiante {
private:
	string nombre;
	int codigo;
	
public:
	Estudiante(string nombre, int codigo) {
		this->nombre = nombre;
		this->codigo = codigo;
	}
	
	string getNombre() { return nombre; }
	int getCodigo() { return codigo; }
};

class Docente {
private:
	string nombre;
	string especialidad;
	
public:
	Docente(string nombre, string especialidad) {
		this->nombre = nombre;
		this->especialidad = especialidad;
	}
	
	string getNombre() { return nombre; }
	string getEspecialidad() { return especialidad; }
};

class Curso {
private:
	string nombre;
	int creditos;
	
public:
	Curso(string nombre, int creditos) {
		this->nombre = nombre;
		this->creditos = creditos;
	}
	
	string getNombre() { return nombre; }
	int getCreditos() { return creditos; }
};

class Asociacion {
private:
	Estudiante* estudiante;
	Docente* docente;
	Curso* curso;
	
public:
	Asociacion(Estudiante* estudiante, Docente* docente, Curso* curso) {
		this->estudiante = estudiante;
		this->docente = docente;
		this->curso = curso;
	}
	
	Estudiante* getEstudiante() { return estudiante; }
	Docente* getDocente() { return docente; }
	Curso* getCurso() { return curso; }
};

int main() {
	// Pedir datos al usuario
	string nombreEstudiante, nombreDocente, nombreCurso;
	
	cout << "Ingrese el nombre del estudiante: ";
	cin >> nombreEstudiante;
	
	cout << "Ingrese el nombre del docente: ";
	cin >> nombreDocente;
	
	cout << "Ingrese el nombre del curso: ";
	cin >> nombreCurso;
	
	// Crear instancias con los datos ingresados
	Estudiante* estudiante1 = new Estudiante(nombreEstudiante, 1234);
	Docente* docente1 = new Docente(nombreDocente, "Matematica");
	Curso* curso1 = new Curso(nombreCurso, 4);
	
	// Se puede generar un código aleatorio para el codigo del estudiante
	
	// Crear una asociación
	Asociacion* asociacion1 = new Asociacion(estudiante1, docente1, curso1);
	
	// ...
	
	// Mostrar la información
	cout << "Estudiante: " << asociacion1->getEstudiante()->getNombre() << endl;
	cout << "Docente: " << asociacion1->getDocente()->getNombre() << endl;
	cout << "Curso: " << asociacion1->getCurso()->getNombre() << endl;
	
	// Liberación de memoria
	delete estudiante1;
	delete docente1;
	delete curso1;
	delete asociacion1;
	
	return 0;
}
