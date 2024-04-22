#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

// Clase Libro
class Libro {
public:
	string ISBN;
	string titulo;
	int anioPublicacion;
	int cantidadEjemplares;
	string autor;
};

// Clase Autor
class Autor {
public:
	string nombre;
	string nacionalidad;
	vector<Libro> librosEscritos;
};

// Clase Prestamo
class Prestamo {
public:
	Libro libro;
	time_t fechaPrestamo;
	time_t fechaDevolucion;
};

// Clase Usuario
class Usuario {
public:
	string nombre;
	string direccion;
	string telefono;
	vector<Prestamo> librosPrestados;
};

// Clase Biblioteca
class Biblioteca {
public:
	vector<Libro> libros;
	vector<Autor> autores;
	vector<Usuario> usuarios;
	
	void registrarLibro(const Libro& libro, const string& autorNombre);
	void registrarAutor(const Autor& autor);
	void registrarUsuario(const Usuario& usuario);
	void prestarLibro(const string& ISBN, const string& usuarioNombre);
	void devolverLibro(const string& ISBN, const string& usuarioNombre);
};

void Biblioteca::registrarLibro(const Libro& libro, const string& autorNombre) {
	libros.push_back(libro);
	
	// Buscar al autor por nombre y agregar el libro a su lista de libros escritos
	auto it = find_if(autores.begin(), autores.end(), [&](const Autor& a) {
		return a.nombre == autorNombre;
	});
	
	if (it != autores.end()) {
		it->librosEscritos.push_back(libro);
	}
}

void Biblioteca::registrarAutor(const Autor& autor) {
	autores.push_back(autor);
}

void Biblioteca::registrarUsuario(const Usuario& usuario) {
	usuarios.push_back(usuario);
}

void Biblioteca::prestarLibro(const string& ISBN, const string& usuarioNombre) {
	// Buscar al usuario por nombre
	auto itUsuario = find_if(usuarios.begin(), usuarios.end(), [&](const Usuario& u) {
		return u.nombre == usuarioNombre;
	});
	
	if (itUsuario != usuarios.end()) {
		// Buscar el libro por ISBN
		auto itLibro = find_if(libros.begin(), libros.end(), [&](const Libro& l) {
			return l.ISBN == ISBN;
		});
		
		if (itLibro != libros.end() && itLibro->cantidadEjemplares > 0) {
			// Crear un objeto Prestamo y agregarlo a la lista de libros prestados del usuario
			Prestamo prestamo;
			prestamo.libro = *itLibro;
			prestamo.fechaPrestamo = time(nullptr);
			itUsuario->librosPrestados.push_back(prestamo);
			
			// Decrementar la cantidad de ejemplares del libro
			itLibro->cantidadEjemplares--;
		} else {
			cout << "No hay ejemplares disponibles del libro con ISBN " << ISBN << endl;
		}
	} else {
		cout << "No se encontró al usuario con nombre " << usuarioNombre << endl;
	}
}

void Biblioteca::devolverLibro(const string& ISBN, const string& usuarioNombre) {
	// Buscar al usuario por nombre
	auto itUsuario = find_if(usuarios.begin(), usuarios.end(), [&](const Usuario& u) {
		return u.nombre == usuarioNombre;
	});
	
	if (itUsuario != usuarios.end()) {
		// Buscar el préstamo del libro por ISBN en la lista de libros prestados del usuario
		auto itPrestamo = find_if(itUsuario->librosPrestados.begin(), itUsuario->librosPrestados.end(), [&](const Prestamo& p) {
			return p.libro.ISBN == ISBN;
		});
		
		if (itPrestamo != itUsuario->librosPrestados.end()) {
			// Establecer la fecha de devolución
			itPrestamo->fechaDevolucion = time(nullptr);
			
			// Buscar el libro por ISBN y incrementar la cantidad de ejemplares
			auto itLibro = find_if(libros.begin(), libros.end(), [&](const Libro& l) {
				return l.ISBN == ISBN;
			});
			
			if (itLibro != libros.end()) {
				itLibro->cantidadEjemplares++;
			}
		} else {
			cout << "El usuario no tiene prestado el libro con ISBN " << ISBN << endl;
		}
	} else {
		cout << "No se encontró al usuario con nombre " << usuarioNombre << endl;
	}
}
void mostrarLibros(const Biblioteca& biblioteca) {
	cout << "\n--- Libros registrados ---\n";
	if (biblioteca.libros.empty()) {
		cout << "No hay libros registrados.\n";
	} else {
		for (const auto& libro : biblioteca.libros) {
			cout << "ISBN: " << libro.ISBN << "\n";
			cout << "Título: " << libro.titulo << "\n";
			cout << "Año de publicación: " << libro.anioPublicacion << "\n";
			cout << "Cantidad de ejemplares: " << libro.cantidadEjemplares << "\n";
			cout << "Autor: " << libro.autor << "\n\n";
		}
	}
}

