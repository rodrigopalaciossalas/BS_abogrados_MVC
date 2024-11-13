
#ifndef CLIENTEMODELO_HPP
#define CLIENTEMODELO_HPP
#include <iostream>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif

// Modelo
class ClienteModelo {
public:
    char* nombre;
    char* email;
	char* apellido;
	char* gmail;

	void setNombre(const char* n);
    void setEmail(const char* e);

    ClienteModelo(const char* n, const char* e);

    ~ClienteModelo();

};

#endif