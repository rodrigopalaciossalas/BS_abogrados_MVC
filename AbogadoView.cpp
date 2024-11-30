// AbogadoView.cpp
#include "AbogadoView.hpp"

void AbogadoView::mostrarMenu() 
{
    std::cout << "\n=== Sistema de Gestión de Abogados ===\n";
    std::cout << "1. Agregar abogado\n";
    std::cout << "2. Listar abogados\n";
    std::cout << "3. Buscar abogado por ID\n";
    std::cout << "4. Eliminar abogado por ID\n";
    std::cout << "5. Modificar abogado\n";
    std::cout << "6. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int AbogadoView::solicitarOpcion() {
    int opcion;
    std::cin >> opcion;
    return opcion;
}

void AbogadoView::mostrarMensaje(const char* mensaje) {
    std::cout << mensaje << "\n";
}

void AbogadoView::mostrarListaAbogados(Abogado** abogados, int cantidad) {
    if (cantidad == 0) {
        mostrarMensaje("No hay abogados registrados.");
        return;
    }

    std::cout << "\n=== Lista de Abogados ===\n";
    for (int i = 0; i < cantidad; ++i) {
        std::cout << "ID: " << abogados[i]->obtenerID() << ", Nombre: " << abogados[i]->getNombres()
                  << " " << abogados[i]->getApellidos() << "\n";
    }
}

void AbogadoView::solicitarDatosAbogado(Abogado*& abogado) {
    char nombre[100], apellido[100], telefono[100], correo[100], especialidad[100], puesto[100];
    int edad, dia, mes, anio;
    double salario;

    std::cin.ignore();  // Limpiar el búfer antes de usar getline
    std::cout << "Nombre: ";
    std::cin.getline(nombre, 100);
    std::cout << "Apellido: ";
    std::cin.getline(apellido, 100);
    std::cout << "Teléfono: ";
    std::cin.getline(telefono, 100);
    std::cout << "Correo: ";
    std::cin.getline(correo, 100);
    std::cout << "Especialidad: ";
    std::cin.getline(especialidad, 100);
    std::cout << "Puesto: ";
    std::cin.getline(puesto, 100);

    std::cout << "Edad: ";
    std::cin >> edad;

    std::cout << "Salario: ";
    std::cin >> salario;

    std::cout << "Fecha de contratación (dd mm yyyy): ";
    std::cin >> dia >> mes >> anio;

    // Crear el nuevo abogado con los datos ingresados
    abogado = new Abogado(nombre, apellido, telefono, correo, edad, especialidad, salario, puesto, correo, dia, mes, anio);
}


int AbogadoView::solicitarID(const char* mensaje) {
    int id;
    std::cout << mensaje;
    std::cin >> id;
    return id;
}
void AbogadoView::mostrarOpcionesModificacion() {
    std::cout << "\nSeleccione el atributo a modificar:\n";
    std::cout << "1. Nombre\n";
    std::cout << "2. Apellido\n";
    std::cout << "3. Teléfono\n";
    std::cout << "4. Correo\n";
    std::cout << "5. Especialidad\n";
    std::cout << "6. Salario\n";
    std::cout << "7. Puesto\n";
    std::cout << "8. Fecha de Contratación\n";
    std::cout << "9. Cancelar\n";
    std::cout << "Opción: ";
}

void AbogadoView::solicitarNuevoValor(char* buffer, const char* mensaje) {
    std::cout << mensaje;
    std::cin.ignore();
    std::cin.getline(buffer, 100);
}

double AbogadoView::solicitarNuevoSalario() {
    double salario;
    std::cout << "Ingrese el nuevo salario: ";
    std::cin >> salario;
    return salario;
}

void AbogadoView::solicitarNuevaFecha(int& dia, int& mes, int& anio) {
    std::cout << "Ingrese la nueva fecha (dd mm yyyy): ";
    std::cin >> dia >> mes >> anio;
}


