#include "AbogadoController.hpp"
#include <iostream>

AbogadoController::AbogadoController(Abogado* _abogado, AbogadoView* _vista)
    : abogado(_abogado), vista(_vista) 
    {}

void AbogadoController::mostrarDatos() 
{
    vista->mostrarDatos(*abogado);
}

void AbogadoController::ingresarDatosObligatorios() 
{
    char entrada[100];
    vista->solicitarEntrada("Ingrese el nombre del abogado: ", entrada, 100);
    abogado->setNombre(entrada);

    vista->solicitarEntrada("Ingrese el apellido del abogado: ", entrada, 100);
    abogado->setApellido(entrada);

    vista->solicitarEntrada("Ingrese el telefono del abogado: ", entrada, 100);
    abogado->setTelefono(entrada);

    vista->solicitarEntrada("Ingrese el puesto del abogado: ", entrada, 100);
    abogado->setPuesto(entrada);

    int dia = vista->solicitarFecha("Ingrese el dia de contratación: ");
    int mes = vista->solicitarFecha("Ingrese el mes de contratación: ");
    int anio = vista->solicitarFecha("Ingrese el año de contratación: ");
    abogado->setFechaContratacion(dia, mes, anio);
}

void AbogadoController::ingresarDatosOpcionales() 
{
    int eleccion;
    std::cout << "¿Qué desea modificar?\n1. Salario\n2. Puesto\n3. Especialidad\n";
    std::cin >> eleccion;

    if (eleccion == 1) {
        double salario;
        std::cout << "Ingrese el salario del abogado: ";
        std::cin >> salario;
        abogado->setSalario(salario);
    } else if (eleccion == 2) {
        char entrada[100];
        vista->solicitarEntrada("Ingrese el puesto del abogado: ", entrada, 100);
        abogado->setPuesto(entrada);
    } else if (eleccion == 3) {
        char entrada[100];
        vista->solicitarEntrada("Ingrese la especialidad del abogado: ", entrada, 100);
        abogado->setEspecialidad(entrada);
    }
}
