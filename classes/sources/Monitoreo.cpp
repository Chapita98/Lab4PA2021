#include "./../headers/Monitoreo.h"
Monitoreo::Monitoreo() {}

Monitoreo::Monitoreo(int _id, std::string _video, std::string _nombre, DtFecha _fechaCom, DtFecha _fechaFin) : Clase(_id, _video, _nombre, _fechaCom, _fechaFin)
{

}

Estudiante Monitoreo::getEstudiante(int i)
{
    return this->estudiantes[i];
}


void Monitoreo::setEstudiante(Estudiante *_estudiante, int i) // i tendria el ultimo lugar del arreglo
{
    this->estudiantes[i] = _estudiante;
}

Monitoreo::~Monitoreo() {}
