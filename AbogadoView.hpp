#ifndef ABOGADO_VIEW_HPP
#define ABOGADO_VIEW_HPP

#include "AbogadoModel.hpp"

class AbogadoView {
public:
    void mostrarDatos( Abogado& abogado);
    void solicitarEntrada(const char* mensaje, char* entrada, int longitud);
    int solicitarFecha(const char* mensaje);
};

#endif // ABOGADO_VIEW_HPP
