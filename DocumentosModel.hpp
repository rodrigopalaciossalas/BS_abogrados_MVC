#ifndef DOCUMENTOS_MODEL_HPP
#define DOCUMENTOS_MODEL_HPP

#include "Fecha.hpp"

class Documentos {
public:
    char tipo[50];
    int numero_id;
    Fecha fecha_creacion;
    char titulo[50];

    Documentos(const char* t, int id, Fecha fecha, const char* tit);
    
    const char* getTipo() const;
    int getID() const;
    Fecha getFecha() const;
    const char* getTitulo() const;
};

#endif
