#include "Documentos.hpp"
#include <iostream>

Documentos::Documentos(const char* t, int id, Fecha fecha, const char* tit)
    : numero_id(id), fecha_creacion(fecha) {
    for (int i = 0; i < 49 && t[i] != '\0'; ++i) {
        tipo[i] = t[i];
    }
    tipo[49] = '\0';

    for (int i = 0; i < 49 && tit[i] != '\0'; ++i) {
        titulo[i] = tit[i];
    }
    titulo[49] = '\0';
}

void Documentos::imprimirDocumento() {
    std::cout << "Titulo: " << titulo << std::endl;
    std::cout << "ID: " << numero_id << std::endl;
    std::cout << "Fecha de Creación: ";
    fecha_creacion.imprimirFecha();
    std::cout << "Tipo: " << tipo << std::endl;
}
