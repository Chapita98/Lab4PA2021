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

AsistenciaDiferida * Estudiante::getAsistenciaDif(int id)
{
    IKey *k = new Integer(id);
    if(this->asistenciasdif->member(k))
    {
        return (AsistenciaDiferida *)this->asistenciasdif->find(k);
    }
    else
    {
        return NULL;
    }

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

void Estudiante::setAsisDif(int id, DtFecha *fecha)
{
    IKey *k = new Integer(id);
    if(this->asistenciasdif->member(k))
    {
        AsistenciaDiferida *a = (AsistenciaDiferida *)this->asistenciasdif->find(k);
        a->setFechaCom(fecha);
    }
    else
    {
        AsistenciaDiferida *a = new AsistenciaDiferida();
        a->setFechaCom(fecha);
        a->setIdClase(id);
        this->asistenciasdif->add(k, a);
    }

}

void Estudiante::setAsisOn(int id, AsistenciaOnline *a)
{
    IKey *k = new Integer(id);
    this->asistenciason->add(k, a);

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

AsistenciaOnline *Estudiante::crearAsisOn(int id, DtFecha fechaCom)
{
    AsistenciaOnline *a = new AsistenciaOnline(id, fechaCom);
    return a;
}

void Estudiante::BorrarAsignatura(int id)
{
    IKey *k = new Integer(id);
    if(this->asistenciasdif->member(k))
    {
        //AsistenciaDiferida *a = (AsistenciaDiferida *)this->asistenciasdif->find(k);
        this->asistenciasdif->remove(k);
        //delete a;
    }
    if(this->asistenciason->member(k))
    {
        //AsistenciaOnline *a = (AsistenciaOnline *)this->asistenciason->find(k);
        this->asistenciason->remove(k);
        //delete a;
    }
    //Asignatura *a;
    //a = (Asignatura *)this->asignaturas->find(k);
    this->asignaturas->remove(k);
    //delete a;
}

Estudiante::~Estudiante() {}
