#include "./../headers/Asignatura.h"

Asignatura::Asignatura() {}

Asignatura::Asignatura(int _id, std::string _nombre)
{
    this->id = _id;
    this->nombre = _nombre;
}

int Asignatura::getId()
{
    return this->id;
}

std::string Asignatura::getNombre()
{
    return this->nombre;
}


void Asignatura::setId(int _id)
{
    this->id = _id;
}

void Asignatura::setNombre(std::string _nombre)
{
    this->nombre = _nombre;
}


Asignatura::~Asignatura() {}
