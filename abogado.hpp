#ifndef ABOGADO_HPP
#define ABOGADO_HPP

#include "Persona.hpp"
#include "Fecha.hpp"
#include "id.hpp"
class Abogado : public Persona 
{
private:
    char* especialidad;
    double salario;
    char* puesto;
    char* gmail;
    Fecha fechaContratacion;
    int id;


public:
    Abogado(const char* _nombre, const char* _apellido, const char* _telefono, const char* _correo, int _edad,
            const char* _especialidad, double _salario, const char* _puesto, const char* _gmail, 
            int dia, int mes, int anio);
    ~Abogado();

    void setEspecialidad(const char* _especialidad);
    void setSalario(double _salario);
    void setPuesto(const char* _puesto);
    void setGmail(const char* _gmail);
    void setFechaContratacion(int dia, int mes, int anio);

    const char* getEspecialidad() const;
    double getSalario() const;
    const char* getPuesto() const;
    const char* getGmail() const;
    Fecha getFechaContratacion() const;
    int obtenerID() const;
    
    void setID(int nuevoID) {
        id = nuevoID;
    }
};

#endif // ABOGADO_HPP
