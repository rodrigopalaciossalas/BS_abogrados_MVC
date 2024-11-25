#include "A_punteros.hpp"

// Calcula la longitud de la cadena
int A_puntero::c_Longitud(const char* ptm) 
{
    int longitud = 0;
    while (ptm[longitud] != '\0') 
    {
        longitud++;
    }
    return longitud;
}

// Copia la cadena origen en destino (memoria dinámica)
void A_puntero::copiarCadena(char*& destino, const char* origen) 
{
    if (origen == nullptr) 
    {
        destino = nullptr;
        return;
    }

    int longitud = c_Longitud(origen);

    // Liberar la memoria anterior solo si destino no es nullptr
    if (destino != nullptr) 
    {
        delete[] destino;
    }

    // Asignar nueva memoria para la cadena de destino
    destino = new char[longitud + 1];  // +1 para el carácter nulo '\0'

    // Copiar la cadena
    for (int i = 0; i < longitud; ++i) 
    {
        destino[i] = origen[i];
    }
    destino[longitud] = '\0'; // Agregar el carácter nulo al final
}

// Imprime la cadena
void A_puntero::imprimirCadena(const char* cadena) 
{
    if (cadena == nullptr || cadena[0] == '\0') {
        std::cout << "Cadena vacía" << std::endl;
    } else {
        std::cout << cadena << std::endl;
    }
}
