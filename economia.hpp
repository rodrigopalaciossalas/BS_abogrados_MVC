#ifndef ECONOMIA_HPP
#define ECONOMIA_HPP

#include <iostream>
#include "A_punteros.hpp"  // Incluimos la librería A_punteros

class Economia 
{
protected:
    int id;
    char* descripcion;  // Usamos puntero para la descripción

public:
    Economia();
    Economia(int id, const char* descripcion);
    virtual ~Economia();

    int getID() const;
    virtual void guardarEnArchivo(std::ostream& out) const;
    virtual void cargarDeArchivo(std::istream& in);
    virtual void mostrarDatos() const;
};

#endif // ECONOMIA_HPP

