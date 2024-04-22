#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Cliente {
private:
    string nombre;
    string direccion;
    string telefono;
    vector<string> compras;

public:
    Cliente(const string& nombre, const string& direccion, const string& telefono)
        : nombre(nombre), direccion(direccion), telefono(telefono) {}

    void agregarCompra(const string& compra) {
        compras.push_back(compra);
    }

    const string& getNombre() const {
        return nombre;
    }

    const string& getDireccion() const {
        return direccion;
    }

    const string& getTelefono() const {
        return telefono;
    }

    const vector<string>& getCompras() const {
        return compras;
    }
};

class Producto {
private:
    string codigo;
    string descripcion;
    float precio;
    string proveedor;

public:
    Producto(const string& codigo, const string& descripcion, float precio, const string& proveedor)
        : codigo(codigo), descripcion(descripcion), precio(precio), proveedor(proveedor) {}

    const string& getCodigo() const {
        return codigo;
    }

    const string& getDescripcion() const {
        return descripcion;
    }

    float getPrecio() const {
        return precio;
    }

    const string& getProveedor() const {
        return proveedor;
    }
};

class Venta {
private:
    int numeroFactura;
    time_t fecha;
    Cliente* cliente;
    vector<Producto*> productosVendidos;

public:
    Venta(int numeroFactura, Cliente* cliente)
        : numeroFactura(numeroFactura), cliente(cliente) {
        fecha = time(nullptr); // Establece la fecha y hora actual
    }

    void agregarProducto(Producto* producto) {
        productosVendidos.push_back(producto);
        cliente->agregarCompra(producto->getDescripcion());
    }

    int getNumeroFactura() const {
        return numeroFactura;
    }

    time_t getFecha() const {
        return fecha;
    }

    Cliente* getCliente() const {
        return cliente;
    }

    const vector<Producto*>& getProductosVendidos() const {
        return productosVendidos;
    }
};

class Tienda {
private:
    vector<Cliente*> clientes;
    vector<Producto*> productos;
    vector<Venta*> ventas;
    int numeroFactura;

public:
    Tienda() : numeroFactura(1) {}

    ~Tienda() {
        // Liberar memoria de los objetos
        for (auto cliente : clientes)
            delete cliente;
        for (auto producto : productos)
            delete producto;
        for (auto venta : ventas)
            delete venta;
    }

    void registrarCliente(const string& nombre, const string& direccion, const string& telefono) {
        clientes.push_back(new Cliente(nombre, direccion, telefono));
    }

    void registrarProducto(const string& codigo, const string& descripcion, float precio, const string& proveedor) {
        productos.push_back(new Producto(codigo, descripcion, precio, proveedor));
    }

    void realizarVenta(Cliente* cliente) {
        int productoIndex;
        vector<Producto*> productosVendidos;
        cout << "Productos disponibles: " << endl;
        for (size_t i = 0; i < productos.size(); ++i) {
            cout << i + 1 << ". " << productos[i]->getDescripcion() << endl;
        }
        cout << "Seleccione los productos (ingrese 0 para terminar): ";
        while (true) {
            cin >> productoIndex;
            if (productoIndex == 0)
                break;
            productosVendidos.push_back(productos[productoIndex - 1]);
        }
        Venta* nuevaVenta = new Venta(numeroFactura++, cliente);
        for (auto producto : productosVendidos) {
            nuevaVenta->agregarProducto(producto);
        }
        ventas.push_back(nuevaVenta);

        // Mostrar factura
        cout << "\nFactura de venta:" << endl;
        cout << "Numero de factura: " << nuevaVenta->getNumeroFactura() << endl;
        time_t fecha = nuevaVenta->getFecha();
        cout << "Fecha de venta: " << asctime(localtime(&fecha));
        cout << "Cliente: " << cliente->getNombre() << endl;
        cout << "Productos vendidos:" << endl;
        for (const auto& producto : nuevaVenta->getProductosVendidos()) {
            cout << "- " << producto->getDescripcion() << " (" << producto->getCodigo() << ")" << endl;
        }
    }

    const vector<Cliente*>& getClientes() const {
        return clientes;
    }

    void mostrarVentas() const {
        cout << "Facturas de venta:" << endl;
        for (const auto& venta : ventas) {
            cout << "Numero de factura: " << venta->getNumeroFactura() << endl;
            time_t fecha = venta->getFecha();
            cout << "Fecha de venta: " << asctime(localtime(&fecha));
            cout << "Cliente: " << venta->getCliente()->getNombre() << endl;
            cout << "Productos vendidos:" << endl;
            for (const auto& producto : venta->getProductosVendidos()) {
                cout << "- " << producto->getDescripcion() << " (" << producto->getCodigo() << ")" << endl;
            }
            cout << "---------------------" << endl;
        }
    }
};

void mostrarMenu() {
    cout << "Bienvenido a la Tienda" << endl;
    cout << "1. Registrar Cliente" << endl;
    cout << "2. Registrar Producto" << endl;
    cout << "3. Realizar Venta" << endl;
    cout << "4. Mostrar Ventas" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese el numero de opcion: ";
}

int main() {
    Tienda tienda;

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer del teclado

        switch (opcion) {
            case 1: {
                string nombre, direccion, telefono;
                cout << "Ingrese el nombre del cliente: ";
                getline(cin, nombre);
                cout << "Ingrese la direccion del cliente: ";
                getline(cin, direccion);
                cout << "Ingrese el telefono del cliente: ";
                getline(cin, telefono);
                tienda.registrarCliente(nombre, direccion, telefono);
                cout << "Cliente registrado exitosamente." << endl;
                break;
            }
            case 2: {
                string codigo, descripcion, proveedor;
                float precio;
                cout << "Ingrese el codigo del producto: ";
                getline(cin, codigo);
                cout << "Ingrese la descripcion del producto: ";
                getline(cin, descripcion);
                cout << "Ingrese el precio del producto: ";
                cin >> precio;
                cin.ignore(); // Limpiar el buffer del teclado
                cout << "Ingrese el proveedor del producto: ";
                getline(cin, proveedor);
                tienda.registrarProducto(codigo, descripcion, precio, proveedor);
                cout << "Producto registrado exitosamente." << endl;
                break;
            }
            case 3: {
                int clienteIndex;
                cout << "Clientes disponibles: " << endl;
                const auto& clientes = tienda.getClientes();
                for (size_t i = 0; i < clientes.size(); ++i) {
                    cout << i + 1 << ". " << clientes[i]->getNombre() << endl;
                }
                cout << "Seleccione el cliente: ";
                cin >> clienteIndex;
                cin.ignore(); // Limpiar el buffer del teclado
                tienda.realizarVenta(clientes[clienteIndex - 1]);
                cout << "Venta realizada exitosamente." << endl;
                break;
            }
            case 4:
                tienda.mostrarVentas();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor ingrese un numero valido." << endl;
                break;
        }
    } while (opcion != 5);

    return 0;
}
