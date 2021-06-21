#include "./../headers/Estudiante.h"
Estudiante::Estudiante() {}

Estudiante::Estudiante(int _ci)
{
    this->ci = _ci;
    this->asignaturas = new OrderedDictionary;
    this->asistenciasdif = new OrderedDictionary;
    this->asistenciason = new OrderedDictionary;
}

Estudiante::Estudiante(int _ci, std::string _email, std::string _nombre, std::string _imagen, std::string _contrasenia) : Usuario(_email, _nombre, _imagen, _contrasenia)
{
    this->ci = _ci;
    this->asignaturas = new OrderedDictionary;
    this->asistenciasdif = new OrderedDictionary;
    this->asistenciason = new OrderedDictionary;
}

int Estudiante::getCi()
{
    return this->ci;
}


void Estudiante::setCi(int _ci)
{
    this->ci = _ci;
}

void Estudiante::setAsignatura(Asignatura *a)
{
    IKey *k = new Integer(a->getId());
    this->asignaturas->add(k, a);
}

bool Estudiante::estaInscripto(int id)
{
    if(!this->asignaturas->isEmpty())
    {
        IKey *k = new Integer(id);
        if(this->asignaturas->find(k))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

}
Estudiante::~Estudiante() {}
