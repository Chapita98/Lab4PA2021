#ifndef ASIGNACION_H
#define ASIGNACION_H
#include "Tipo.h"

class Asignacion
{
private:
    Tipo tipo;

public:
    Asignacion();
    Asignacion(Tipo _tipo);

    Tipo getTipo();

    void setTipo(Tipo _tipo);

    virtual ~Asignacion();
};


#endif /* ASIGNACION_H */
