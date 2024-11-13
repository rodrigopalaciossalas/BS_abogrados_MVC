#include <iostream>
#ifndef CLIENTEVISTA_HPP
#define CLIENTEVISTA_HPP
#include "clientemodelo.hpp"

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif

class VistaCliente {
public:
    void mostrarCliente(const VistaCliente& VistaCliente);
    void solicitarNombreCliente();
	void solicitarApellidoCliente();
	void solicitarTelefonoCliente();
    void solicitarEmailCliente();
};

#endif