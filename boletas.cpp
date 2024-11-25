#include "Boletas.hpp"

Boletas::Boletas() : Economia(), monto(0.0f) 
{}

Boletas::Boletas(int id, const char* descripcion, float monto)
    : Economia(id, descripcion), monto(monto) 
{}

void Boletas::guardarEnArchivo(std::ostream& out) const 
{
    out << id << " " << descripcion << " " << monto << "\n";
}

void Boletas::cargarDeArchivo(std::istream& in) 
{
    in >> id >> descripcion >> monto;
}

void Boletas::mostrarDatos() const 
{
    std::cout << "ID: " << id << ", Descripción: " << descripcion
              << ", Monto: " << monto << "\n";
}
