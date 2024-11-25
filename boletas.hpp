#ifndef BOLETAS_HPP
#define BOLETAS_HPP

#include "Economia.hpp"

class Boletas : public Economia 
{
private:
    float monto;

public:
    Boletas();
    Boletas(int id, const char* descripcion, float monto);

    void guardarEnArchivo(std::ostream& out) const override;
    void cargarDeArchivo(std::istream& in) override;
    void mostrarDatos() const override;
};

#endif // BOLETAS_HPP
