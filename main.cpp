#include "AbogadoModel.hpp"
#include "AbogadoView.hpp"
#include "AbogadoController.hpp"

int main() {
    AbogadoModel modelo;
    AbogadoView vista;
    AbogadoController controlador(&modelo, &vista);

    controlador.iniciar();
    return 0;
}
