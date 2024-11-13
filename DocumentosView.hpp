#ifndef DOCUMENTOS_VIEW_HPP
#define DOCUMENTOS_VIEW_HPP

#include "DocumentosModel.hpp"
#include <iostream>

class DocumentosView {
public:
    void displayDocumentos(const Documentos& doc) const;
};

#endif
