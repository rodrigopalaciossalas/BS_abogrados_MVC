#ifndef DOCUMENTOS_MODEL_HPP
#define DOCUMENTOS_MODEL_HPP

#include "Fecha.hpp"
#include <fstream>

class Documentos {
private:
    char* tipo;
    int numero_id;
    Fecha fecha_creacion;
    char* titulo;

public:
    Documentos();
    Documentos(const char* t, int id, Fecha fecha, const char* tit);

    virtual ~Documentos();

    const char* getTipo() const;
    int getID() const;
    Fecha getFecha() const;
    const char* getTitulo() const;

    void setTipo(const char* t);
    void setID(int id);
    void setFecha(Fecha fecha);
    void setTitulo(const char* tit);
};

#endif
