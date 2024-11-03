#include "Menu.hpp"
#include "Cliente.hpp"
#include "Abogado.hpp"
#include <iostream>

// ImplementaciÃ³n del constructor predeterminado
Menu::Menu() : eleccion_principal(0), eleccion_cliente(0) {}

void Menu::caratula() {
    std::cout << "       #####   ######    #####    #####    #####   ######    ######   ######   #####    #####" << std::endl;
    std::cout << "      ##   ##   ##  ##  ##   ##  ##   ##  ##   ##   ##  ##     ##       ##    ##   ##  ##   ##" << std::endl;
    std::cout << "      ##   ##   ##  ##  ##   ##  ##       ##   ##   ##  ##     ##       ##    ##   ##  ##" << std::endl;
    std::cout << "      #######   #####   ##   ##  ##  ###  #######   ##  ##     ##       ##    ##   ##   #####" << std::endl;
    std::cout << "      ##   ##   ##  ##  ##   ##  ##   ##  ##   ##   ##  ##     ##       ##    ##   ##       ##" << std::endl;
    std::cout << "      ##   ##   ##  ##  ##   ##  ##   ##  ##   ##   ##  ##     ##       ##    ##   ##  ##   ##" << std::endl;
    std::cout << "      ##   ##  ######    #####    #####   ##   ##  ######    ######     ##     #####    #####" << std::endl;
    std::cout << "                                         TU TERROR                                           \n\n\n" << std::endl;

    std::cout << "INICIE SESION COMO: " << std::endl;
    std::cout << "1. Cliente " << std::endl;
    std::cout << "2. Abogado" << std::endl;
    std::cout << "\nTu opcion: " << std::endl;
    std::cin >> eleccion_principal;

    switch (eleccion_principal) {
        case 1:
            std::system(CLEAR_COMMAND);
            std::cout << "                 _/       _/                               _/" << std::endl;
            std::cout << "  _/_/_/        _/                 _/_/       _/_/_/    _/_/_/_/       _/_/" << std::endl;
            std::cout << " _/            _/       _/      _/_/_/_/     _/    _/    _/         _/_/_/_/" << std::endl;
            std::cout << "_/            _/       _/      _/           _/    _/    _/         _/" << std::endl;
            std::cout << " _/_/_/      _/       _/        _/_/_/     _/    _/      _/_/       _/_/_/" << std::endl;

            std::cout << "                          ELIGE UNA OPCION\n\n";
            std::cout << "1. Ingresar mi id" << std::endl;
            std::cout << "2. Registrarme" << std::endl;
            std::cout << "\n\nTU OPCION ES: " << std::endl;
            std::cin >> eleccion_cliente;

            if (eleccion_cliente == 1) {
                Cliente pers("Juana", "60794260", "457821");
                pers.mostrarCliente();
            } else if (eleccion_cliente == 2) {
                Cliente nuevoCliente("Nuevo", "00000000", "123456");
                nuevoCliente.registrarCliente();
            }
            break;
		case 2: 
			std::system(CLEAR_COMMAND);
            std::cout << " _______ ______   _____   ______ _______ ______   _____  _______" << std::endl;
            std::cout << " |_____| |_____] |     | |  ____ |_____| |     \ |     | |______" << std::endl;
            std::cout << " |     | |_____] |_____| |_____| |     | |_____/ |_____| ______|" << std::endl;
            

            std::cout << "                          ELIGE UNA OPCION\n\n";
            std::cout << "1. Ingresar mi id" << std::endl;
            std::cout << "2. Registrarme" << std::endl;
            std::cout << "\n\nTU OPCION ES: " << std::endl;
            std::cin >> eleccion_abogado;

            if (eleccion_abogado == 1) {
            } else if (eleccion_cliente == 2) {
                Cliente nuevoCliente("Nuevo", "00000000", "123456");
                std::cout<<"Proximamente... solo en los abogaditos tu terror";
            }
            break;

		
        default:
            std::cout << "Opcion invalida." << std::endl;
            break;
    }
}


