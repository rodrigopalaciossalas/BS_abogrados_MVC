// Persona.cpp
#include "Persona.hpp"

Persona::Persona(const char* nombres, const char* apellidos, const char* telefono,
                 const char* correo, int edad)
    : edad(edad)
{
    A_puntero::copiarCadena(this->nombres, nombres);
    A_puntero::copiarCadena(this->apellidos, apellidos);
    A_puntero::copiarCadena(this->telefono, telefono);
    A_puntero::copiarCadena(this->correo, correo);
}

Persona::~Persona() 
{
    if (nombres) 
        delete[] nombres;
    if (apellidos) 
        delete[] apellidos;
    if (telefono) 
        delete[] telefono;
    if (correo) 
        delete[] correo;
}

const char* Persona::getNombres() const { 
    return nombres; 
}

const char* Persona::getApellidos() const { 
    return apellidos; 
}

const char* Persona::getTelefono() const { 
    return telefono; 
}

const char* Persona::getCorreo() const { 
    return correo; 
}

void Persona::setNombres(const char* nombres) {
    A_puntero::copiarCadena(this->nombres, nombres);
}

void Persona::setApellidos(const char* apellidos) {
    A_puntero::copiarCadena(this->apellidos, apellidos);
}

void Persona::setTelefono(const char* telefono) {
    A_puntero::copiarCadena(this->telefono, telefono);
}

void Persona::setCorreo(const char* correo) {
    A_puntero::copiarCadena(this->correo, correo);
}
