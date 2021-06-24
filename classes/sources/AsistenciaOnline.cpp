#include "./../headers/AsistenciaOnline.h"

AsistenciaOnline::AsistenciaOnline(int id, DtFecha _fechaCom)
{
	this->idClase = id;
	this->fechaCom = fechaCom;
}

DtFecha AsistenciaOnline::getFechaCom()
{
    return this->fechaCom;
}

DtFecha AsistenciaOnline::getFechaFin()
{
    return this->fechaCom;
}

int AsistenciaOnline::getIdClase()
{
    return this->idClase;
}

void AsistenciaOnline::setFechaCom(DtFecha _fecha)
{
    this->fechaCom = _fecha;
}

void AsistenciaOnline::setFechaFin(DtFecha _fecha)
{
    this->fechaFin = _fecha;
}

void AsistenciaOnline::setIdClase(int id)
{
    this->idClase = id;
}

AsistenciaOnline::~AsistenciaOnline() {}
