#include "MainEconomia.hpp"
#include <iostream>
#include <fstream>  // Necesario para manejar archivos
#include "ColorManipulation.hpp"
// Implementación del constructor
MainEconomia::MainEconomia(const char* archivoBoletas, const char* archivoFacturas)
    : nombreArchivoBoletas(archivoBoletas), nombreArchivoFacturas(archivoFacturas) {
}

// Implementación del método iniciar que maneja el menú
void MainEconomia::iniciar() {
    int opcion;

    do {

        resetCursor();
        clearScreen();
        setTextColor(BRIGHT_YELLOW);
        std::cout << "\nMenu Principal:\n";
        resetColor();
        setTextColor(BRIGHT_CYAN);
        std::cout << "1.";
        resetColor();
        std::cout << "Boletas\n";
        setTextColor(BRIGHT_CYAN);
        std::cout << "2."; 
        resetColor();
        std::cout << "Facturas\n";
        setTextColor(BRIGHT_CYAN);
        std::cout << "3."; 
        resetColor();
        std::cout << "Salir\n";
        setTextColor(BRIGHT_YELLOW);
        std::cout << "Seleccione una opcion: ";
        resetColor();
        std::cin >> opcion;
        std::cin.ignore();  // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                gestionarBoletas();  // Invoca la función que gestiona boletas
                break;

            case 2:
                gestionarFacturas();  // Invoca la función que gestiona facturas
                break;

            case 3:
                setTextColor(BRIGHT_RED);
                std::cout << "Saliendo...\n";
                resetColor();
                break;
            default:
                setTextColor(BRIGHT_RED);
                std::cout << "Opción no válida. Intente nuevamente.\n";
                resetColor();
                break;
        }
    } while (opcion != 3);
}


// Implementación de la gestión de boletas
void MainEconomia::gestionarBoletas() {
    GestionarBoletas(listaBoletas, nombreArchivoBoletas); 
}

// Implementación de la gestión de facturas
void MainEconomia::gestionarFacturas() {
    GestionarFacturas(listaFacturas, nombreArchivoFacturas); 
}

void MainEconomia::mostrarMenuBoletas() {
    setTextColor(BRIGHT_YELLOW);
    std::cout << "\nMenu de Boletas:\n";
    resetColor();
    setTextColor(BRIGHT_CYAN);    
    std::cout << "1.";
    resetColor();
    std::cout << " Mostrar Lista de Boletas\n";
    setTextColor(BRIGHT_CYAN);
    std::cout << "2.";
    resetColor();
    std::cout << " Agregar Boleta\n";
    setTextColor(BRIGHT_CYAN);
    std::cout << "3.";
    resetColor();
    std::cout << " Modificar Boleta\n";
    setTextColor(BRIGHT_CYAN);
    std::cout << "4.";
    resetColor();
    std::cout << " Eliminar Boleta\n";
    setTextColor(BRIGHT_CYAN);
    std::cout << "5.";
    resetColor();
    std::cout << " Volver al menu principal\n";
}

// Implementación del método de gestión de boletas
void MainEconomia::GestionarBoletas(ListaGenerica& listaBoletas, const char* nombreArchivoBoletas) {
    int subOpcion, id;
    char nuevoDato[256];

    do {
        mostrarMenuBoletas();
        setTextColor(BRIGHT_YELLOW);
        std::cout << "Seleccione una opción: ";
        resetColor();
        std::cin >> subOpcion;
        std::cin.ignore();  // Limpiar el buffer de entrada

        switch (subOpcion) {
            case 1:
                // Mostrar lista de Boletas
                std::cout << "\nLista de Boletas:\n";
                listaBoletas.mostrarLista(nombreArchivoBoletas);
                break;

            case 2:
                // Agregar Boleta
                std::cout << "\nIngrese el dato de la nueva boleta (ID,Descripción): ";
                std::cin.getline(nuevoDato, 256);
                listaBoletas.agregarDato(nombreArchivoBoletas, nuevoDato);
                break;

            case 3:
                // Modificar Boleta
                std::cout << "\nIngrese el ID de la boleta a modificar: ";
                std::cin >> id;
                std::cin.ignore();  // Limpiar el buffer de entrada
                std::cout << "Ingrese el nuevo dato para la boleta: ";
                std::cin.getline(nuevoDato, 256);
                listaBoletas.modificarDato(nombreArchivoBoletas, id, nuevoDato);
                break;

            case 4:
                // Eliminar Boleta
                std::cout << "\nIngrese el ID de la boleta a eliminar: ";
                std::cin >> id;
                listaBoletas.borrarPorID(nombreArchivoBoletas, id);
                break;

            case 5:
                // Volver al menú principal
                break;

            default:
                std::cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }
    } while (subOpcion != 5);
}

// Implementación del método de gestión de facturas
void MainEconomia::mostrarMenuFacturas() {
    setTextColor(BRIGHT_YELLOW);
    std::cout << "\nMenu de Facturas:\n";
    resetColor();
    setTextColor(BRIGHT_CYAN);
    std::cout << "1.";
    resetColor();
    std::cout << " Mostrar Lista de Facturas\n";
    setTextColor(BRIGHT_CYAN); 
    std::cout << "2.";
    resetColor();
    std::cout << " Agregar Factura\n";
    setTextColor(BRIGHT_CYAN);
    std::cout << "3.";
    resetColor();
    std::cout << " Modificar Factura\n";
    setTextColor(BRIGHT_CYAN);
    std::cout << "4.";
    resetColor();
    std::cout << " Eliminar Factura\n";
    setTextColor(BRIGHT_CYAN);
    std::cout << "5.";
    resetColor();
    std::cout << " Volver al menú principal\n";
}

void MainEconomia::GestionarFacturas(ListaGenerica& listaFacturas, const char* nombreArchivoFacturas) {
    int subOpcion, id;
    char nuevoDato[256];

    do {
        mostrarMenuFacturas();
        setTextColor(BRIGHT_YELLOW);
        std::cout << "Seleccione una opcion: ";
        resetColor();
        std::cin >> subOpcion;
        std::cin.ignore();  // Limpiar el buffer de entrada

        switch (subOpcion) {
            case 1:
                // Mostrar lista de Facturas
                std::cout << "\nLista de Facturas:\n";
                listaFacturas.mostrarLista(nombreArchivoFacturas);
                break;

            case 2:
                // Agregar Factura
                std::cout << "\nIngrese el dato de la nueva factura (ID,Descripcion): ";
                std::cin.getline(nuevoDato, 256);
                listaFacturas.agregarDato(nombreArchivoFacturas, nuevoDato);
                break;

            case 3:
                // Modificar Factura
                std::cout << "\nIngrese el ID de la factura a modificar: ";
                std::cin >> id;
                std::cin.ignore();  // Limpiar el buffer de entrada
                std::cout << "Ingrese el nuevo dato para la factura: ";
                std::cin.getline(nuevoDato, 256);
                listaFacturas.modificarDato(nombreArchivoFacturas, id, nuevoDato);
                break;

            case 4:
                // Eliminar Factura
                std::cout << "\nIngrese el ID de la factura a eliminar: ";
                std::cin >> id;
                listaFacturas.borrarPorID(nombreArchivoFacturas, id);
                break;

            case 5:
                // Volver al menú principal
                break;

            default:
                setTextColor(BRIGHT_RED);
                std::cout << "Opcion no valida. Intente nuevamente.\n";
                resetColor();
                break;
        }
    } while (subOpcion != 5);
}

