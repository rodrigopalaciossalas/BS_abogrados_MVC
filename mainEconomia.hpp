#ifndef MAINECONOMIA_HPP
#define MAINECONOMIA_HPP

#include "ListaGenerica.hpp"

class MainEconomia {
private:
    ListaGenerica listaBoletas;
    ListaGenerica listaFacturas;
    const char* nombreArchivoBoletas;
    const char* nombreArchivoFacturas;

public:
    MainEconomia(const char* archivoBoletas, const char* archivoFacturas);
    void iniciar();  // Método para iniciar la interfaz y manejar el menú
    void gestionarBoletas();
    void gestionarFacturas();
    // Métodos para gestionar boletas y facturas
    void mostrarMenuBoletas();
    void mostrarMenuFacturas();
    void GestionarBoletas(ListaGenerica& lista, const char* nombreArchivo);
    void GestionarFacturas(ListaGenerica& lista, const char* nombreArchivo);
};

#endif // MAINECONOMIA_HPP
