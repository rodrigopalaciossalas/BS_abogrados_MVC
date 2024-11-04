#ifndef A_PUNTEROS_HPP
#define A_PUNTEROS_HPP

class A_puntero 
{
public:
    char* ptm;     
    char* destino; 
    char* origen;  

    // Métodos
    int c_Longitud(const char* _ptm);
    void copiarCadena( char* _origen); 

    // Constructor
    A_puntero( char* origen); 
    
    // Destructor
    ~A_puntero();
};

#endif // A_PUNTEROS_HPP
