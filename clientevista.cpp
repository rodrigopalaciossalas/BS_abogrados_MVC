#include <iostream>
#include "clientevista.hpp"

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif


    void VistaCliente::mostrarCliente(const Cliente& cliente) {
        std::cout << "Nombre: " << cliente.getNombre() << std::endl;
		std::cout << "Apellido: " << cliente.getApellido() << std::endl;
		std::cout << "Telefono: " << cliente.getTelefono() << std::endl;
        std::cout << "Email: " << cliente.getEmail() << std::endl;
    }

    void VistaCliente::solicitarNombreCliente() {
        std::cout << "Ingrese el nombre del cliente: ";
    }

	void VistaCliente::solicitarApellidoCliente() {
        std::cout << "Ingrese el apellido del cliente: ";
    }
	
	void VistaCliente::solicitarTelefonoCliente() {
        std::cout << "Ingrese el telefono del cliente: ";
    }
	
    void VistaCliente::solicitarEmailCliente() {
        std::cout << "Ingrese el email del cliente: ";
    }
};