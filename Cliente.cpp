/*
#include "Cliente.hpp"

void Cliente::mostrar_cliente() const {
    std::cout << "Nombre: " << nombres_cliente << std::endl;
	std::cout << "Apellidos: " << apellidos_cliente << std::endl;
    std::cout << "DNI: " << dni << std::endl;
    std::cout << "Telefono: " << telefono << std::endl;
    std::cout << "Direccion: " << direccion << std::endl;
}

void Cliente::registrar_cliente(){
	std::cout<<"REGISTRANDO CLIENTE";
	
	std::cout<<"\nIngresa tus nombres: ";
	std::cin>>nombres_cliente;
	
	std::cout<<"\nIngresa tus apellidos: ";
	std::cin>>apellidos_cliente;
	
	std::cout<<"\nIngresa tu DNI: ";
	std::cin>>dni;
	
	std::cout<<"\nIngresa tu telefono: ";
	std::cin>>telefono;
	
	std::cout<<"\nIngresa tu direccion: ";
	std::cin>>direccion;
}
*/
#include "Cliente.hpp"
#include <iostream>

Cliente::Cliente(const char* nom, const char* id, const char* tel) {
    for (int i = 0; i < 49 && nom[i] != '\0'; ++i) {
        nombre[i] = nom[i];
    }
    nombre[49] = '\0';

    for (int i = 0; i < 9 && id[i] != '\0'; ++i) {
        numero_id[i] = id[i];
    }
    numero_id[9] = '\0';

    for (int i = 0; i < 49 && tel[i] != '\0'; ++i) {
        telefono[i] = tel[i];
    }
    telefono[49] = '\0';
}

void Cliente::mostrarCliente() const {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "ID: " << numero_id << std::endl;
    std::cout << "TelÃ©fono: " << telefono << std::endl;
}

void Cliente::registrarCliente() const {
    std::cout << "MUY PRONTO TE PODRAS REGISTRAR, ANDAMOS CON \n RAZONAMIENTO DE ABOGADO Y NO DE PROGRAMADOR" << std::endl;
}




