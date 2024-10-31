#include <iostream>
#include "abogado.hpp"

Abogado::Abogado(double _salario, const char _puesto[50], const char _nombre[50], const char _apellido[50], 
                 int _ID_Empleado, const char _telefono[15], const char _gmail[50], 
                 int _fecha_contratacion, const char _especialidad[50]) 
{
    salario = _salario;
	
    for (int i = 0; i < 50 && _puesto[i] != '\0'; ++i) 
	{
        puesto[i] = _puesto[i];
    }
    puesto[49] = '\0'; 

    for (int i = 0; i < 50 && _nombre[i] != '\0'; ++i) 
	{
        nombre[i] = _nombre[i];
    }
    nombre[49] = '\0';

    for (int i = 0; i < 50 && _apellido[i] != '\0'; ++i) 
	{
        apellido[i] = _apellido[i];
    }
    apellido[49] = '\0';

    ID_Empleado = _ID_Empleado;

    for (int i = 0; i < 15 && _telefono[i] != '\0'; ++i) 
	{
        telefono[i] = _telefono[i];
    }
    telefono[14] = '\0';

    for (int i = 0; i < 50 && _gmail[i] != '\0'; ++i) 
	{
        gmail[i] = _gmail[i];
    }
    gmail[49] = '\0';

    fecha_contratacion = _fecha_contratacion;

    for (int i = 0; i < 50 && _especialidad[i] != '\0'; ++i) 
	{
        especialidad[i] = _especialidad[i];
    }
    especialidad[49] = '\0';
}

void Abogado::mostrarDatos() 
{
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Apellido: " << apellido << std::endl;
    std::cout << "Salario: $" << salario << std::endl;
    std::cout << "Puesto: " << puesto << std::endl;
    std::cout << "ID Empleado: " << ID_Empleado << std::endl;
    std::cout << "Telefono: " << telefono << std::endl;
    std::cout << "Gmail: " << gmail << std::endl;
    std::cout << "Fecha de contratacion: " << fecha_contratacion << std::endl;
    std::cout << "Especialidad: " << especialidad << std::endl;
}





/* idea para punteros planificacion
Abogado::Abogado(double* _salario, char* _puesto, char* _nombre, char* _apellido, 
                 int* _ID_Empleado, char* _telefono, char* _gmail, 
                 int* _fecha_contratacion, char* _especialidad) 
{
    puesto = _puesto;   
    nombre = _nombre;       
    apellido = _apellido;   
    ID_Empleado = _ID_Empleado;
    telefono = _telefono;
    gmail = _gmail;
    fecha_contratacion = _fecha_contratacion;
    especialidad = _especialidad;
}

Abogado::~Abogado()
{
    delete[] salario;
    delete[] puesto;
    delete[] nombre;
    delete[] apellido;
    delete[] ID_Empleado;
    delete[] telefono;
    delete[] gmail;
    delete[] fecha_contratacion;
    delete[] especialidad;
}

int c_Longitud(char* ptm) 
{
    int longitud = 0;
    while (ptm[longitud] != '\0') 
    {
        longitud++;
    }
    return longitud;
}

void Abogado::setSalario(double* _salario)
{
    salario = _salario;
    std::cout << "Ingrese el salario: ";
    std::cin >> *_salario;
}
void Abogado::setPuesto(char* _puesto)
{
    puesto = _puesto;
    std::cout << "Ingrese el puesto: ";
    std::cin >> *_puesto;
}
void Abogado::setNombre(char* _nombre)
{
    nombre = _nombre;
    std::cout << "Ingrese el nombre: ";
    std::cin >> *_nombre;
}
void Abogado::setApellido(char* _apellido)
{
    apellido = _apellido;
    std::cout << "Ingrese el apellido: ";
    std::cin >> *_apellido;
}
void Abogado::setID_Empleado(int* _ID_Empleado)
{
    
    ID_Empleado = _ID_Empleado;
    std::cout << "Ingrese el ID del empleado: ";
    std::cin >> *_ID_Empleado;
}
void Abogado::setTelefono(char* _telefono)
{
    telefono = _telefono;
    std::cout << "Ingrese el telefono: ";
    std::cin >> *_telefono;

}
void Abogado::setGmail(char* _gmail)
{
    gmail = _gmail;
    std::cout << "Ingrese el gmail: ";
    std::cin >> *_gmail;
}
void Abogado::setFechaContratacion(int* _fecha_contratacion)
{
    fecha_contratacion = _fecha_contratacion;
    std::cout << "Ingrese la fecha de contratacion: ";
    std::cin >> *_fecha_contratacion;
}
void Abogado::setEspecialidad(char* _especialidad)
{
    especialidad = _especialidad;
    std::cout << "Ingrese la especialidad: ";
    std::cin >> *_especialidad;
}

void Abogado::mostrarDatos()
{
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Apellido: " << apellido << std::endl;
    std::cout << "Salario: " << salario << std::endl;
    std::cout << "Puesto: " << puesto << std::endl;
    std::cout << "ID Empleado: " << ID_Empleado << std::endl;
    std::cout << "Telefono: " << telefono << std::endl;
    std::cout << "Gmail: " << gmail << std::endl;
    std::cout << "Fecha de contratacion: " << *fecha_contratacion << std::endl;
    std::cout << "Especialidad: " << especialidad << std::endl;
}
*/