#include "./../headers/AsistenciaOnline.h"

AsistenciaOnline::AsistenciaOnline(DtFecha _fechaCom, DtFecha _fechaFin) //: _fecha(_fecha)
{
	this->fechaCom = fechaCom;
	this->fechaFin = fechaFin;
}

DtFecha AsistenciaOnline::getFechaCom()
{
    return this->fechaCom;
}

DtFecha AsistenciaOnline::getFechaFin()
{
    return this->fechaCom;
}

void AsistenciaOnline::setFechaCom(DtFecha &_fecha)
{
    this->fechaCom = _fecha;
}

void AsistenciaOnline::setFechaFin(DtFecha &_fecha)
{
    this->fechaFin = _fecha;
}

AsistenciaOnline::~AsistenciaOnline() {}
