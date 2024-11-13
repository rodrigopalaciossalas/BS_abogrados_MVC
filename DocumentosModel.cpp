#include "DocumentosModel.hpp"
#include <cstring>

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

const char* Documentos::getTipo() const {
    return tipo;
}

int Documentos::getID() const {
    return numero_id;
}

Fecha Documentos::getFecha() const {
    return fecha_creacion;
}

const char* Documentos::getTitulo() const {
    return titulo;
}
