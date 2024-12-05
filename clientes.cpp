#include "Clientes.hpp"
#include "A_punteros.hpp"

Clientes::Clientes(const char* _nombres, const char* _apellidos, const char* _telefono, const char* _correo,
                   int edad, int ID, const char* _direccion, const char* _profesion)
    : Persona(_nombres, _apellidos, _telefono, _correo, edad), ID(ID) {
    
    direccion = nullptr;
    profesion = nullptr;

    // Copia segura de las cadenas
    A_puntero::copiarCadena(direccion, _direccion);  
    A_puntero::copiarCadena(profesion, _profesion); 
}

Clientes::~Clientes() {
    // Liberar memoria
    if (direccion != nullptr) {
        delete[] direccion;
    }
    if (profesion != nullptr) {
        delete[] profesion;
    }
}

const char* Clientes::getDireccion() const { 
    return direccion; 
}

const char* Clientes::getProfesion() const { 
    return profesion; 
}

const int Clientes::getID() const { 
    return ID; 
}

void Clientes::setDireccion(const char* _direccion) { 
    if (direccion != nullptr) {
        delete[] direccion;
    }
    A_puntero::copiarCadena(direccion, _direccion); 
}

void Clientes::setProfesion(const char* _profesion) { 
    if (profesion != nullptr) {
        delete[] profesion;
    }
    A_puntero::copiarCadena(profesion, _profesion); 
}

void Clientes::guardarEnArchivo(std::ofstream& archivo) const {
    archivo << "ID: " << ID << std::endl;
    archivo << "Nombres: " << getNombres() << std::endl;
    archivo << "Apellidos: " << getApellidos() << std::endl;
    archivo << "Telefono: " << getTelefono() << std::endl;
    archivo << "Edad: " << getEdad() << std::endl;  
    archivo << "Correo: " << getCorreo() << std::endl;
    archivo << "Direccion: " << getDireccion() << std::endl;
    archivo << "Profesion: " << getProfesion() << std::endl;
    archivo << "------------------------" << std::endl;
}

void Clientes::registrarCliente(std::ofstream& archivo) {
    char nombres[100], apellidos[100], telefono[100], correo[100], direccion[100], profesion[100];
    int edad, id;

    // Ingreso de datos
    std::cout << "Ingrese el nombre del cliente: ";
    std::cin.ignore(); 
    std::cin.getline(nombres, 100);

    std::cout << "Ingrese los apellidos del cliente: ";
    std::cin.getline(apellidos, 100);

    std::cout << "Ingrese el telefono del cliente: ";
    std::cin.getline(telefono, 100);

    std::cout << "Ingrese el correo del cliente: ";
    std::cin.getline(correo, 100);

    std::cout << "Ingrese la edad del cliente: ";
    std::cin >> edad;

    std::cout << "Ingrese el ID del cliente: ";
    std::cin >> id;

    std::cout << "Ingrese la direccion del cliente: ";
    std::cin.ignore(); 
    std::cin.getline(direccion, 100);

    std::cout << "Ingrese la profesion del cliente: ";
    std::cin.getline(profesion, 100);

    // Crear y guardar el cliente
    Clientes nuevoCliente(nombres, apellidos, telefono, correo, edad, id, direccion, profesion);
    nuevoCliente.guardarEnArchivo(archivo);
    std::cout << "Cliente registrado con éxito." << std::endl;
}
#include <iostream>
#include <fstream>

void Clientes::mostrarClientes(const char* nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return;
    }

    char buffer[200];  // Un buffer para almacenar cada línea
    while (archivo.getline(buffer, sizeof(buffer))) {  // Usamos getline con un buffer
        std::cout << buffer << std::endl;  // Imprime la línea leída
    }

    archivo.close();  // Cerrar el archivo después de leer
}

#include <iostream>
#include <fstream>

void Clientes::buscarCliente(const char* nombreArchivo, int id) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return;
    }

    char buffer[200];  // Buffer para almacenar cada línea
    bool encontrado = false;

    // Lee línea por línea
    while (archivo.getline(buffer, sizeof(buffer))) {
        // Comprobamos si la línea contiene "ID: "
        if (buffer[0] == 'I' && buffer[1] == 'D' && buffer[2] == ':' && buffer[3] == ' ') {
            // Extraemos el número después de "ID: " (empezando desde la posición 4)
            int archivoID = 0;
            int i = 4;  // La parte numérica de la cadena está después de "ID: "
            while (buffer[i] != '\0' && buffer[i] >= '0' && buffer[i] <= '9') {
                archivoID = archivoID * 10 + (buffer[i] - '0');  // Convertimos los caracteres en un número
                i++;
            }

            // Si el ID coincide, lo mostramos
            if (archivoID == id) {
                std::cout << "Cliente encontrado: " << std::endl;
                std::cout << buffer << std::endl;
                encontrado = true;
                break;  // Detenemos la búsqueda si encontramos el cliente
            }
        }
    }

    if (!encontrado) {
        std::cout << "Cliente no encontrado." << std::endl;
    }

    archivo.close();  // Cierra el archivo después de leer
}
int Clientes::getEdad() const {
    return getEdad();  // Llamar al método de la clase base (Persona) para obtener la edad
}









