#ifndef FECHA_HPP
#define FECHA_HPP

#include <iostream>

class Fecha {
public:
    int dia;
    int mes;
    int anio;

    Fecha(int d, int m, int a);
    void imprimirFecha() const;
};

#endif
