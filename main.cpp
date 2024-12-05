#include <iostream>
#include "MainGestion.hpp"  // Incluir el archivo con las funciones

int main() {
    int opcion;

    do {
        mostrarMenu(opcion);  // Mostrar el menú

        switch (opcion) {
            case 1:
                gestionarAbogados();  // Llamar a la gestión de abogados
                break;

            case 2:
                gestionarEconomia();  // Llamar a la gestión de economía
                break;

            case 3:
                gestionarDocumentos();  // Llamar a la gestión de documentos
                break;
            case 4:
                gestionarClientes();
                break;
            case 5:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }
    } while (opcion != 5);  // Asegúrate de que la opción para salir sea 5

    return 0;
}

