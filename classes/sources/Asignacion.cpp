#include "./../headers/Asignacion.h"
Asignacion::Asignacion() {}

Asignacion::Asignacion(Tipo _tipo)
{
    this->tipo = _tipo;
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
