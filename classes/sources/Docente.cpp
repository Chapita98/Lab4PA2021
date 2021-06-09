#include "./../headers/Docente.h"
Docente::Docente() {}

Docente::Docente(std::string _instituto)
{
    this->instituto = _instituto;
}

Docente::Docente(std::string _instituto, std::string _email, std::string _nombre, std::string _imagen, std::string _contrasenia) : Usuario(_email, _nombre, _imagen, _contrasenia)
{
    this->instituto = _instituto;
}

std::string Docente::getInstituto()
{
    return this->instituto;
}


void Docente::setInstituto(std::string _instituto)
{
    this->instituto = _instituto;
}

Docente::~Docente() {}
