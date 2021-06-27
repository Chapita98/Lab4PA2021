#include "./../headers/Estudiante.h"
Estudiante::Estudiante()
{
    this->asignaturas = new OrderedDictionary;
    this->asistenciasdif = new OrderedDictionary;
    this->asistenciason = new OrderedDictionary;
}

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

bool Estudiante::Asistio(int id)
{
    IKey *k = new Integer(id);
    if(this->asistenciason->member(k))
    {
        return true;
    }
    else
    {
        return false;
    }

}

AsistenciaOnline * Estudiante::getAsistenciaOn(int id)
{
    IKey *k = new Integer(id);
    if(this->asistenciason->member(k))
    {
        AsistenciaOnline *a;
        a = (AsistenciaOnline *)this->asistenciason->find(k);
        return a;
    }
    else
    {
        return NULL;
    }

}

IDictionary *Estudiante::getAsistenciasOn()
{
    return this->asistenciason;
}

IDictionary *Estudiante::getAsistenciasDif()
{
    return this->asistenciasdif;
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
        AsistenciaDiferida *a = new AsistenciaDiferida;
        a->setFechaCom(fecha);
        this->asistenciasdif->add(k, a);
    }

}

void Estudiante::setAsisOn(int id, AsistenciaOnline *a)
{
    IKey *k = new Integer(id);
    this->asistenciason->add(k, a);

}

void Estudiante::finalizarAsisOn(int idC, DtFecha *f)
{
    AsistenciaOnline *aO;
    IKey *k = new Integer(idC);
    aO = (AsistenciaOnline* )this->asistenciason->find(k);
    aO->finalizarAsistencia(f);
}

void Estudiante::finalizarAsisDif(int idC, DtFecha *f)
{
    AsistenciaDiferida *aD;
    IKey *k = new Integer(idC);
    aD = (AsistenciaDiferida* )this->asistenciasdif->find(k);
    aD->setFechaFin(f);
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

AsistenciaOnline *Estudiante::crearAsisOn(int idC, int idA, DtFecha *fechaCom)
{
    return new AsistenciaOnline(idC, idA, fechaCom);
}

void Estudiante::BorrarAsignatura(int idA)
{
    IKey *k = new Integer(idA);
    this->asignaturas->remove(k);
}

void Estudiante::BorrarAsistencias(int idC)
{
    IKey *k = new Integer(idC);
    if(this->asistenciasdif->member(k))
    {
        AsistenciaDiferida *a = (AsistenciaDiferida *)this->asistenciasdif->find(k);
        this->asistenciasdif->remove(k);
        delete a;
    }
    if(this->asistenciason->member(k))
    {
        AsistenciaOnline *a = (AsistenciaOnline *)this->asistenciason->find(k);
        this->asistenciason->remove(k);
        delete a;
    }
}

Estudiante::~Estudiante() {}
