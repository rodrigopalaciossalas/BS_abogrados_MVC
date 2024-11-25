#include "Facturas.hpp"

Facturas::Facturas() : Economia(), total(0.0f) 
{
    cliente[0] = '\0';
}

Facturas::Facturas(int id, const char* descripcion, float total, const char* cliente)
    : Economia(id, descripcion), total(total) 
    {
    int i = 0;
    while (cliente[i] != '\0' && i < 99) 
    {
        this->cliente[i] = cliente[i];
        i++;
    }
    this->cliente[i] = '\0';
}

void Facturas::guardarEnArchivo(std::ostream& out) const 
{
    out << id << " " << descripcion << " " << total << " " << cliente << "\n";
}

void Facturas::cargarDeArchivo(std::istream& in) 
{
    in >> id >> descripcion >> total >> cliente;
}

void Facturas::mostrarDatos() const 
{
    std::cout << "ID: " << id << ", Descripción: " << descripcion
              << ", Total: " << total << ", Cliente: " << cliente << "\n";
}
