#include "./../headers/Asignacion.h"
Asignacion::Asignacion() {}


Asignacion::Asignacion(Tipo _tipo, int _idAsignatura)
{
    this->tipo = _tipo;
    this->idAsignatura = _idAsignatura;
}

Tipo Asignacion::getTipo()
{
    return this->tipo;
}

Integer *Asignacion::getAsignatura()
{
    Integer *i = new Integer(this->idAsignatura);
    return i;
}
void Asignacion::setTipo(Tipo _tipo)
{
    this->tipo = _tipo;
}

Asignacion::~Asignacion() {}