int main() {
	Biblioteca biblioteca;
	
	int opcion;
	do {
		cout << "\n--- Sistema de Gestión de Biblioteca ---\n";
		cout << "1. Registrar libro\n";
		cout << "2. Registrar autor\n";
		cout << "3. Registrar usuario\n";
		cout << "4. Prestar libro\n";
		cout << "5. Devolver libro\n";
		cout << "6. Mostrar libros\n";
		cout << "7. Salir\n";
		cout << "Ingrese una opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1: {
			string ISBN, titulo, autorNombre;
			int anioPublicacion, cantidadEjemplares;
			cout << "Ingrese ISBN: ";
			cin >> ISBN;
			cout << "Ingrese título: ";
			cin.ignore();
			getline(cin, titulo);
			cout << "Ingrese año de publicación: ";
			cin >> anioPublicacion;
			cout << "Ingrese cantidad de ejemplares: ";
			cin >> cantidadEjemplares;
			cout << "Ingrese nombre del autor: ";
			cin.ignore();
			getline(cin, autorNombre);
			Libro libro = {ISBN, titulo, anioPublicacion, cantidadEjemplares, autorNombre};
			biblioteca.registrarLibro(libro, autorNombre);
			break;
		}
		case 2: {
			string nombre, nacionalidad;
			cout << "Ingrese nombre del autor: "<<endl;
			cin>>nombre;
			cout << "Ingrese nacionalidad del autor: ";
			cin>>nacionalidad;
			Autor autor = {nombre, nacionalidad, {}};
			biblioteca.registrarAutor(autor);
			break;
		}
		case 3: {
			string nombre, direccion, telefono;
			cout << "Ingrese nombre del usuario: "<<endl;
			cin>>nombre;
			cout << "Ingrese dirección del usuario: "<<endl;
			cin>>direccion;
			cout << "Ingrese teléfono del usuario: "<<endl;
			cin>>telefono;
			Usuario usuario = {nombre, direccion, telefono, {}};
			biblioteca.registrarUsuario(usuario);
			break;
		}
		case 4: {
			string ISBN, usuarioNombre;
			cout << "Ingrese ISBN del libro: ";
			cin >> ISBN;
			cout << "Ingrese nombre del usuario: ";
			cin.ignore();
			getline(cin, usuarioNombre);
			biblioteca.prestarLibro(ISBN, usuarioNombre);
			break;
		}
		case 5: {
			string ISBN, usuarioNombre;
			cout << "Ingrese ISBN del libro: ";
			cin >> ISBN;
			cout << "Ingrese nombre del usuario: ";
			cin.ignore();
			getline(cin, usuarioNombre);
			biblioteca.devolverLibro(ISBN, usuarioNombre);
			break;
		}
		case 6:
			mostrarLibros(biblioteca);
			break;
		case 7:
			cout << "¡Hasta luego!\n";
			break;
		default:
			cout << "Opción inválida. Intente nuevamente.\n";
			break;
		}
	} while (opcion != 7);
	
	return 0;
}
