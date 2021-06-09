#include "./../headers/Estudiante.h"
Estudiante::Estudiante() {}

Estudiante::Estudiante(int _ci)
{
    this->ci = _ci;
}

Estudiante::Estudiante(int _ci, std::string _email, std::string _nombre, std::string _imagen, std::string _contrasenia) : Usuario(_email, _nombre, _imagen, _contrasenia)
{
    this->ci = _ci;
}

int Estudiante::getCi()
{
    return this->ci;
}


void Estudiante::setCi(int _ci)
{
    this->ci = _ci;
}

Estudiante::~Estudiante() {}
