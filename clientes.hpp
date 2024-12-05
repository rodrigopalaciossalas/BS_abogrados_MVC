
#ifndef CLIENTES_HPP
#define CLIENTES_HPP

#include "Persona.hpp"
#include <fstream>

class Clientes : public Persona {
private:
    int ID;
    char* direccion;
    char* profesion;

public:
    Clientes(const char* _nombres, const char* _apellidos, const char* _telefono, const char* _correo,
             int edad, int ID, const char* _direccion, const char* _profesion);
    ~Clientes();

    const char* getDireccion() const;
    const char* getProfesion() const;
    const int getID() const;

    void setDireccion(const char* _direccion);
    void setProfesion(const char* _profesion);
    int getEdad() const;
    void guardarEnArchivo(std::ofstream& archivo) const;
    void mostrarInformacion() const;

    static void mostrarClientes(const char* nombreArchivo);
    static void buscarCliente(const char* nombreArchivo, int id);
    void registrarCliente(std::ofstream& archivo);
};

#endif 
