// AbogadoModel.hpp
#ifndef ABOGADO_MODEL_HPP
#define ABOGADO_MODEL_HPP

#include "Abogado.hpp"
#include <fstream>

class AbogadoModel {
private:
    Abogado** abogados;  // Lista interna de punteros a Abogado
    int cantidad;        // Cantidad de abogados
    int capacidad;       // Capacidad actual de la lista

    void redimensionar(); // Aumenta la capacidad del arreglo dinámico

public:
    AbogadoModel();
    ~AbogadoModel();

    void agregarAbogado(Abogado* abogado); // Agrega un abogado a la lista
    void eliminarAbogadoPorID(int id); // Elimina un abogado por ID
    Abogado* buscarAbogadoPorID(int id); // Busca un abogado por ID
    void listarAbogados(); // Lista todos los abogados

    // Persistencia
    void cargarDesdeArchivo(const char* nombreArchivo); // Carga la lista desde un archivo
    void guardarEnArchivo(const char* nombreArchivo);  // Guarda la lista en un archivo


};

#endif // ABOGADO_MODEL_HPP
