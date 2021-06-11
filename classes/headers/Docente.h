#ifndef DOCENTE_H
#define DOCENTE_H
#include "./Usuario.h"
#include "./../../ICollection/interfaces/IDictionary.h"

class Usuario;

class Docente : public Usuario
{
private:
    std::string instituto;
    IDictionary * asignaciones;
    IDictionary * clases;

public:
    Docente();
    Docente(std::string _instituto);
    Docente(std::string _instituto, std::string _email, std::string _nombre, std::string _imagen, std::string _contrasenia);
    

    std::string getInstituto();

    void setInstituto(std::string _instituto);
    
    virtual ~Docente();
};

#endif /* DOCENTE_H */
