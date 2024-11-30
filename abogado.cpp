#include "Abogado.hpp"
#include "A_punteros.hpp"

// Constructor
Abogado::Abogado(const char* _nombre, const char* _apellido, const char* _telefono, const char* _correo, int _edad,
                 const char* _especialidad, double _salario, const char* _puesto, const char* _gmail,
                 int dia, int mes, int anio)
    : Persona(_nombre, _apellido, _telefono, _correo, _edad),
      salario(_salario), fechaContratacion(dia, mes, anio), id(0) {
    especialidad = nullptr;
    puesto = nullptr;
    gmail = nullptr;


    A_puntero::copiarCadena(especialidad, _especialidad);
    A_puntero::copiarCadena(puesto, _puesto);
    A_puntero::copiarCadena(gmail, _gmail);

      // Asignación del ID usando la clase ID
    id = ID::generarID(); 

}

// Destructor
Abogado::~Abogado() {
    if (especialidad) delete[] especialidad;
    if (puesto) delete[] puesto;
    if (gmail) delete[] gmail;
}

// Getters
const char* Abogado::getEspecialidad() const {
    return especialidad;
}

double Abogado::getSalario() const {
    return salario;
}

const char* Abogado::getPuesto() const {
    return puesto;
}

const char* Abogado::getGmail() const {
    return gmail;
}

Fecha Abogado::getFechaContratacion() const {
    return fechaContratacion;
}

int Abogado::obtenerID() const {
    return id;
}


// Setters
void Abogado::setEspecialidad(const char* _especialidad) {
    A_puntero::copiarCadena(especialidad, _especialidad);
}

void Abogado::setSalario(double _salario) {
    salario = _salario;
}

void Abogado::setPuesto(const char* _puesto) {
    A_puntero::copiarCadena(puesto, _puesto);
}

void Abogado::setGmail(const char* _gmail) {
    A_puntero::copiarCadena(gmail, _gmail);
}

void Abogado::setFechaContratacion(int dia, int mes, int anio) {
    fechaContratacion = Fecha(dia, mes, anio);
}
