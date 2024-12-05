// AbogadoView.cpp
#include "AbogadoView.hpp"
#include "ColorManipulation.hpp"
void AbogadoView::mostrarMenu() 
{
    resetCursor();
    clearScreen();
    setTextColor(YELLOW);
    std::cout << "\n===== Sistema de Gestion de Abogados =====\n";
    resetColor();
    setTextColor(GREEN);
    std::cout << "1."; 
    resetColor();
    std::cout << "Agregar abogado\n";
    setTextColor(GREEN);
    std::cout << "2."; 
    resetColor();
    std::cout << "Listar abogados\n";
    setTextColor(GREEN);
    std::cout << "3.";
    resetColor();
    std::cout << "Buscar abogado por ID\n";
    setTextColor(GREEN);
    std::cout << "4.";
    resetColor();
    std::cout << "Eliminar abogado por ID\n";
    setTextColor(GREEN);
    std::cout << "5.";
    resetColor();
    std::cout << "Modificar abogado\n";  // Nueva opción
    setTextColor(GREEN);
    std::cout << "6."; 
    resetColor();
    std::cout << "Salir\n";
    setTextColor(YELLOW);
    std::cout << "Seleccione una opcion: ";
    resetColor();
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
        setTextColor(BRIGHT_RED);
        mostrarMensaje("No hay abogados registrados.");
        resetColor();
        return;
    }
    setTextColor(YELLOW);
    std::cout << "\n==== Lista de Abogados ====\n";
    resetColor();
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

    std::cout << "Fecha de contratacion (dd mm yyyy): ";
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
    setTextColor(YELLOW);
    std::cout << "\nSeleccione el atributo a modificar:\n";
    setTextColor(YELLOW);
    std::cout << "1.";
    resetColor();
    std::cout << " Nombre\n";
    setTextColor(YELLOW);
    std::cout << "2.";
    resetColor();
    std::cout << " Apellido\n";
    setTextColor(YELLOW);
    std::cout << "3.";
    resetColor();
    std::cout << " Telefono\n";
    setTextColor(YELLOW);
    std::cout << "4.";
    resetColor();
    std::cout << " Correo\n";
    setTextColor(YELLOW);
    std::cout << "5.";
    resetColor();
    std::cout << " Especialidad\n";
    setTextColor(YELLOW);
    std::cout << "6.";
    resetColor();
    std::cout << " Salario\n";
    setTextColor(YELLOW);
    std::cout << "7.";
    resetColor();
    std::cout << " Puesto\n";
    setTextColor(YELLOW);
    std::cout << "8.";
    resetColor();
    std::cout << " Fecha de Contratación\n";
    setTextColor(YELLOW);
    std::cout << "9.";
    resetColor();
    std::cout << " Cancelar\n";
    setTextColor(YELLOW);
    std::cout << "Opcion: ";
    resetColor();
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


