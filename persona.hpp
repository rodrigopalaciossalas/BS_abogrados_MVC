// Persona.hpp
#ifndef PERSONA_HPP
#define PERSONA_HPP

#include "A_punteros.hpp"

class Persona {
private:
    char* nombres;
    char* apellidos;
    char* telefono;
    char* correo;
    int edad;

public:
    void setNombres(const char* nombres);
    void setApellidos(const char* apellidos);
    void setTelefono(const char* telefono);
    void setCorreo(const char* correo);

    Persona(const char* nombres, const char* apellidos, const char* telefono,
            const char* correo, int edad);
    ~Persona();

    // Métodos get públicos para acceder a los atributos heredados
    const char* getNombres() const;
    const char* getApellidos() const;
    const char* getTelefono() const;
    const char* getCorreo() const;
};

#endif

