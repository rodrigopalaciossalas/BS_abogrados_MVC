// AbogadoController.hpp
#ifndef ABOGADO_CONTROLLER_HPP
#define ABOGADO_CONTROLLER_HPP

#include "AbogadoModel.hpp"
#include "AbogadoView.hpp"

class AbogadoController {
private:
    AbogadoModel* modelo;
    AbogadoView* vista;

public:
    AbogadoController(AbogadoModel* modelo, AbogadoView* vista);

    void iniciar();  // Lógica principal del menú
    void agregarAbogado();
    void listarAbogados();
    void buscarAbogado();
    void eliminarAbogado();
    void modificarAbogado();
};

#endif // ABOGADO_CONTROLLER_HPP

