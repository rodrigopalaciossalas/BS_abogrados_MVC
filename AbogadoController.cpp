// AbogadoController.cpp
#include "AbogadoController.hpp"

AbogadoController::AbogadoController(AbogadoModel* modelo, AbogadoView* vista)
    : modelo(modelo), vista(vista) {}

void AbogadoController::iniciar() {
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
            modificarAbogado();  // Nueva opción para modificar abogados
            break;
        case 6:
            vista->mostrarMensaje("Saliendo del sistema...");
            break;
        default:
            vista->mostrarMensaje("Opción inválida. Intente nuevamente.");
        }
    } while (opcion != 6);
}


void AbogadoController::agregarAbogado() {
    Abogado* nuevoAbogado = nullptr;
    vista->mostrarMensaje("\n=== Agregar Abogado ===");
    vista->solicitarDatosAbogado(nuevoAbogado);
    modelo->agregarAbogado(nuevoAbogado);
    vista->mostrarMensaje("Abogado agregado exitosamente.");
}


void AbogadoController::listarAbogados() {
    modelo->listarAbogados();
}

void AbogadoController::buscarAbogado() {
    int id = vista->solicitarID("Ingrese el ID del abogado: ");
    Abogado* abogado = modelo->buscarAbogadoPorID(id);
    if (abogado) {
        vista->mostrarMensaje("Abogado encontrado:");
        vista->mostrarListaAbogados(&abogado, 1);
    } else {
        vista->mostrarMensaje("No se encontró un abogado con ese ID.");
    }
}

void AbogadoController::eliminarAbogado() {
    int id = vista->solicitarID("Ingrese el ID del abogado a eliminar: ");
    modelo->eliminarAbogadoPorID(id);
    vista->mostrarMensaje("Abogado eliminado (si existía).");
}


void AbogadoController::modificarAbogado() {
    int id = vista->solicitarID("Ingrese el ID del abogado a modificar: ");
    Abogado* abogado = modelo->buscarAbogadoPorID(id);

    if (abogado == nullptr) {
        vista->mostrarMensaje("No se encontró un abogado con ese ID.");
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
            vista->mostrarMensaje("Nombre actualizado correctamente.");
            break;
        case 2:
            vista->solicitarNuevoValor(buffer, "Ingrese el nuevo apellido: ");
            abogado->setApellidos(buffer);
            vista->mostrarMensaje("Apellido actualizado correctamente.");
            break;
        case 3:
            vista->solicitarNuevoValor(buffer, "Ingrese el nuevo teléfono: ");
            abogado->setTelefono(buffer);
            vista->mostrarMensaje("Teléfono actualizado correctamente.");
            break;
        case 4:
            vista->solicitarNuevoValor(buffer, "Ingrese el nuevo correo: ");
            abogado->setCorreo(buffer);
            vista->mostrarMensaje("Correo actualizado correctamente.");
            break;
        case 5:
            vista->solicitarNuevoValor(buffer, "Ingrese la nueva especialidad: ");
            abogado->setEspecialidad(buffer);
            vista->mostrarMensaje("Especialidad actualizada correctamente.");
            break;
        case 6:
            nuevoSalario = vista->solicitarNuevoSalario();
            abogado->setSalario(nuevoSalario);
            vista->mostrarMensaje("Salario actualizado correctamente.");
            break;
        case 7:
            vista->solicitarNuevoValor(buffer, "Ingrese el nuevo puesto: ");
            abogado->setPuesto(buffer);
            vista->mostrarMensaje("Puesto actualizado correctamente.");
            break;
        case 8:
            vista->solicitarNuevaFecha(dia, mes, anio);
            abogado->setFechaContratacion(dia, mes, anio);
            vista->mostrarMensaje("Fecha de contratación actualizada correctamente.");
            break;
        case 9:
            vista->mostrarMensaje("Cancelando modificación...");
            break;
        default:
            vista->mostrarMensaje("Opción inválida. Intente nuevamente.");
        }
    } while (opcion != 9);
}
