#include "DocumentosController.hpp"

DocumentosController::DocumentosController(Documentos* docs, int count)
    : documentos(docs), docCount(count) {}

bool DocumentosController::compareStrings(const char* str1, const char* str2) const {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        ++i;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

void DocumentosController::searchByName(const char* name) const {
    for (int i = 0; i < docCount; ++i) {
        if (compareStrings(documentos[i].getTitulo(), name)) {
            view.displayDocumentos(documentos[i]);
            return;
        }
    }
    std::cout << "Documento no encontrado." << std::endl;
}

void DocumentosController::searchByID(int id) const {
    for (int i = 0; i < docCount; ++i) {
        if (documentos[i].getID() == id) {
            view.displayDocumentos(documentos[i]);
            return;
        }
    }
    std::cout << "Documento no encontrado." << std::endl;
}

void DocumentosController::searchByDate(Fecha date) const {
    for (int i = 0; i < docCount; ++i) {
        if (documentos[i].getFecha().dia == date.dia &&
            documentos[i].getFecha().mes == date.mes &&
            documentos[i].getFecha().anio == date.anio) {
            view.displayDocumentos(documentos[i]);
            return;
        }
    }
    std::cout << "Documento no encontrado." << std::endl;
}

void DocumentosController::searchByType(const char* type) const {
    for (int i = 0; i < docCount; ++i) {
        if (compareStrings(documentos[i].getTipo(), type)) {
            view.displayDocumentos(documentos[i]);
            return;
        }
    }
    std::cout << "Documento no encontrado." << std::endl;
}
