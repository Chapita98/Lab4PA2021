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


void Asignacion::setTipo(Tipo _tipo)
{
    this->tipo = _tipo;
}

Asignacion::~Asignacion() {}
