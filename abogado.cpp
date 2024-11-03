#include <iostream>
#include "Abogado.hpp"
#include "ID.hpp"
#include "Fecha.hpp"

// Función para calcular la longitud de una cadena
int c_Longitud(const char* ptm) 
{
    int longitud = 0;
    while (ptm[longitud] != '\0') 
    {
        longitud++;
    }
    return longitud;
}

// Función  para copiar cadenas
void copiarCadena(char*& destino, const char* origen) 
{
    delete[] destino; // Liberar memoria no se bien si esta implementacion es correcta
    destino = new char[c_Longitud(origen) + 1];
    for (int i = 0; i < c_Longitud(origen); ++i) 
    {
        destino[i] = origen[i];
    }
    destino[c_Longitud(origen)] = '\0';
}

// Constructor
Abogado::Abogado(const char* _nombre, const char* _apellido, const char* _telefono, 
                 const char* _especialidad, double _salario, const char* _puesto, 
                 const char* _gmail, int dia, int mes, int anio) : fechaContratacion(dia, mes, anio), salario(_salario)
{
    copiarCadena(nombre, _nombre);
    copiarCadena(apellido, _apellido);
    copiarCadena(telefono, _telefono);
    copiarCadena(especialidad, _especialidad);
    copiarCadena(puesto, _puesto);
    copiarCadena(gmail, _gmail);
}

// Destructor
Abogado::~Abogado()
{
    delete[] nombre;
    delete[] apellido;
    delete[] telefono;
    delete[] especialidad;
    delete[] puesto;
    delete[] gmail;
}

// Métodos void
void Abogado::mostrarDatos() 
{
    std::cout << "ID: Abg." << id_abogado.obtenerID()
              << "Nombre: " << nombre << "\nApellido: " << apellido
              << "\nTelefono: " << telefono << "\nEspecialidad: " << especialidad
              << "\nSalario: " << salario << "\nPuesto: " << puesto 
              << "\nGmail: " << gmail << "\nFecha de contratacion: ";
    fechaContratacion.imprimirFecha(); 
}

void Abogado::setSalario(double _salario) 
{
    salario = _salario;
}

void Abogado::setPuesto(const char* _puesto) 
{
    copiarCadena(puesto, _puesto);
}

void Abogado::setNombre(const char* _nombre) 
{
    copiarCadena(nombre, _nombre);
}

void Abogado::setApellido(const char* _apellido) 
{
    copiarCadena(apellido, _apellido);
}

void Abogado::setTelefono(const char* _telefono) 
{
    copiarCadena(telefono, _telefono);
}

void Abogado::setGmail(const char* _gmail) 
{
    copiarCadena(gmail, _gmail);
}

void Abogado::setEspecialidad(const char* _especialidad) 
{
    copiarCadena(especialidad, _especialidad);
}

void Abogado::Abogado_datos_obligatorios()
{
    std::cout << "Ingrese el nombre del abogado: ";
    std::cin.getline(nombre, 100);

    std::cout << "Ingrese el apellido del abogado: ";
    std::cin.getline(apellido, 100);

    std::cout << "Ingrese el telefono del abogado: ";
    std::cin.getline(telefono, 100);


    std::cout << "Ingrese el puesto del abogado: ";
    std::cin.ignore();  
    std::cin.getline(puesto, 100);

    int dia, mes, anio;
    std::cout << "Ingrese la fecha de contratación (dia mes anio): ";
    std::cin >> dia >> mes >> anio;

}
void Abogado::Abogado_datos_opcionales()
{
    int eleccion;
    std::cout << "Ingrese el dato que desea modificar: \n";
    std::cout << "1. Gmail\n";
    std::cout << "2. Salario\n";
    std::cout << "3. Especialidad\n";
    std::cin >> eleccion;

  if (eleccion == 1)
  {
    std::cout << "Ingrese el gmail del abogado (opcional): ";
    std::cin.ignore();  
    std::cin.getline(gmail, 100);
  }
 else if (eleccion == 2)
    {
    std::cout << "Ingrese el salario del abogado: ";
    std::cin >> salario;
    }
    else if (eleccion == 3)
    {
    std::cout << "Ingrese la especialidad del abogado: ";
    std::cin.ignore();
    std::cin.getline(especialidad, 100);
    }
}

