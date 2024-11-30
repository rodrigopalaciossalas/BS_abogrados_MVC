// ID.hpp
#ifndef ID_HPP
#define ID_HPP

class ID {
private:
    static int contadorID;

public:
    static int generarID(); // Método estático para generar un nuevo ID
};

#endif // ID_HPP
