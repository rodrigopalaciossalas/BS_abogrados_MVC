/*
#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include <iostream>

//CLASE PRINCIPAL
class Cliente{
	
public: 
	char direccion[50];
	char telefono[20];	
	char nombres_cliente[20];
	char apellidos_cliente[20];
	char dni[20];
	
	void mostrar_cliente();
	void registrar_cliente() const;
};


#endif*/

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>

class Cliente {
public:
    char nombre[50];
    char numero_id[10];
    char telefono[50];

    Cliente(const char* nom, const char* id, const char* tel);
    void mostrarCliente() const;
    void registrarCliente() const;
};

#endif 

