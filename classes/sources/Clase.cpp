#include "../headers/Clase.h"
Clase::Clase()
{
    this->asistenciaon = new List;
    this->asistenciadif = new List;
	this->mensajes = new OrderedDictionary;
}

Clase::Clase(int _id, std::string _nombre, DtFecha _fechaCom)
{
	this->id = _id;
	this->nombre = _nombre;
	this->fechaCom = _fechaCom;
	this->asistenciaon = new List;
	this->asistenciadif = new List;
	this->mensajes = new OrderedDictionary;
}

int Clase::getId()
{
	return this->id;
}

std::string Clase::getVideo()
{
	return this->video;
}

std::string Clase::getNombre()
{
	return this->nombre;
}

DtFecha Clase::getFechaCom()
{
	return this->fechaCom;
}

DtFecha Clase::getFechaFin()
{
	return this->fechaFin;
}

void Clase::setId(int _id)
{
	this->id = _id;
}

void Clase::setNombre(std::string _nombre)
{
	this->nombre = _nombre;
}

void Clase::setFechaCom(DtFecha &_fecha)
{
	this->fechaCom = _fecha;
}

void Clase::setFechaFin(DtFecha &_fecha)
{
	this->fechaFin = _fecha;
}

void Clase::setVideo(std::string _video)
{
    this->video = _video;
}

bool Clase::estaEnVivo()
{
    if(this->video.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Clase::finalizar(int url, DtFecha fecha)
{
    this->video = url;
    this->fechaFin = fecha;
}

void Clase::BorrarInstancias()
{
    IIterator *i = this->asistenciadif->getIterator();
    AsistenciaDiferida *aD;
    while(i->hasCurrent())
    {
        aD = (AsistenciaDiferida *) i->getCurrent();
        this->asistenciadif->remove(aD);
        delete aD;
        i->next();
    }
    i = this->asistenciaon->getIterator();
    AsistenciaOnline *aO;
    while(i->hasCurrent())
    {
        aO = (AsistenciaOnline *) i->getCurrent();
        this->asistenciaon->remove(aO);
        delete aO;
        i->next();
    }
    i = this->mensajes->getIterator();
    Mensaje *m;
    while(i->hasCurrent())
    {
        m = (Mensaje *) i->getCurrent();
        IKey *k = new Integer(m->getId());
        this->mensajes->remove(k);
        delete m;
        i->next();
    }
}

Clase::~Clase() {}
