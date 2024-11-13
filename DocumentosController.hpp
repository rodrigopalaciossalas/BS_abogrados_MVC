#ifndef DOCUMENTOS_CONTROLLER_HPP
#define DOCUMENTOS_CONTROLLER_HPP

#include "DocumentosModel.hpp"
#include "DocumentosView.hpp"

class DocumentosController {
private:
    Documentos* documentos;
    int docCount;
    DocumentosView view;

    bool compareStrings(const char* str1, const char* str2) const;

public:
    DocumentosController(Documentos* docs, int count);

    void searchByName(const char* name) const;
    void searchByID(int id) const;
    void searchByDate(Fecha date) const;
    void searchByType(const char* type) const;

    void displayDocumentos(const Documentos& doc) const;
};

#endif
