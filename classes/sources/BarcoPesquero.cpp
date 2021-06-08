#include "./../headers/BarcoPesquero.h"
BarcoPesquero::BarcoPesquero() {}

BarcoPesquero::BarcoPesquero(int capacidad, int carga)
{
    this->Capacidad = capacidad;
    this->Carga = carga;
}

BarcoPesquero::BarcoPesquero(int capacidad, int carga, std::string id, std::string nombre) : Barco(id, nombre)
{
    this->Capacidad = capacidad;
    this->Carga = carga;
}

int BarcoPesquero::getCapacidad()
{
    return this->Capacidad;
}

int BarcoPesquero::getCarga()
{
    return this->Carga;
}

void BarcoPesquero::setCarga(int carga)
{
    this->Carga = carga;
}

void BarcoPesquero::setCapacidad(int capacidad)
{
    this->Capacidad = capacidad;
}

BarcoPesquero::~BarcoPesquero() {}
