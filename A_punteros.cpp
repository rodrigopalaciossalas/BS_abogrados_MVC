#include "A_punteros.hpp"
#include <iostream>

A_puntero::A_puntero( char* origen) 
{
    origen = new char[c_Longitud(origen) + 1];
    for (int i = 0; i < c_Longitud(origen); ++i) 
    {
        origen[i] = origen[i]; 
    }
    origen[c_Longitud(origen)] = '\0'; 

    destino = nullptr; 
    copiarCadena(origen); 
}


A_puntero::~A_puntero() 
{
    delete[] destino; 
    delete[] origen; 
}

int A_puntero::c_Longitud(const char* _ptm)
 {
    int longitud = 0;
    while (_ptm[longitud] != '\0') 
    {
        longitud++;
    }
    return longitud;
}

void A_puntero::copiarCadena( char* _origen) 
{
        delete[] destino;
    destino = new char[c_Longitud(_origen) + 1]; 

    for (int i = 0; i < c_Longitud(_origen); ++i) 
    {
        destino[i] = _origen[i];
    }
    destino[c_Longitud(_origen)] = '\0';
}
