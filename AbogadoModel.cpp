#include "AbogadoModel.hpp"
#include <iostream>

Abogado::Abogado(const char* _nombre, const char* _apellido, const char* _telefono, const char* _especialidad, double _salario, const char* _puesto, const char* _gmail, int dia, int mes, int anio)
    : fechaContratacion(dia, mes, anio), salario(_salario), id(1) // ID asignado como ejemplo
{
    nombre = nullptr;
    apellido = nullptr;
    telefono = nullptr;
    especialidad = nullptr;
    puesto = nullptr;
    gmail = nullptr;

    puntero.copiarCadena(nombre, _nombre);
    puntero.copiarCadena(apellido, _apellido);
    puntero.copiarCadena(telefono, _telefono);
    puntero.copiarCadena(especialidad, _especialidad);
    puntero.copiarCadena(puesto, _puesto);
    puntero.copiarCadena(gmail, _gmail);
}

Abogado::~Abogado() 
{
    if (nombre != nullptr)
    {
		delete[] nombre;
	}
    if (apellido != nullptr)
    {
        delete[] apellido;
    }
    if (telefono != nullptr)
    {
        delete[] telefono;
    }
    if (especialidad != nullptr)
    {
        delete[] especialidad;
    }
    if (puesto != nullptr)
    {
        delete[] puesto;
    }
    if (gmail != nullptr)
    {
        delete[] gmail;
    }
}

void Abogado::setNombre(const char* _nombre) 
{ 
    puntero.copiarCadena(nombre, _nombre); 
}
void Abogado::setApellido(const char* _apellido) 
{ 
    puntero.copiarCadena(apellido, _apellido); 
}
void Abogado::setTelefono(const char* _telefono) 
{ 
    puntero.copiarCadena(telefono, _telefono); 
}
void Abogado::setEspecialidad(const char* _especialidad) 
{ 
    puntero.copiarCadena(especialidad, _especialidad); 
}
void Abogado::setSalario(double _salario) 
{
     salario = _salario;
}
void Abogado::setPuesto(const char* _puesto) 
{
     puntero.copiarCadena(puesto, _puesto); 
}
void Abogado::setGmail(const char* _gmail) 
{
     puntero.copiarCadena(gmail, _gmail); 
}
void Abogado::setFechaContratacion(int dia, int mes, int anio) 
{
     fechaContratacion = Fecha(dia, mes, anio); 
}

const char* Abogado::getNombre() const 
{
     return nombre; 
}
const char* Abogado::getApellido() const 
{ 
    return apellido;
}
const char* Abogado::getTelefono() const 
{
     return telefono; 
}
const char* Abogado::getEspecialidad() const 
{
     return especialidad; 
}
double Abogado::getSalario() const 
{
     return salario; 
}
const char* Abogado::getPuesto() const 
{ 
    return puesto; 
}
const char* Abogado::getGmail() const 
{
     return gmail; 
}
Fecha Abogado::getFechaContratacion() const 
{ 
    return fechaContratacion; 
}
int Abogado::obtenerID() const 
{ 
    return id; 
}

void Abogado::imprimirCadena(const char* cadena) 
{
    puntero.imprimirCadena(cadena);  // Llamada al miembro de A_puntero
}
