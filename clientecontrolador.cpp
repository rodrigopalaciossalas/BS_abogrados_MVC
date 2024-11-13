#include <iostream>
#include "clientecontrolador.hpp"

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif

    void ControladorCliente::crearCliente() {
        char nombre[100];   // memoria temporal para almacenar el nombre
        char email[100];    
		char apellido[100]; 
		char telefono[100]; 

        vista.solicitarNombreCliente();
        std::cin.getline(nombre, 100);
        
		vista.solicitarApellidoCliente();
        std::cin.getline(apellido, 100);
		
		vista.solicitarTelefonoCliente();
        std::cin.getline(telefono, 100);
		
        vista.solicitarEmailCliente();
        std::cin.getline(email, 100);
        
        ClienteModelo* cliente = new Cliente(nombre, apellido, telefono, email);
    }

    void ControladorCliente::mostrarCliente() {
        if (cliente != nullptr) {
            vista.mostrarCliente(*cliente);
        } else {
            std::cout << "No hay cliente para mostrar." << std::endl;
        }
    }

    ControladorCliente::~ControladorCliente() {
        delete cliente; // Liberar memoria
    };