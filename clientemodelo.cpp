#include <iostream>
#include "clientemodelo.hpp"

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif


ClienteModelo::ClienteModelo(const char* _nombre, const char* _apellido, const char* _telefono, const char* _email) {
	puntero.copiarCadena(nombre, _nombre);
	puntero.copiarCadena(apellido, _apellido);
    puntero.copiarCadena(telefono, _telefono);
    puntero.copiarCadena(email, _email); 
}

ClienteModelo::~ClienteModelo(){
	
    delete[] nombre;
	delete[] apellido;
    delete[] telefono;
    delete[] email;
}

    const char* getNombre() const { 
		return nombre; 
		}
		
	const char* getApellido() const { 
		return apellido; 
		}
		
	const char* getTelefono() const { 
		return telefono; 
		}
		
    const char* getEmail() const { 
		return email; 
		}
		
		

    void ClienteModelo::setNombre(const char* _nombre) {
        copiarCadena(nombre, _nombre);
    }
	
	void ClienteModelo::setNombre(const char* _apellido) {
        copiarCadena(nombre, _apellido);
    }
	
	void ClienteModelo::setNombre(const char* _telefono) {
        copiarCadena(nombre, _telefono);
    }

    void ClienteModelo::setEmail(const char* _email) {
        copiarCadena(email, _email);
    }
};