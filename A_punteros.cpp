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
// Copia la cadena de caracteres de origen a destino (memoria dinámica)
void A_puntero::copiarCadena(char*& destino, const char* origen) {
    if (origen == nullptr) {
        destino = nullptr;
        return;
    }

    // Calcula la longitud de la cadena origen
    int longitud = c_Longitud(origen);

    // Libera la memoria anterior solo si destino no es nullptr
    if (destino != nullptr) {
        delete[] destino;
    }

    // Asigna nueva memoria para la cadena de destino
    destino = new char[longitud + 1];  // +1 para el carácter nulo '\0'

    // Copia la cadena
    for (int i = 0; i < longitud; ++i) {
        destino[i] = origen[i];
    }
    destino[longitud] = '\0'; // Null-terminator al final
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

char* A_puntero::dividirCadena(char* cadena, const char delimitador, int& inicio) {
    if (cadena == nullptr || cadena[inicio] == '\0') {
        return nullptr;  // Si no hay más tokens, retornamos nullptr
    }

    int longitud = 0;

    // Salta los caracteres delimitadores al principio
    while (cadena[inicio] == delimitador) {
        inicio++;
    }

    // Encuentra el siguiente delimitador o el final de la cadena
    int start = inicio;
    while (cadena[inicio] != '\0' && cadena[inicio] != delimitador) {
        longitud++;
        inicio++;
    }

    // Si llegamos al final de la cadena sin encontrar tokens válidos
    if (longitud == 0) {
        return nullptr;
    }

    // Crea una nueva cadena con el token encontrado
    char* token = new char[longitud + 1];
    for (int i = 0; i < longitud; i++) {
        token[i] = cadena[start + i];
    }
    token[longitud] = '\0'; // Null-terminator al final

    // Mueve inicio al siguiente carácter después del delimitador
    if (cadena[inicio] == delimitador) {
        inicio++;
    }

    return token;
}
