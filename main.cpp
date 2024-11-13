#include "DocumentosModel.hpp"
#include "DocumentosView.hpp"
#include "DocumentosController.hpp"
#include "Fecha.hpp"

int main() {
    Fecha fecha1(10, 5, 2021);
    Fecha fecha2(15, 6, 2022);
    Fecha fecha3(20, 7, 2023);

    Documentos doc1("Contrato", 1, fecha1, "Contrato de alquiler");
    Documentos doc2("Reporte", 2, fecha2, "Reporte financiero");
    Documentos doc3("Testamento", 3, fecha3, "Testamento de defuncion");

    Documentos documentos[] = { doc1, doc2, doc3 };
    int docCount = 3;

    DocumentosController controller(documentos, docCount);

    std::cout << "Busqueda por titulo 'Contrato de alquiler':" << std::endl;
    controller.searchByName("Contrato de alquiler");

    std::cout << "\nBusqueda por ID 2:" << std::endl;
    controller.searchByID(2);

    std::cout << "\nBusqueda por fecha 20-7-2023:" << std::endl;
    controller.searchByDate(Fecha(20, 7, 2023));

    std::cout << "\nBusqueda por tipo 'Contrato':" << std::endl;
    controller.searchByType("Contrato");

    return 0;
}
