#include "AbogadoView.hpp"
#include <iostream>

void AbogadoView::mostrarDatos( Abogado& abogado) 
{
    std::cout << "ID: Abg." << abogado.obtenerID() << "\n";
    std::cout << "Nombre: "; abogado.imprimirCadena(abogado.getNombre());
    std::cout << "\nApellido: "; abogado.imprimirCadena(abogado.getApellido());
    std::cout << "\nTelefono: "; abogado.imprimirCadena(abogado.getTelefono());
    std::cout << "\nEspecialidad: "; abogado.imprimirCadena(abogado.getEspecialidad());
    std::cout << "\nSalario: " << abogado.getSalario() << "\n";
    std::cout << "Puesto: "; abogado.imprimirCadena(abogado.getPuesto());
    std::cout << "\nGmail: "; abogado.imprimirCadena(abogado.getGmail());
    std::cout << "\nFecha de Contratacion: "; // Aquí puedes mostrar la fecha completa
}

void AbogadoView::solicitarEntrada(const char* mensaje, char* entrada, int longitud) {
    std::cout << mensaje;
    std::cin.ignore();
    std::cin.getline(entrada, longitud);
}

int AbogadoView::solicitarFecha(const char* mensaje) {
    std::cout << mensaje;
    int fecha;
    std::cin >> fecha;
    return fecha;
}
