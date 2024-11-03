#include <iostream>
#include "Abogado.hpp"
#include "Fecha.hpp"

int main() {
    char nombre[100], apellido[100], telefono[100], especialidad[100], puesto[100], gmail[100];
    double salario;
    int dia, mes, anio;

    // Solicitar datos obligatorios
    std::cout << "Ingrese el nombre del abogado: ";
    std::cin.getline(nombre, 100);

    std::cout << "Ingrese el apellido del abogado: ";
    std::cin.getline(apellido, 100);

    std::cout << "Ingrese el telefono del abogado: ";
    std::cin.getline(telefono, 100);

    std::cout << "Ingrese la especialidad del abogado: ";
    std::cin.getline(especialidad, 100);

    std::cout << "Ingrese el salario del abogado: ";
    std::cin >> salario;

    std::cout << "Ingrese el puesto del abogado: ";
    std::cin.ignore();  
    std::cin.getline(puesto, 100);

    // Solicitar fecha de contratación
    std::cout << "Ingrese la fecha de contratación (dia mes anio): ";
    std::cin >> dia >> mes >> anio;

    // Solicitar datos opcionales
    std::cout << "Ingrese el gmail del abogado (opcional): ";
    std::cin.ignore();  
    std::cin.getline(gmail, 100);

    // Crear objeto Abogado
    Abogado abogado(nombre, apellido, telefono, especialidad, salario, puesto, gmail, dia, mes, anio);

    // Mostrar datos del abogado
    abogado.mostrarDatos();

    return 0;
}

