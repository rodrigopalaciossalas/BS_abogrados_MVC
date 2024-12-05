#ifndef MAINGESTION_HPP
#define MAINGESTION_HPP

#include <iostream>

#include "mainEconomia.hpp"

#include "AbogadoModel.hpp"
#include "AbogadoView.hpp"
#include "AbogadoController.hpp"

#include "ColorManipulation.hpp"

#include "DocumentosManager.hpp"
#include "Clientes.hpp"
// Función para mostrar el menú
void mostrarMenu(int &opcion);

// Función para gestionar Abogados
void gestionarAbogados();

// Función para gestionar Economía (Boletas y Facturas)
void gestionarEconomia();

void gestionarDocumentos();

void gestionarClientes();

#endif // MAINGESTION_HPP
