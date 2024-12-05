#include "DocumentosView.hpp"

void DocumentosView::mostrarDocumentos(const Documentos& doc) const {
    std::cout << "Titulo: " << doc.getTitulo() << std::endl;
    std::cout << "ID: " << doc.getID() << std::endl;
    std::cout << "Fecha de Creacion: ";
    doc.getFecha().imprimirFecha();
    std::cout << "Tipo: " << doc.getTipo() << std::endl;
}