#include "DocumentosModel.hpp"

Documentos::Documentos() 
    : numero_id(0), fecha_creacion(Fecha()), tipo(nullptr), titulo(nullptr) {
}

Documentos::Documentos(const char* t, int id, Fecha fecha, const char* tit)
    : numero_id(id), fecha_creacion(fecha) {

    int i = 0;
    while (t[i] != '\0') ++i;
    tipo = new char[i + 1];
    for (int j = 0; j < i; ++j) tipo[j] = t[j];
    tipo[i] = '\0';

    i = 0;
    while (tit[i] != '\0') ++i;
    titulo = new char[i + 1];
    for (int j = 0; j < i; ++j) titulo[j] = tit[j];
    titulo[i] = '\0';
}

Documentos::~Documentos() {
    delete[] tipo;
    delete[] titulo;
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

void Documentos::setTipo(const char* t) {
    delete[] tipo;
    int i = 0;
    while (t[i] != '\0') ++i;
    tipo = new char[i + 1];
    for (int j = 0; j < i; ++j) tipo[j] = t[j];
    tipo[i] = '\0';
}

void Documentos::setID(int id) {
    numero_id = id;
}

void Documentos::setFecha(Fecha fecha) {
    fecha_creacion = fecha;
}

void Documentos::setTitulo(const char* tit) {
    delete[] titulo;
    int i = 0;
    while (tit[i] != '\0') ++i;
    titulo = new char[i + 1];
    for (int j = 0; j < i; ++j) titulo[j] = tit[j];
    titulo[i] = '\0';
}
