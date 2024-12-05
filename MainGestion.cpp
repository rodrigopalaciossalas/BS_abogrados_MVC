#include <iostream>
#include "MainGestion.hpp"  // Incluir el archivo con las funciones
#include "ColorManipulation.hpp"
void mostrarMenu(int &opcion){
    resetCursor();
    clearScreen();
    setTextColor(YELLOW);
    std::cout << "\nMenu Principal de Gestion:\n";
    resetColor();
    setTextColor(GREEN);
    std::cout << "1.";
    resetColor();
    std::cout << " Gestion de Abogados\n";
    setTextColor(GREEN);
    std::cout << "2.";
    resetColor();
    std::cout << " Gestion de Economia (Boletas y Facturas)\n";
    setTextColor(GREEN);
    std::cout << "3.";
    resetColor();
    std::cout << " Documentos\n";
    setTextColor(GREEN);
    std::cout << "4.";
    resetColor();
    std::cout << " Clientes\n";
    setTextColor(GREEN);
    std::cout << "5.";
    resetColor();
    std::cout << " Salir\n";
    setTextColor(YELLOW);
    std::cout << "Seleccione una opción: ";
    resetColor();
    std::cin >> opcion;
    std::cin.ignore();  // Limpiar el buffer de entrada
}

void gestionarAbogados() {
    AbogadoModel modelo;
    AbogadoView vista;
    AbogadoController controlador(&modelo, &vista);

    controlador.iniciar();  // Inicia la gestión de abogados
}

// Función para gestionar Economía (Boletas y Facturas)
void gestionarEconomia() {
    // Crear una instancia de MainEconomia con los nombres de archivo para Boletas y Facturas
    const char* archivoBoletas = "boletas.txt";
    const char* archivoFacturas = "facturas.txt";

    // Crear un objeto de la clase MainEconomia
    MainEconomia mainEconomia(archivoBoletas, archivoFacturas);

    // Llamar al método iniciar para comenzar la gestión de economía
    mainEconomia.iniciar();
}

void gestionarDocumentos() {
    DocumentosManager manager;

    manager.gestionarDocumentos();

}

void gestionarClientes() {
    const char* nombreArchivo = "clientes.txt"; // Nombre del archivo donde se guardarán los clientes
    std::ofstream archivo(nombreArchivo, std::ios::app); // Abre el archivo en modo append

    if (!archivo) {
        std::cout << "Error al abrir el archivo para escribir." << std::endl;
        return; // Salir de la función si hay un error
    }

    int busqueda;
    int opcion;
    do {
        resetCursor();
        clearScreen();
        setTextColor(YELLOW);
        std::cout << "\n*** Menú de Clientes ***" << std::endl;
        resetColor();
        setTextColor(GREEN);
        std::cout << "1.";
        resetColor();
        std::cout <<" Registrar Cliente" << std::endl;
        setTextColor(GREEN);
        std::cout << "2.";
        resetColor();
        std::cout <<" Mostrar Clientes" << std::endl;
        setTextColor(GREEN);
        std::cout << "3.";
        resetColor();
        std::cout <<" Buscar por ID" << std::endl;
        setTextColor(GREEN);
        std::cout << "4.";
        resetColor();
        std::cout << " Salir" << std::endl;
        setTextColor(YELLOW);
        std::cout << "Seleccione una opción: ";
        resetColor();
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1: {
                Clientes cliente("", "", "", "", 0, 0, "", ""); // cliente temporal
                cliente.registrarCliente(archivo);
                break;
            }
            case 2: {
                Clientes::mostrarClientes(nombreArchivo);
                break;
            }
            case 3: {
                std::cout << "Ingresa id del cliente: ";
                std::cin >> busqueda;

                // Crear un objeto cliente para llamar a buscarCliente
                Clientes cliente("", "", "", "", 0, 0, "", "");
                cliente.buscarCliente(nombreArchivo, busqueda);
                break;
            }
            case 4:
                std::cout << "Adios" << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
        }
    } while (opcion != 4); 

    archivo.close(); 
}