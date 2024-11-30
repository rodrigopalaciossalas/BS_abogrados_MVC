#ifndef A_PUNTEROS_HPP
#define A_PUNTEROS_HPP

#include <iostream>

class A_puntero 
{
public:
    // Método para calcular la longitud de una cadena
    static int c_Longitud(const char* ptm);

    // Método para copiar una cadena a memoria dinámica
    static void copiarCadena(char*& destino, const char* origen);

    // Método para imprimir una cadena
    static void imprimirCadena(const char* cadena);

    static char* dividirCadena(char* cadena, const char delimitador, int& inicio);
};

#endif // A_PUNTEROS_HPP
