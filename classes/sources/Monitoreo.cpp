#include "./../headers/Monitoreo.h"
#include "./../headers/Estudiante.h"
Monitoreo::Monitoreo()
{
    this->estudiantes = new List;
}

Monitoreo::Monitoreo(int _id, std::string _nombre, DtFecha _fechaCom) : Clase(_id, _nombre, _fechaCom)
{
    this->estudiantes = new List;
}

ICollection *Monitoreo::getEstudiantes()
{
   return this->estudiantes;
}


void Monitoreo::setEstudiante(Estudiante *_estudiante)
{
    this->estudiantes->add(_estudiante);
}

Monitoreo::~Monitoreo() {}
