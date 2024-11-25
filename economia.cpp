#include "Economia.hpp"

Economia::Economia() : id(0), descripcion(nullptr) 
{}

Economia::Economia(int id, const char* descripcion) : id(id) 
{
    if (descripcion) 
    {
        A_puntero::copiarCadena(this->descripcion, descripcion);
    } else 
    {
        this->descripcion = nullptr;
    }
}

Economia::~Economia() 
{
    // Liberamos la memoria dinámica si existe
    if (descripcion != nullptr) 
    {
        delete[] descripcion;
    }
}

int Economia::getID() const 
{
    return id;
}

void Economia::guardarEnArchivo(std::ostream& out) const 
{
    out << id << " ";
    A_puntero::imprimirCadena(descripcion);
}

void Economia::cargarDeArchivo(std::istream& in) 
{
    in >> id;
    // Leemos la descripción con memoria dinámica
    char buffer[1000];  // Usamos un buffer temporal para cargar la descripción
    in >> buffer;
    
    // Usamos A_puntero para copiar la cadena leída
    if (descripcion != nullptr) 
    {
        delete[] descripcion;  // Liberamos cualquier memoria previamente asignada
    }
    A_puntero::copiarCadena(descripcion, buffer);
}

void Economia::mostrarDatos() const 
{
    std::cout << "ID: " << id << ", Descripción: ";
    // Usamos A_puntero para imprimir la cadena
    A_puntero::imprimirCadena(descripcion);
}
