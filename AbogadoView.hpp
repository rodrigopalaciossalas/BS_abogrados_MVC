// AbogadoView.hpp
#ifndef ABOGADO_VIEW_HPP
#define ABOGADO_VIEW_HPP

#include "Abogado.hpp"

class AbogadoView {
public:
    
    void mostrarMenu();  // Muestra el menú principal
    int solicitarOpcion();  // Solicita al usuario seleccionar una opción del menú
    void mostrarMensaje(const char* mensaje);  // Muestra un mensaje al usuario
    void mostrarListaAbogados(Abogado** abogados, int cantidad);  // Muestra una lista de abogados
    void solicitarDatosAbogado(Abogado*& abogado);  // Solicita datos de un abogado al usuario
    int solicitarID(const char* mensaje);  // Solicita un ID
    void mostrarOpcionesModificacion();
    void solicitarNuevoValor(char* buffer, const char* mensaje);
    double solicitarNuevoSalario();
    void solicitarNuevaFecha(int& dia, int& mes, int& anio);
};

#endif // ABOGADO_VIEW_HPP
