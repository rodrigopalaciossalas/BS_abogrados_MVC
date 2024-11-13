#ifndef A_punteros_hpp
#define A_punteros_hpp
#include <iostream>

class A_puntero
{
  public:  
    int c_Longitud(const char* ptm);
    void copiarCadena(char*& destino, const char* origen);
    void imprimirCadena(const char* cadena);
    // Constructor
    A_puntero();
};

#endif // A_punteros 