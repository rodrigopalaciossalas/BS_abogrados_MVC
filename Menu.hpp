#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "Cliente.hpp"
#include "Abogado.hpp"
#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif

class Menu {
public:
    int eleccion_principal;
    int eleccion_cliente;
	int eleccion_abogado;
    Menu();  

    void caratula();
};

#endif
