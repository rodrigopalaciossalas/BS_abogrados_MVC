#ifndef ABOGADO_MODEL_HPP
#define ABOGADO_MODEL_HPP

#include "Fecha.hpp"
#include "A_punteros.hpp"  // Incluir la clase A_puntero

class Abogado 
{
private: 
    char* nombre;
    char* apellido;
    char* telefono;
    char* especialidad;
    double salario;
    char* puesto;
    char* gmail;
    Fecha fechaContratacion;
    int id;
    A_puntero puntero;  // Miembro de tipo A_puntero para manejar cadenas
public:
    Abogado(const char* _nombre, const char* _apellido, const char* _telefono, const char* _especialidad, double _salario, const char* _puesto, const char* _gmail, int dia, int mes, int anio);
    ~Abogado();

    void setNombre(const char* _nombre);
    void setApellido(const char* _apellido);
    void setTelefono(const char* _telefono);
    void setEspecialidad(const char* _especialidad);
    void setSalario(double _salario);
    void setPuesto(const char* _puesto);
    void setGmail(const char* _gmail);
    void setFechaContratacion(int dia, int mes, int anio);

    const char* getNombre() const;
    const char* getApellido() const;
    const char* getTelefono() const;
    const char* getEspecialidad() const;
    double getSalario() const;
    const char* getPuesto() const;
    const char* getGmail() const;
    Fecha getFechaContratacion() const;
    int obtenerID() const;

    void imprimirCadena(const char* cadena);
};

#endif // ABOGADO_MODEL_HPP
