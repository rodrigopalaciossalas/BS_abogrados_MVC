#ifndef DOCUMENTOS_CONTROLLER_HPP
#define DOCUMENTOS_CONTROLLER_HPP

#include "DocumentosModel.hpp"
#include "DocumentosView.hpp"
#include <fstream>

class DocumentosController {
private:
    Documentos* documentos;
    int docCount;
    DocumentosView vista;

    bool compararCadenas(const char* str1, const char* str2) const;

public:
    DocumentosController(Documentos* docs, int count);

    void buscarPorNombre(const char* name) const;
    void buscarPorID(int id) const;
    void buscarPorFecha(Fecha fecha) const;
    void buscarPorTipo(const char* tipo) const;

    void guardarDocumentosEnArchivo(const char* nombreArchivo) const;
    void mostrarDocumentosDesdeArchivo(const char* nombreArchivo) const;

    void agregarDocumento(const char* tipo, int id, Fecha fecha, const char* titulo);
    void modificarDocumento(int id);
    void eliminarDocumento(int id);

    void mostrarDocumentos(const Documentos& doc) const;
};

#endif
