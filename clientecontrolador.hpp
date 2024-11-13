#include <iostream>
#ifndef CLIENTECONTROLADOR_HPP
#define CLIENTECONTROLADOR_HPP
#include "clientemodelo.hpp"
#include "clientevista.hpp"

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif

class ControladorCliente {
public:
	
	
    ClienteModelo* cliente;
    VistaCliente vista;

    void crearCliente();

    void mostrarCliente();
	ControladorCliente() : cliente(nullptr) {}
    ~ControladorCliente();
};

#endif