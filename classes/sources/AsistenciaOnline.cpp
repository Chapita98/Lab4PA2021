#include "./../headers/AsistenciaOnline.h"

AsistenciaOnline::AsistenciaOnline(int id, DtFecha _fechaCom)
{
	this->idClase = id;
	this->fechaCom = fechaCom;
}

DtFecha *AsistenciaOnline::getFechaCom()
{
    return this->fechaCom;
}

DtFecha *AsistenciaOnline::getFechaFin()
{
    return this->fechaCom;
}

int AsistenciaOnline::getIdClase()
{
    return this->idClase;
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

int AsistenciaOnline::TiempodeAsistencia()
{
    int h, m;
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
    return m /100;
}

AsistenciaOnline::~AsistenciaOnline() {}
