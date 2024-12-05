// AbogadoController.cpp
#include "AbogadoController.hpp"
#include"ColorManipulation.hpp"
AbogadoController::AbogadoController(AbogadoModel* modelo, AbogadoView* vista)
    : modelo(modelo), vista(vista) 
    {}

void AbogadoController::iniciar() 
{
    int opcion;
    do {
        vista->mostrarMenu();
        opcion = vista->solicitarOpcion();

        switch (opcion) {
        case 1:
            agregarAbogado();
            break;
        case 2:
            listarAbogados();
            break;
        case 3:
            buscarAbogado();
            break;
        case 4:
            eliminarAbogado();
            break;
        case 5:
            modificarAbogado();  
            break;
        case 6:
            setTextColor(BRIGHT_RED);
            vista->mostrarMensaje("Saliendo del sistema...");
            resetColor();
            break;
        default:
            setTextColor(BRIGHT_RED);
            vista->mostrarMensaje("Opción inválida. Intente nuevamente.");
            resetColor();
        }
    } while (opcion != 6);
}


void AbogadoController::agregarAbogado() 
{
    Abogado* nuevoAbogado = nullptr;
    setTextColor(YELLOW);
    vista->mostrarMensaje("\n====== Agregar Abogado =====");
    resetColor();
    vista->solicitarDatosAbogado(nuevoAbogado);
    modelo->agregarAbogado(nuevoAbogado);
    setTextColor(GREEN);
    vista->mostrarMensaje("Abogado agregado exitosamente.");
    resetColor();
}


void AbogadoController::listarAbogados() 
{
    modelo->listarAbogados();
}

void AbogadoController::buscarAbogado() 
{
    int id = vista->solicitarID("Ingrese el ID del abogado: ");
    Abogado* abogado = modelo->buscarAbogadoPorID(id);
    if (abogado) 
    {
        vista->mostrarMensaje("Abogado encontrado:");
        vista->mostrarListaAbogados(&abogado, 1);
    } else 
    {
        setTextColor(BRIGHT_RED);
        vista->mostrarMensaje("No se encontró un abogado con ese ID.");
        resetColor();
    }
}

void AbogadoController::eliminarAbogado()
{
    int id = vista->solicitarID("Ingrese el ID del abogado a eliminar: ");
    modelo->eliminarAbogadoPorID(id);
    setTextColor(BRIGHT_RED);
    vista->mostrarMensaje("Abogado eliminado (si existía).");
    resetColor();
}


void AbogadoController::modificarAbogado() 
{
    int id = vista->solicitarID("Ingrese el ID del abogado a modificar: ");
    Abogado* abogado = modelo->buscarAbogadoPorID(id);

    if (abogado == nullptr) 
    {
        setTextColor(BRIGHT_RED);
        vista->mostrarMensaje("No se encontro un abogado con ese ID.");
        setTextColor(BRIGHT_RED);
        return;
    }

    int opcion;
    do {
        vista->mostrarOpcionesModificacion();
        opcion = vista->solicitarOpcion();

        char buffer[100];
        int dia, mes, anio;
        double nuevoSalario;

        switch (opcion) 
        {
        case 1:
            vista->solicitarNuevoValor(buffer, "Ingrese el nuevo nombre: ");
            abogado->setNombres(buffer);
            setTextColor(BRIGHT_GREEN);
            vista->mostrarMensaje("Nombre actualizado correctamente.");
            resetColor();
            break;
        case 2:
            vista->solicitarNuevoValor(buffer, "Ingrese el nuevo apellido: ");
            abogado->setApellidos(buffer);
            setTextColor(BRIGHT_GREEN);
            vista->mostrarMensaje("Apellido actualizado correctamente.");
            resetColor();
            break;
        case 3:
            vista->solicitarNuevoValor(buffer, "Ingrese el nuevo teléfono: ");
            abogado->setTelefono(buffer);
            setTextColor(BRIGHT_GREEN);
            vista->mostrarMensaje("Teléfono actualizado correctamente.");
            resetColor();
            break;
        case 4:
            vista->solicitarNuevoValor(buffer, "Ingrese el nuevo correo: ");
            abogado->setCorreo(buffer);
            setTextColor(BRIGHT_GREEN);
            vista->mostrarMensaje("Correo actualizado correctamente.");
            resetColor();
            break;
        case 5:
            vista->solicitarNuevoValor(buffer, "Ingrese la nueva especialidad: ");
            abogado->setEspecialidad(buffer);
            setTextColor(BRIGHT_GREEN);
            vista->mostrarMensaje("Especialidad actualizada correctamente.");
            resetColor();
            break;
        case 6:
            nuevoSalario = vista->solicitarNuevoSalario();
            abogado->setSalario(nuevoSalario);
            setTextColor(BRIGHT_GREEN);
            vista->mostrarMensaje("Salario actualizado correctamente.");
            resetColor();
            break;
        case 7:
            vista->solicitarNuevoValor(buffer, "Ingrese el nuevo puesto: ");
            abogado->setPuesto(buffer);
            setTextColor(BRIGHT_GREEN);
            vista->mostrarMensaje("Puesto actualizado correctamente.");
            resetColor();
            break;
        case 8:
            vista->solicitarNuevaFecha(dia, mes, anio);
            abogado->setFechaContratacion(dia, mes, anio);
            setTextColor(BRIGHT_GREEN);
            vista->mostrarMensaje("Fecha de contratacion actualizada correctamente.");
            resetColor();
            break;
        case 9:
            setTextColor(BRIGHT_RED);
            vista->mostrarMensaje("Cancelando modificación...");
            resetColor();
            break;
        default:
            setTextColor(BRIGHT_RED);
            vista->mostrarMensaje("Opcion invalida. Intente nuevamente.");
            resetColor();
        }
    } while (opcion != 9);
}
