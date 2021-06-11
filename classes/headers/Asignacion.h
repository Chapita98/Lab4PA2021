#ifndef ASIGNACION_H
#define ASIGNACION_H
#include "Tipo.h"
#include "./../../ICollection/interfaces/ICollectible.h"

class Asignacion : public ICollectible
{
private:
    Tipo tipo;
    int idAsignatura;

public:
    Asignacion();
    Asignacion(Tipo _tipo);

    Tipo getTipo();

    void setTipo(Tipo _tipo);

    virtual ~Asignacion();
};


#endif /* ASIGNACION_H */
