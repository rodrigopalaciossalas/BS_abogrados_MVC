#ifndef LISTAGENERICA_HPP
#define LISTAGENERICA_HPP

#include <iostream>
#include <fstream>

class ListaGenerica {
private:
    char** datos;     // Matriz dinámica para almacenar líneas de texto
    int cantidad;     // Cantidad de líneas almacenadas
    int capacidad;    // Capacidad máxima actual de la matriz

    void redimensionar(int nuevaCapacidad) 
    {
        if (nuevaCapacidad <= 0) return;

        char** nuevaLista = new char*[nuevaCapacidad];
        if (nuevaLista == nullptr) 
        {
            std::cerr << "Error al redimensionar la lista.\n";
            return;
        }

        for (int i = 0; i < cantidad; ++i) 
        {
            nuevaLista[i] = datos[i];
        }
        delete[] datos;
        datos = nuevaLista;
        capacidad = nuevaCapacidad;
    }

    void cargarDesdeArchivo(const char* nombreArchivo) 
    {
        // Limpiar datos actuales
        for (int i = 0; i < cantidad; ++i) 
        {
            delete[] datos[i];
        }
        cantidad = 0;

        // Leer el archivo
        std::ifstream archivo(nombreArchivo);
        if (!archivo.is_open())
        {
            std::cerr << "Error al abrir el archivo: " << nombreArchivo << "\n";
            return;
        }

        char caracter;
        char* linea = new char[256]; // Asignar un buffer temporal
        int index = 0;

        while (archivo.get(caracter)) 
        {
            if (caracter == '\n' || archivo.eof()) 
            {
                linea[index] = '\0';  // Finalizar la cadena

                if (cantidad >= capacidad) 
                {
                    redimensionar(capacidad * 2);
                }

                datos[cantidad] = new char[index + 1];
                if (datos[cantidad] == nullptr) 
                {
                    std::cerr << "Error al asignar memoria para la línea.\n";
                    return;
                }
                for (int i = 0; i <= index; ++i) 
                {
                    datos[cantidad][i] = linea[i];
                }
                ++cantidad;

                index = 0;  // Resetear el índice para la siguiente línea
            } 
            else 
            {
                linea[index++] = caracter;
            }
        }

        delete[] linea; // Liberar el buffer temporal
        archivo.close();
    }

    void guardarEnArchivo(const char* nombreArchivo) 
    {
        std::ofstream archivo(nombreArchivo, std::ios::trunc);
        if (!archivo.is_open()) 
        {
            std::cerr << "Error al abrir el archivo para guardar: " << nombreArchivo << "\n";
            return;
        }
        for (int i = 0; i < cantidad; ++i) 
        {
            if (datos[i] != nullptr) 
            {
                archivo << datos[i] << "\n";
            }
        }
        archivo.close();
    }

public:
    ListaGenerica(int capacidadInicial = 10) 
        : cantidad(0), capacidad(capacidadInicial) 
        {
        if (capacidadInicial <= 0) 
        {
            std::cerr << "Capacidad inicial no válida, se usa capacidad predeterminada de 10.\n";
            capacidad = 10;
        }
        datos = new char*[capacidad];
        if (datos == nullptr) 
        {
            std::cerr << "Error al asignar memoria para la lista.\n";
            return;
        }
    }

    ~ListaGenerica()
    {
        for (int i = 0; i < cantidad; ++i) 
        {
            if (datos[i] != nullptr) 
            {
                delete[] datos[i];
            }
        }
        delete[] datos;
    }

    void mostrarLista(const char* nombreArchivo) 
    {
        cargarDesdeArchivo(nombreArchivo);
        if (cantidad == 0) {
            std::cout << "No hay datos en el archivo.\n";
            return;
        }
        for (int i = 0; i < cantidad; ++i) 
        {
            if (datos[i] != nullptr) 
            {
                std::cout << i + 1 << ": " << datos[i] << "\n";
            }
        }
    }

    void agregarDato(const char* nombreArchivo, const char* nuevoDato) 
    {
        cargarDesdeArchivo(nombreArchivo);
        if (cantidad >= capacidad) {
            redimensionar(capacidad * 2);
        }
        
        int len = 0;
        while (nuevoDato[len] != '\0') ++len;  // Encontrar longitud de nuevoDato
        
        datos[cantidad] = new char[len + 1];
        if (datos[cantidad] == nullptr) 
        {
            std::cerr << "Error al asignar memoria para el nuevo dato.\n";
            return;
        }
        for (int i = 0; i <= len; ++i) 
        {
            datos[cantidad][i] = nuevoDato[i];
        }
        ++cantidad;
        guardarEnArchivo(nombreArchivo);
        std::cout << "Dato agregado exitosamente.\n";
    }

    void modificarDato(const char* nombreArchivo, int id, const char* nuevoDato) 
    {
        cargarDesdeArchivo(nombreArchivo);
        for (int i = 0; i < cantidad; ++i) 
        {
            int idActual = atoi(datos[i]);
            if (idActual == id) {
                int len = 0;
                while (nuevoDato[len] != '\0') ++len;  // Encontrar longitud de nuevoDato
                
                delete[] datos[i];
                datos[i] = new char[len + 1];
                if (datos[i] == nullptr) 
                {
                    std::cerr << "Error al asignar memoria para el nuevo dato.\n";
                    return;
                }
                for (int j = 0; j <= len; ++j) 
                {
                    datos[i][j] = nuevoDato[j];
                }
                guardarEnArchivo(nombreArchivo);
                std::cout << "Dato modificado exitosamente.\n";
                return;
            }
        }
        std::cerr << "No se encontró un elemento con el ID " << id << ".\n";
    }

    void borrarPorID(const char* nombreArchivo, int id) 
    {
        cargarDesdeArchivo(nombreArchivo);
        for (int i = 0; i < cantidad; ++i) 
        {
            int idActual = atoi(datos[i]);
            if (idActual == id) {
                if (datos[i] != nullptr) 
                {
                    delete[] datos[i];
                    datos[i] = nullptr;
                }
                for (int j = i; j < cantidad - 1; ++j) 
                {
                    if (datos[j + 1] != nullptr)
                    {
                        datos[j] = datos[j + 1];
                    }
                }
                --cantidad;
                guardarEnArchivo(nombreArchivo);
                std::cout << "Elemento con ID " << id << " eliminado.\n";
                return;
            }
        }
        std::cerr << "No se encontró un elemento con el ID " << id << ".\n";
    }
};

#endif // LISTAGENERICA_HPP
