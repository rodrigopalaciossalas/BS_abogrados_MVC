#include "DocumentosManager.hpp"
#include <iostream>
#include <fstream>
#include "ColorManipulation.hpp"
// Constructor y Destructor
DocumentosManager::DocumentosManager() {
    // Inicializar el puntero a los documentos con una cantidad predeterminada de documentos.
}

DocumentosManager::~DocumentosManager() {
    // Liberar la memoria de los documentos si no es nulo
    if (documentos != nullptr) {
        delete[] documentos;
    }
}

void DocumentosManager::crearArchivoSiNoExiste(const char* nombreArchivo) {
    std::ifstream archivo(nombreArchivo);

    // Verificar si el archivo no existe
    if (!archivo) {
        std::ofstream nuevoArchivo(nombreArchivo);
        if (nuevoArchivo) {
            std::cout << "Archivo creado exitosamente: " << nombreArchivo << std::endl;
        } else {
            std::cerr << "No se pudo crear el archivo." << std::endl;
        }
    } else {
        std::cout << "El archivo ya existe." << std::endl;
    }
}

void DocumentosManager::gestionarDocumentos() {
    const char* nombreArchivo = "documentos.txt";
    crearArchivoSiNoExiste(nombreArchivo);

    Fecha fecha1(10, 5, 2021);
    Fecha fecha2(15, 6, 2022);
    Fecha fecha3(20, 7, 2023);

    Documentos* documentos = new Documentos[3]; 
    documentos[0] = Documentos("Contrato", 1, fecha1, "Contrato de alquiler");
    documentos[1] = Documentos("Reporte", 2, fecha2, "Reporte financiero");
    documentos[2] = Documentos("Testamento", 3, fecha3, "Testamento de defuncion");

    int cantidadDocumentos = 3;

    DocumentosController controlador(documentos, cantidadDocumentos);

    int opcion = 0;
    while (true) {  // Usamos true para mantener el ciclo hasta que el usuario elija salir

        resetCursor();
        clearScreen();
        setTextColor(YELLOW);
        std::cout << "\n*** Menu de Opciones ***\n";
        resetColor();
        setTextColor(RED);
        std::cout << "1.";
        resetColor();
         std::cout <<" Buscar documento\n";
        setTextColor(RED);
        std::cout << "2.";
        resetColor();
         std::cout <<" Agregar documento\n";
        setTextColor(RED);
        std::cout << "3.";
        resetColor();
         std::cout <<" Modificar documento\n";
        setTextColor(RED);
        std::cout << "4.";
        resetColor();
         std::cout <<" Eliminar documento\n";
        setTextColor(RED);
        std::cout << "5.";
        resetColor();
         std::cout <<" Mostrar documentos desde el archivo\n";
        setTextColor(RED);
        std::cout << "6.";
        resetColor();
         std::cout <<" Volver al menu principal\n";  // Opción para volver al menú principal
        setTextColor(YELLOW);
        std::cout << "Elija una opcion: ";
        resetColor();
        std::cin >> opcion;

        switch(opcion) {
            case 1: {
                int buscarOpcion = 0;
                setTextColor(YELLOW);
                std::cout << "\n*** Opciones de Busqueda ***\n";
                resetColor();
                setTextColor(GREEN);
                std::cout << "1.";
                resetColor();
                std::cout <<" Buscar por Nombre\n";
                setTextColor(GREEN);
                std::cout << "2.";
                resetColor();
                std::cout <<" Buscar por ID\n";
                setTextColor(GREEN);
                std::cout << "3.";
                resetColor();
                std::cout <<" Buscar por Fecha\n";
                setTextColor(GREEN);
                std::cout << "4.";
                resetColor();
                std::cout <<" Buscar por Tipo\n";
                setTextColor(YELLOW);
                std::cout << "Elija una opcion: ";
                resetColor();
                std::cin >> buscarOpcion;

                switch(buscarOpcion) {
                    case 1: {
                        char nombre[100];
                        std::cout << "Ingrese el nombre del documento: ";
                        std::cin >> nombre;
                        controlador.buscarPorNombre(nombre);
                        break;
                    }
                    case 2: {
                        int id;
                        std::cout << "Ingrese el ID del documento: ";
                        std::cin >> id;
                        controlador.buscarPorID(id);
                        break;
                    }
                    case 3: {
                        int dia, mes, anio;
                        std::cout << "Ingrese la fecha (dia mes año): ";
                        std::cin >> dia >> mes >> anio;
                        Fecha fecha(dia, mes, anio);
                        controlador.buscarPorFecha(fecha);
                        break;
                    }
                    case 4: {
                        char tipo[100];
                        std::cout << "Ingrese el tipo del documento: ";
                        std::cin >> tipo;
                        controlador.buscarPorTipo(tipo);
                        break;
                    }
                    default:
                        std::cout << "Opcion no valida.\n";
                        break;
                }
                break;
            }
            case 2: {
                char tipo[100], titulo[100];
                int id, dia, mes, anio;
                std::cout << "Ingrese el tipo del documento: ";
                std::cin >> tipo;
                std::cout << "Ingrese el ID del documento: ";
                std::cin >> id;
                std::cout << "Ingrese la fecha (dia mes año): ";
                std::cin >> dia >> mes >> anio;
                Fecha fecha(dia, mes, anio);
                std::cout << "Ingrese el titulo del documento: ";
                std::cin >> titulo;

                Documentos* nuevoArreglo = new Documentos[cantidadDocumentos + 1];  
                for (int i = 0; i < cantidadDocumentos; ++i) {
                    nuevoArreglo[i] = documentos[i];
                }
                nuevoArreglo[cantidadDocumentos] = Documentos(tipo, id, fecha, titulo);  

                delete[] documentos; 
                documentos = nuevoArreglo; 

                cantidadDocumentos++; 

                controlador.agregarDocumento(tipo, id, fecha, titulo);
                std::cout << "Documento agregado exitosamente.\n";
                break;
            }
            case 3: {
                int id;
                std::cout << "Ingrese el ID del documento a modificar: ";
                std::cin >> id;
                controlador.modificarDocumento(id);
                break;
            }
            case 4: {
                int id;
                std::cout << "Ingrese el ID del documento a eliminar: ";
                std::cin >> id;
                controlador.eliminarDocumento(id);
                std::cout << "Documento eliminado exitosamente.\n";
                break;
            }
            case 5: {
                std::cout << "\nDocumentos desde el archivo:\n";
                controlador.mostrarDocumentosDesdeArchivo(nombreArchivo);
                break;
            }
            case 6: {
                std::cout << "Volviendo al menu principal...\n";
                return;  // Esto hará que el flujo vuelva al método principal de menú
            }
            default:
                std::cout << "Opcion no válida. Intente de nuevo.\n";
                break;
        }
    }
}
