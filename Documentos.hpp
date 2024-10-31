#ifndef DOCUMENTOS_HPP
#define DOCUMENTOS_HPP

#include "Fecha.hpp"

class Documentos {
public:
    char tipo[50];
    int numero_id;
    Fecha fecha_creacion;
    char titulo[50];

    Documentos(const char* t, int id, Fecha fecha, const char* tit);
    void imprimirDocumento();
};

#endif 
