#include "DocumentosController.hpp"
#include <iostream>

DocumentosController::DocumentosController(Documentos* docs, int count)
    : documentos(docs), docCount(count) {}

bool DocumentosController::compararCadenas(const char* str1, const char* str2) const {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) return false;
        ++i;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

void DocumentosController::guardarDocumentosEnArchivo(const char* nombreArchivo) const {
    std::ofstream archivo(nombreArchivo, std::ios::app);
    if (!archivo) {
        std::cout << "Error al abrir el archivo para guardar." << std::endl;
        return;
    }
    for (int i = 0; i < docCount; ++i) {
        archivo << "Titulo: " << documentos[i].getTitulo() << std::endl;
        archivo << "ID: " << documentos[i].getID() << std::endl;
        archivo << "Fecha de Creacion: " << documentos[i].getFecha().dia << "-" 
                << documentos[i].getFecha().mes << "-" << documentos[i].getFecha().anio << std::endl;
        archivo << "Tipo: " << documentos[i].getTipo() << std::endl;
        archivo << "------------------------" << std::endl;
    }
    archivo.close();
}

void DocumentosController::mostrarDocumentosDesdeArchivo(const char* nombreArchivo) const {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cout << "Error al abrir el archivo para leer." << std::endl;
        return;
    }

    char* linea = new char[256];

    while (archivo.getline(linea, 256)) {
        std::cout << linea << std::endl;
    }

    delete[] linea;
    archivo.close();
}

void DocumentosController::buscarPorNombre(const char* name) const {
    for (int i = 0; i < docCount; ++i) {
        if (compararCadenas(documentos[i].getTitulo(), name)) {
            vista.mostrarDocumentos(documentos[i]);
            return;
        }
    }
    std::cout << "Documento no encontrado." << std::endl;
}

void DocumentosController::buscarPorID(int id) const {
    for (int i = 0; i < docCount; ++i) {
        if (documentos[i].getID() == id) {
            vista.mostrarDocumentos(documentos[i]);
            return;
        }
    }
    std::cout << "Documento no encontrado." << std::endl;
}

void DocumentosController::buscarPorFecha(Fecha fecha) const {
    for (int i = 0; i < docCount; ++i) {
        if (documentos[i].getFecha().dia == fecha.dia &&
            documentos[i].getFecha().mes == fecha.mes &&
            documentos[i].getFecha().anio == fecha.anio) {
            vista.mostrarDocumentos(documentos[i]);
            return;
        }
    }
    std::cout << "Documento no encontrado." << std::endl;
}

void DocumentosController::buscarPorTipo(const char* tipo) const {
    for (int i = 0; i < docCount; ++i) {
        if (compararCadenas(documentos[i].getTipo(), tipo)) {
            vista.mostrarDocumentos(documentos[i]);
            return;
        }
    }
    std::cout << "Documento no encontrado." << std::endl;
}

void DocumentosController::agregarDocumento(const char* tipo, int id, Fecha fecha, const char* titulo) {
    documentos[docCount] = Documentos(tipo, id, fecha, titulo);
    ++docCount;
    guardarDocumentosEnArchivo("documentos.txt");
}

void DocumentosController::modificarDocumento(int id) {
    for (int i = 0; i < docCount; ++i) {
        if (documentos[i].getID() == id) {
            int opcion;
            std::cout << "Modificar:\n1. Tipo\n2. ID\n3. Fecha\n4. Titulo\n";
            std::cin >> opcion;

            if (opcion == 1) {
                char nuevoTipo[100];
                std::cout << "Nuevo tipo: ";
                std::cin >> nuevoTipo;
                documentos[i].setTipo(nuevoTipo);
            } else if (opcion == 2) {
                int nuevoID;
                std::cout << "Nuevo ID: ";
                std::cin >> nuevoID;
                documentos[i].setID(nuevoID);
            } else if (opcion == 3) {
                int dia, mes, anio;
                std::cout << "Nueva fecha (dia mes anio): ";
                std::cin >> dia >> mes >> anio;
                documentos[i].setFecha(Fecha(dia, mes, anio));
            } else if (opcion == 4) {
                char nuevoTitulo[100];
                std::cout << "Nuevo titulo: ";
                std::cin >> nuevoTitulo;
                documentos[i].setTitulo(nuevoTitulo);
            }
            guardarDocumentosEnArchivo("documentos.txt");
            return;
        }
    }
    std::cout << "Documento no encontrado.\n";
}

void DocumentosController::eliminarDocumento(int id) {
    for (int i = 0; i < docCount; ++i) {
        if (documentos[i].getID() == id) {
            for (int j = i; j < docCount - 1; ++j) {
                documentos[j] = documentos[j + 1];
            }
            --docCount;
            guardarDocumentosEnArchivo("documentos.txt");
            return;
        }
    }
    std::cout << "Documento no encontrado.\n";
}