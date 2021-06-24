#include "./../headers/AsistenciaDiferida.h"

AsistenciaDiferida::AsistenciaDiferida()
{
    this->fechaCom = new List;
    this->fechaFin = new List;
}

ICollection *AsistenciaDiferida::getFechaCom()
{
    return this->fechaCom;
}

ICollection *AsistenciaDiferida::getFechaFin()
{
    return this->fechaFin;
}

int AsistenciaDiferida::getIdClase()
{
    return this->idClase;
}

void AsistenciaDiferida::setFechaCom(DtFecha *_fecha)
{
    this->fechaCom->add(_fecha);
}

void AsistenciaDiferida::setFechaFin(DtFecha *_fecha)
{
    this->fechaFin->add(_fecha);
}
void AsistenciaDiferida::setIdClase(int id)
{
    this->idClase = id;
}

AsistenciaDiferida::~AsistenciaDiferida() {}
