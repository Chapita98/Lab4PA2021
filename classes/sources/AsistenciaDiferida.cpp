#include "./../headers/AsistenciaDiferida.h"

AsistenciaDiferida::AsistenciaDiferida() {}

DtFecha AsistenciaDiferida::*getFechaCom(int i)
{
    return this->fechaCom[i];
}

DtFecha AsistenciaDiferida::*getFechaFin(int i)
{
    return this->fechaFin[i];
}

void AsistenciaDiferida::setFechaCom(DtFecha *_fecha, int i) // i tendria el ultimo lugar del array
{
    this->fechaCom[i]= _fecha;
}

void AsistenciaDiferida::setFechaFin(DtFecha *_fecha, int i) // i tendria el ultimo lugar del array
{
    this->fechaFin[i]= _fecha;
}
AsistenciaDiferida::~AsistenciaDiferida() {}
