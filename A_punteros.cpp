#include "A_punteros.hpp"
#include <iostream>

int A_puntero::c_Longitud(const char* ptm) 
{
    int longitud = 0;
    while (ptm[longitud] != '\0') 
    {
        longitud++;
    }
    return longitud;
}

void A_puntero::copiarCadena(char*& destino, const char* origen) 
{
    delete[] destino; // Liberar memoria no se bien si esta implementacion es correcta
    destino = new char[c_Longitud(origen) + 1];
    for (int i = 0; i < c_Longitud(origen); ++i) 
    {
        destino[i] = origen[i];
    }
    destino[c_Longitud(origen)] = '\0';
}

void A_puntero::imprimirCadena(const char* cadena) 
{
    for (const char* ptr = cadena; *ptr != '\0'; ++ptr) 
    {
        std::cout << *ptr;
    }
    std::cout << "\n";
}


A_puntero::A_puntero()
{

}
