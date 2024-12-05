#ifndef DOCUMENTOSMANAGER_HPP
#define DOCUMENTOSMANAGER_HPP

#include "DocumentosModel.hpp"
#include "DocumentosView.hpp"
#include "DocumentosController.hpp"
#include "Fecha.hpp"
#include <iostream>
#include <fstream>

class DocumentosManager {
public:
    // Constructor y destructor
    DocumentosManager();
    ~DocumentosManager();

    // Función para crear el archivo si no existe
    void crearArchivoSiNoExiste(const char* nombreArchivo);

    // Función para gestionar los documentos
    void gestionarDocumentos();

    // Función para mostrar el menú principal
    void mostrarMenu(int& opcion);
    
private:
    Documentos* documentos;  // Puntero para los documentos
    int cantidadDocumentos;  // Cantidad de documentos
};

#endif // DOCUMENTOSMANAGER_HPP
