#ifndef FACTURAS_HPP
#define FACTURAS_HPP

#include "Economia.hpp"

class Facturas : public Economia 
{
private:
    float total;
    char cliente[100]; //remplazar con datos de la clase cliente filtrar por ID

public:
    Facturas();
    Facturas(int id, const char* descripcion, float total, const char* cliente);

    void guardarEnArchivo(std::ostream& out) const override;
    void cargarDeArchivo(std::istream& in) override;
    void mostrarDatos() const override;
};

#endif // FACTURAS_HPP
