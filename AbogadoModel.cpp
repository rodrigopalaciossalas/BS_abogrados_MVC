// AbogadoModel.cpp
#include "AbogadoModel.hpp"
#include <iostream>
#include <fstream>
#include "ColorManipulation.hpp"

AbogadoModel::AbogadoModel()
    : abogados(nullptr), cantidad(0), capacidad(2) 
    {
    abogados = new Abogado*[capacidad];
    cargarDesdeArchivo("abogados.txt");
}

AbogadoModel::~AbogadoModel() {
    for (int i = 0; i < cantidad; i++) 
    {
        delete abogados[i];
    }
    delete[] abogados;
}

void AbogadoModel::redimensionar() {
    capacidad *= 2;
    Abogado** nuevosAbogados = new Abogado*[capacidad];
    for (int i = 0; i < cantidad; i++) {
        nuevosAbogados[i] = abogados[i];
    }
    delete[] abogados;
    abogados = nuevosAbogados;
}

void AbogadoModel::agregarAbogado(Abogado* abogado) {
    if (cantidad == capacidad) {
        redimensionar();
    }
    abogados[cantidad++] = abogado;
    guardarEnArchivo("abogados.txt");
}

void AbogadoModel::eliminarAbogadoPorID(int id) {
    for (int i = 0; i < cantidad; i++) {
        if (abogados[i]->obtenerID() == id) {
            delete abogados[i];
            for (int j = i; j < cantidad - 1; j++) {
                abogados[j] = abogados[j + 1];
            }
            cantidad--;
            guardarEnArchivo("abogados.txt");
            setTextColor(BRIGHT_YELLOW);
            std::cout << "Abogado con ID " << id << " eliminado.\n";
            resetColor();
            return;
        }
    }
    setTextColor(BRIGHT_RED);
    std::cout << "No se encontró un abogado con el ID " << id << ".\n";
    resetColor();
}

Abogado* AbogadoModel::buscarAbogadoPorID(int id) {
    for (int i = 0; i < cantidad; i++) {
        if (abogados[i]->obtenerID() == id) {
            return abogados[i];
        }
    }
    return nullptr;
}

void AbogadoModel::listarAbogados() {
    if (cantidad == 0) {
        setTextColor(BRIGHT_YELLOW);
        std::cout << "No hay abogados registrados.\n";
        resetColor();
        return;
    }
    for (int i = 0; i < cantidad; i++) {
        Abogado* abogado = abogados[i];
        std::cout << "ID: " << abogado->obtenerID()
                  << ", Nombre: " << abogado->getNombres() << " " << abogado->getApellidos()
                  << ", Especialidad: " << abogado->getEspecialidad() << "\n";
    }
}

void AbogadoModel::cargarDesdeArchivo(const char* nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        setTextColor(BRIGHT_RED);
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << "\n";
        resetColor();
        return;
    }

    char linea[1024];  // Usamos un buffer de tamaño adecuado para cada línea
    while (archivo.getline(linea, sizeof(linea))) {
        int id, salario, dia, mes, anio;
        char* nombre = nullptr;
        char* apellido = nullptr;
        char* telefono = nullptr;
        char* correo = nullptr;
        char* especialidad = nullptr;
        char* puesto = nullptr;
        char* fechaStr = nullptr;

        int inicio = 0;  // Inicializamos la posición de inicio en la cadena

        // Dividimos la línea en tokens usando dividirCadena
        char* token = A_puntero::dividirCadena(linea, ',', inicio);
        if (token != nullptr) {
            id = atoi(token);  // El primer campo es el ID
            delete[] token;  // Liberamos el token
        }

        token = A_puntero::dividirCadena(linea, ',', inicio);
        if (token != nullptr) {
            A_puntero::copiarCadena(nombre, token);  // Nombre
            delete[] token;
        }

        token = A_puntero::dividirCadena(linea, ',', inicio);
        if (token != nullptr) {
            A_puntero::copiarCadena(apellido, token);  // Apellido
            delete[] token;
        }

        token = A_puntero::dividirCadena(linea, ',', inicio);
        if (token != nullptr) {
            A_puntero::copiarCadena(telefono, token);  // Teléfono
            delete[] token;
        }

        token = A_puntero::dividirCadena(linea, ',', inicio);
        if (token != nullptr) {
            A_puntero::copiarCadena(correo, token);  // Correo
            delete[] token;
        }

        token = A_puntero::dividirCadena(linea, ',', inicio);
        if (token != nullptr) {
            A_puntero::copiarCadena(especialidad, token);  // Especialidad
            delete[] token;
        }

        token = A_puntero::dividirCadena(linea, ',', inicio);
        if (token != nullptr) {
            salario = atoi(token);  // Salario
            delete[] token;
        }

        token = A_puntero::dividirCadena(linea, ',', inicio);
        if (token != nullptr) {
            A_puntero::copiarCadena(puesto, token);  // Puesto
            delete[] token;
        }

        token = A_puntero::dividirCadena(linea, ',', inicio);
        if (token != nullptr) {
            A_puntero::copiarCadena(fechaStr, token);  // Fecha (por ejemplo: 15/05/2020)
            delete[] token;
        }

        // Parseamos la fecha
        if (fechaStr != nullptr) {
            sscanf(fechaStr, "%d/%d/%d", &dia, &mes, &anio);
        }

        // Crear un nuevo abogado
        Abogado* abogado = new Abogado(nombre, apellido, telefono, correo, 30, especialidad, salario, puesto, correo, dia, mes, anio);
        abogado->setID(id);  // Asignar el ID correctamente
        agregarAbogado(abogado);  // Agregar a la lista

        // Liberar memoria de las cadenas copiadas
        delete[] nombre;
        delete[] apellido;
        delete[] telefono;
        delete[] correo;
        delete[] especialidad;
        delete[] puesto;
        delete[] fechaStr;
    }
    archivo.close();
}


void AbogadoModel::guardarEnArchivo(const char* nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::trunc);
    if (!archivo.is_open()) {
        setTextColor(BRIGHT_RED);
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << "\n";
        resetColor();
        return;
    }
    for (int i = 0; i < cantidad; i++) {
        Abogado* abogado = abogados[i];
        archivo << abogado->obtenerID() << ","
                << abogado->getNombres() << ","
                << abogado->getApellidos() << ","
                << abogado->getTelefono() << ","
                << abogado->getCorreo() << ","
                << abogado->getEspecialidad() << ","
                << abogado->getSalario() << ","
                << abogado->getPuesto() << ","
                << abogado->getFechaContratacion().dia << "/" 
                << abogado->getFechaContratacion().mes << "/" 
                << abogado->getFechaContratacion().anio << "\n";
    }
    archivo.close();
}
