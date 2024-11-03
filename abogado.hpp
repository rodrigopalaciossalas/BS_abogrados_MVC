#ifndef ABOGADO_HPP
#define ABOGADO_HPP
#include "ID.hpp"
#include "Fecha.hpp"
#include <iostream>

class Abogado
{
    public:
        // Datos principales de la clase Abogado
        char* nombre;
        char* apellido;
        char* telefono;
        Fecha fechaContratacion;  
        ID id_abogado; 
        // Datos secundarios de la clase
        double salario;  
        char* puesto;
        char* gmail;
        char* especialidad;

        // Métodos de entrada de datos
        void mostrarDatos();
        void setSalario(double _salario);
        void setPuesto(const char* _puesto);
        void setNombre(const char* _nombre);
        void setApellido(const char* _apellido);
        void setIDEmpleado(int _ID_Empleado);
        void setTelefono(const char* _telefono);
        void setGmail(const char* _gmail);
        void setEspecialidad(const char* _especialidad);

        // Constructor
        Abogado(const char* _nombre, const char* _apellido, const char* _telefono, const char* _especialidad,
                double _salario, const char* _puesto, const char* _gmail, 
                int dia, int mes, int anio);

        // Destructor
        ~Abogado();
};

#endif // ABOGADO_HPP
/*
class Abogado 
{
    public:
        double salario;          
        char puesto[50];         
        char nombre[50];         
        char apellido[50];      
        int ID_Empleado;         
        char telefono[15];       
        char gmail[50];          
        int fecha_contratacion;  
        char especialidad[50]; 

        // Constructor
        Abogado(double salario, const char puesto[50], const char nombre[50], const char apellido[50], 
                int ID_Empleado, const char telefono[15], const char gmail[50], 
                int fecha_contratacion, const char especialidad[50]);

        // Método para mostrar datos
        void mostrarDatos();
};
*/
