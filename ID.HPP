#ifndef ID_HPP
#define ID_HPP

class ID 
{
public:
    static int contador; // Contador estático para generar IDs únicos
    int id; 
    ID(); // Constructor
    int obtenerID();// Método para obtener el ID
};

#endif // ID_HPP
