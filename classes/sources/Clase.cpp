#include "../headers/Clase.h"
Clase::Clase() {}

Clase::Clase(int _id, std::string _nombre, DtFecha _fechaCom)
{
	this->id = _id;
	this->nombre = _nombre;
	this->fechaCom = _fechaCom;
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

void Clase::setVideo(std::string _video)
{
	this->video = _video;
}

void Clase::setFechaCom(DtFecha &_fecha)
{
	this->fechaCom = _fecha;
}

void Clase::setFechaFin(DtFecha &_fecha)
{
	this->fechaFin = _fecha;
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

Clase::~Clase() {}
