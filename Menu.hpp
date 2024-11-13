#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "Imagenes.hpp"
#include "Cliente.hpp"
#include "Abogado.hpp"


class Menu {
public:
    int eleccion_principal;
    int eleccion_cliente;
	int eleccion_abogado;
    Menu();  


	int opcion_principal();
	void derivar (int n);
};

#endif
