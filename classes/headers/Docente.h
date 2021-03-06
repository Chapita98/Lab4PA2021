#ifndef DOCENTE_H
#define DOCENTE_H
#include "./Usuario.h"
#include "./Asignacion.h"
#include "./Clase.h"
#include "./../../ICollection/interfaces/IDictionary.h"
#include "./../../ICollection/interfaces/ICollection.h"

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
    std::string getEmail();
    std::string getNombre();
    ICollection *getAsignaturas();
    Asignacion *getAsignacion(int id);
    IDictionary *getClasesVivo();
    IDictionary *getClases();
    Clase *getClase(int id);

    void setInstituto(std::string _instituto);
    void setAsignacion(Asignacion *a, IKey *k);
    void setClase(Clase *c);

    bool estaAsignado(int id);
    void finalizarClase(int id, DtFecha *fecha);
    void BorrarAsignacion(int id, IDictionary *cl);
    Asignacion *crearAsignacion(Tipo tipo, int idAsignatura);


    virtual ~Docente();
};

#endif /* DOCENTE_H */
