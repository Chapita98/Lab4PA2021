#include "./../headers/AsistenciaOnline.h"

AsistenciaOnline::AsistenciaOnline(int idC, int idA, DtFecha *_fechaCom)
{
	this->idClase = idC;
	this->idAsig = idA;
	this->fechaCom = _fechaCom;
}

DtFecha *AsistenciaOnline::getFechaCom()
{
    return this->fechaCom;
}

DtFecha *AsistenciaOnline::getFechaFin()
{
    return this->fechaFin;
}

int AsistenciaOnline::getIdClase()
{
    return this->idClase;
}

int AsistenciaOnline::getIdAsig()
{
    return this->idAsig;
}

void AsistenciaOnline::setFechaCom(DtFecha *_fecha)
{
    this->fechaCom = _fecha;
}

void AsistenciaOnline::setFechaFin(DtFecha *_fecha)
{
    this->fechaFin = _fecha;
}

void AsistenciaOnline::setIdClase(int id)
{
    this->idClase = id;
}

void AsistenciaOnline::setIdAsig(int id)
{
    this->idAsig = id;
}

void AsistenciaOnline::finalizarAsistencia(DtFecha *fechaF)
{
    this->fechaFin = fechaF;
}

int AsistenciaOnline::TiempodeAsistencia()
{
    int h = 0,  m = 0;
    if(this->fechaFin->getHora() == this->fechaCom->getHora())
    {
        m = this->fechaFin->getMinuto() - this->fechaCom->getMinuto();
    }
    else
    {
        h = this->fechaFin->getHora() - this->fechaCom->getHora();
        if(this->fechaFin->getMinuto() > this->fechaCom->getMinuto())
        {
            m = this->fechaFin->getMinuto() - this->fechaCom->getMinuto();
            h = h*60;
            m = h + m;
        }
        else
        {
            h = h * 60;
            m = this->fechaCom->getMinuto() - this->fechaFin->getMinuto();
            m = h - m;
        }
    }
    return m;
}

AsistenciaOnline::~AsistenciaOnline() {}
