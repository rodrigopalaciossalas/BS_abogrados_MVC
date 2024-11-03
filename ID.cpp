 #include "ID.hpp"

// Inicializar el contador estático
int ID::contador = 0;

// Constructor
ID::ID() 
{
    id = ++contador;
}

int ID::obtenerID() 
{
    return id;
}
