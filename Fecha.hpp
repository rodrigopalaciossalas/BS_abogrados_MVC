#ifndef FECHA_HPP
#define FECHA_HPP

#include <iostream>

class Fecha {
public:
    int dia;
    int mes;
    int anio;

    Fecha() : dia(1), mes(1), anio(2000) {}
    Fecha(int d, int m, int a);

    void imprimirFecha() const;
};

#endif
