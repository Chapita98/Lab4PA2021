#include "./../headers/Monitoreo.h"
#include "./../headers/Estudiante.h"
Monitoreo::Monitoreo() {}

Monitoreo::Monitoreo(int _id, std::string _nombre, DtFecha _fechaCom) : Clase(_id, _nombre, _fechaCom)
{

}

Estudiante *Monitoreo::getEstudiante(int i)
{
   //return this->estudiantes[i];
}


void Monitoreo::setEstudiante(Estudiante *_estudiante)
{
    this->estudiantes->add(_estudiante);
}

Monitoreo::~Monitoreo() {}
