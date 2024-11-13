#include "Menu.hpp"
#include "Imagenes.hpp"
#include "Cliente.hpp"
#include "Abogado.hpp"
#include <iostream>
#define CLEAR_COMMAND "clear"

Menu::Menu() : eleccion_principal(0), eleccion_cliente(0) {}



int Menu::opcion_principal(){
	while(true){
		std::cout << "INICIE SESION COMO: " << std::endl;
		std::cout << "1. Cliente " << std::endl;
		std::cout << "2. Abogado" << std::endl;
		std::cout << "\nTu opcion: " << std::endl;
		std::cin >> eleccion_principal;
		if (eleccion_principal==1 || eleccion_principal==2)
		{
			break;
		}
		else
		{
			std::system(CLEAR_COMMAND);
			Imagenes abogaditos_tu_terror;
			std::cout<<"\n\n OPCION INVALIDA, INTENTE DENUEVO\n\n";
			continue;
		}
	}
		
	return eleccion_principal;
}


void Menu::derivar(int n){
    
    if (n==1)
	{ 
			Imagenes clien_letra;
			clien_letra.letras_clientes();

            std::cout << "                          ELIGE UNA OPCION\n\n";
            std::cout << "1. Ingresar mi id" << std::endl;
            std::cout << "2. Registrarme" << std::endl;
            std::cout << "\n\nTU OPCION ES: " << std::endl;
            std::cin >> eleccion_cliente;

            if (eleccion_cliente == 1) 
			{
                Cliente pers("Juana", "Perez", "60754660", "Juana@gmail.com");
                pers.mostrarDatos();
            }
			else {
                Cliente nuevoCliente("Julia", "Muñoz", "60754660", "Juana@gmail.com");
                nuevoCliente.Cliente_registrar();
            }
	}
	else	
	{
			std::system(CLEAR_COMMAND);
            std::cout << " _______ ______   _____   ______ _______ ______   _____  _______" << std::endl;
            std::cout << " |_____| |_____] |     | |  ____ |_____| |     ] |     | |______" << std::endl;
            std::cout << " |     | |_____] |_____| |_____| |     | |_____/ |_____| ______|" << std::endl;
            

            std::cout << "                          ELIGE UNA OPCION\n\n";
            std::cout << "1. Ingresar mi id" << std::endl;
            std::cout << "2. Registrarme" << std::endl;
            std::cout << "\n\nTU OPCION ES: " << std::endl;
            std::cin >> eleccion_abogado;

            if (eleccion_abogado == 1) {
                Abogado pers1("Juan", "Perez", "555-1234", "Penal", 50000.0, "Asociado", "juan.perez@gmail.com", 1, 1, 2020);
                pers1.mostrarDatos();
            } 
			else {
                Cliente nuevCliente("Julia", "Muñ", "457821", "Juana@gmail.com");
                std::cout<<"Proximamente... solo en los abogaditos tu terror";
            }
    }
}

