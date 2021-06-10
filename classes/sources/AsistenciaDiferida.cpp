#include "./../headers/AsistenciaDiferida.h"

// TODO DtFecha(_fechaCom, _fechaFin)

AsistenciaDiferida::AsistenciaDiferida(DtFecha _fechaCom, DtFecha _fechaFin) : _fecha(_fecha)
{
	this->fechaCom = fechaCom;
	this->fechaFin = fechaFin;
}

DtFecha AsistenciaDiferida::*getFechaCom(int i)
{
    return this->fechaCom[i];
}

DtFecha AsistenciaDiferida::*getFechaFin(int i)
{
    return this->fechaFin[i];
}

void AsistenciaDiferida::setFechaCom(DtFecha &_fecha, int i) // i tendria el ultimo lugar del array
{
    this->fechaCom[i]= _fecha;
}

void AsistenciaDiferida::setFechaFin(DtFecha &_fecha, int i) // i tendria el ultimo lugar del array
{
    this->fechaFin[i]= _fecha;
}

AsistenciaDiferida::~AsistenciaDiferida() {}