//codigo comentado para referencia
/**
int c_Longitud(const char* ptm) 
{
    int longitud = 0;
    while (ptm[longitud] != '\0') 
    {
        longitud++;
    }
    return longitud;
}

// Constructor
Abogado::Abogado(const char* _nombre, const char* _apellido, const char* _telefono, 
                 const char* _especialidad, double _salario, const char* _puesto, 
                 const char* _gmail, int dia, int mes, int anio) 
    : fechaContratacion(dia, mes, anio)
{
    // Asignación de memoria para cadenas
    nombre = new char[c_Longitud(_nombre) + 1];
    apellido = new char[c_Longitud(_apellido) + 1];
    telefono = new char[c_Longitud(_telefono) + 1];
    especialidad = new char[c_Longitud(_especialidad) + 1];
    puesto = new char[c_Longitud(_puesto) + 1];
    gmail = new char[c_Longitud(_gmail) + 1];
    salario = _salario;

    // Copia de datos
    for (int i = 0; i < c_Longitud(_nombre); ++i) {
        nombre[i] = _nombre[i];
    }
    nombre[c_Longitud(_nombre)] = '\0';

    for (int i = 0; i < c_Longitud(_apellido); ++i) {
        apellido[i] = _apellido[i];
    }
    apellido[c_Longitud(_apellido)] = '\0';

    for (int i = 0; i < c_Longitud(_telefono); ++i) {
        telefono[i] = _telefono[i];
    }
    telefono[c_Longitud(_telefono)] = '\0';

    for (int i = 0; i < c_Longitud(_especialidad); ++i) {
        especialidad[i] = _especialidad[i];
    }
    especialidad[c_Longitud(_especialidad)] = '\0';

    for (int i = 0; i < c_Longitud(_puesto); ++i) {
        puesto[i] = _puesto[i];
    }
    puesto[c_Longitud(_puesto)] = '\0';

    for (int i = 0; i < c_Longitud(_gmail); ++i) {
        gmail[i] = _gmail[i];
    }
    gmail[c_Longitud(_gmail)] = '\0';
}

// Destructor
Abogado::~Abogado()
{
    delete[] nombre;
    delete[] apellido;
    delete[] telefono;
    delete[] especialidad;
    delete[] puesto;
    delete[] gmail;
}

// Métodos void

void Abogado::mostrarDatos() 
{
    std::cout << "Nombre: " << nombre << "\nApellido: " << apellido 
              << "\nTelefono: " << telefono << "\nEspecialidad: " << especialidad 
              << "\nSalario: " << salario << "\nPuesto: " << puesto 
              << "\nGmail: " << gmail << "\nFecha de contratacion: ";
            fechaContratacion.imprimirFecha();
}

void Abogado::setSalario(double _salario) 
{
    salario = _salario;
}

void Abogado::setPuesto(const char* _puesto) 
{
    delete[] puesto;
    puesto = new char[c_Longitud(_puesto) + 1];
    for (int i = 0; i < c_Longitud(_puesto); ++i) {
        puesto[i] = _puesto[i];
    }
    puesto[c_Longitud(_puesto)] = '\0';
}

void Abogado::setNombre(const char* _nombre) 
{
    delete[] nombre;
    nombre = new char[c_Longitud(_nombre) + 1];
    for (int i = 0; i < c_Longitud(_nombre); ++i) {
        nombre[i] = _nombre[i];
    }
    nombre[c_Longitud(_nombre)] = '\0';
}

void Abogado::setApellido(const char* _apellido) 
{
    delete[] apellido;
    apellido = new char[c_Longitud(_apellido) + 1];
    for (int i = 0; i < c_Longitud(_apellido); ++i) {
        apellido[i] = _apellido[i];
    }
    apellido[c_Longitud(_apellido)] = '\0';
}

void Abogado::setIDEmpleado(int _ID_Empleado) 
{
    ID_Empleado = _ID_Empleado;
}

void Abogado::setTelefono(const char* _telefono) 
{
    delete[] telefono;
    telefono = new char[c_Longitud(_telefono) + 1];
    for (int i = 0; i < c_Longitud(_telefono); ++i) {
        telefono[i] = _telefono[i];
    }
    telefono[c_Longitud(_telefono)] = '\0';
}

void Abogado::setGmail(const char* _gmail) 
{
    delete[] gmail;
    gmail = new char[c_Longitud(_gmail) + 1];
    for (int i = 0; i < c_Longitud(_gmail); ++i) {
        gmail[i] = _gmail[i];
    }
    gmail[c_Longitud(_gmail)] = '\0';
}

void Abogado::setEspecialidad(const char* _especialidad) 
{
    delete[] especialidad;
    especialidad = new char[c_Longitud(_especialidad) + 1];
    for (int i = 0; i < c_Longitud(_especialidad); ++i) {
        especialidad[i] = _especialidad[i];
    }
    especialidad[c_Longitud(_especialidad)] = '\0';
}

**/
/*
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
*/