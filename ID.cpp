// ID.cpp
#include "ID.hpp"

int ID::contadorID = 0; // Inicializamos el contador en 0.

int ID::generarID() {
    return ++contadorID; // Incrementa y devuelve el nuevo ID
}
