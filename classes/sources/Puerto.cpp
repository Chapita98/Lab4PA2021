#include "./../headers/Puerto.h"
Puerto::Puerto() {}

Puerto::Puerto(std::string _id, std::string _nombre, DtFecha _fechaCreacion, int _cantArribos) : fechaCreacion(_fechaCreacion)
{
  this->id = _id;
  this->nombre = _nombre;
  this->fechaCreacion = _fechaCreacion;
  this->cantidadArribos = _cantArribos;
}
void Puerto::setArribo(Arribo *_arribo)
{
    this->arribos[this->getCantArribos()]= _arribo;
}

std::string Puerto::getId()
{
  return this->id;
}

std::string Puerto::getNombre()
{
  return this->nombre;
}

DtFecha Puerto::getFechaCreacion()
{
  return this->fechaCreacion;
}

int Puerto::getCantArribos()
{
  return this->cantidadArribos;
}
Arribo* Puerto::getArribo(int i)
{
    return this->arribos[i];
}
void Puerto::setId(std::string _id)
{
  this->id = _id;
}

void Puerto::setNombre(std::string _nombre)
{
  this->nombre = _nombre;
}
void Puerto::setCantArribos(int _cantidadArribos)
{
  this->cantidadArribos= _cantidadArribos;
}
void Puerto::setFechaCreacion(DtFecha &_fechaCreacion)
{
  this->fechaCreacion = _fechaCreacion;
}

Puerto::~Puerto() {}
