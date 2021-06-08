#include "./../headers/DtArribo.h"
// Lista
DtArribo::DtArribo() {}
DtArribo::DtArribo(DtBarco *paramBarcoQueArriba, DtFecha paramFechaDeArribo, float paramCarga) : barcoQueArriba(paramBarcoQueArriba), fechaDeArribo(paramFechaDeArribo)
{
    this->barcoQueArriba = paramBarcoQueArriba;
    this->fechaDeArribo = paramFechaDeArribo;
    this->carga = paramCarga;
}
// Getters
DtBarco* DtArribo::getBarcoQueArriba()
{
    return this->barcoQueArriba;
}

DtFecha DtArribo::getFechaDeArribo()
{
    return this->fechaDeArribo;
}

float DtArribo::getCarga()
{
    return this->carga;
}

DtArribo::~DtArribo() {}
