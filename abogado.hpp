#ifndef ABOGADO_HPP
#define ABOGADO_HPP

class Abogado 
{
    public:
        double salario;          
        char puesto[50];         
        char nombre[50];         
        char apellido[50];      
        int ID_Empleado;         
        char telefono[15];       
        char gmail[50];          
        int fecha_contratacion;  
        char especialidad[50]; 

        // Constructor
        Abogado(double salario, const char puesto[50], const char nombre[50], const char apellido[50], 
                int ID_Empleado, const char telefono[15], const char gmail[50], 
                int fecha_contratacion, const char especialidad[50]);

        // Método para mostrar datos
        void mostrarDatos();
};

#endif // ABOGADO_HPP


/* punteros para class abogado ideas
class Abogado 
{
    public:
        double* salario;
        char* puesto;
        char* nombre;
        char* apellido;
        int* ID_Empleado;
        char* telefono;
        char* gmail;
        int* fecha_contratacion;
        char* especialidad;

        // Metodos entrada de datos
        void mostrarDatos();
        void setSalario(double* _salario);
        void setPuesto(char* _puesto);
        void setNombre(char* _nombre);
        void setApellido(char* _apellido);
        void setID_Empleado(int* _ID_Empleado);
        void setTelefono(char* _telefono);
        void setGmail(char* _gmail);
        void setFechaContratacion(int* _fecha_contratacion);
        void setEspecialidad(char* _especialidad);

        // Constructor
        Abogado(double* salario, char* puesto, char* nombre, char* apellido, 
                int* ID_Empleado, char* telefono, char* gmail, 
                int* fecha_contratacion, char* especialidad);
       
        // Destructor
        ~Abogado();

};
*/