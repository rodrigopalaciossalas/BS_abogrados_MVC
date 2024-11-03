#include <iostream>
#include "Abogado.hpp"

int main() {
    // Crear un objeto Abogado con datos de prueba
    Abogado abogado1("Juan", "Perez", "555-1234", "Penal", 50000.0, "Asociado", "juan.perez@gmail.com", 1, 1, 2020);

    // Mostrar datos del abogado
    std::cout << "Datos iniciales del abogado:\n";
    abogado1.mostrarDatos();

    // Modificar datos obligatorios
    std::cout << "\nIngresar datos obligatorios:\n";
    abogado1.Abogado_datos_obligatorios();

    // Mostrar los datos actualizados
    std::cout << "\nDatos del abogado después de modificar datos obligatorios:\n";
    abogado1.mostrarDatos();

    // Modificar datos opcionales
    std::cout << "\nIngresar datos opcionales:\n";
    abogado1.Abogado_datos_opcionales();

    // Mostrar los datos finales
    std::cout << "\nDatos finales del abogado:\n";
    abogado1.mostrarDatos();

    return 0;
}
