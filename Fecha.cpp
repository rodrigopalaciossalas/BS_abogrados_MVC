#include "Fecha.hpp"


Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

void Fecha::imprimirFecha() const {
    std::cout << dia << "-" << mes << "-" << anio << std::endl;
}