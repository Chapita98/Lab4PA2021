#include "../headers/BarcoPasajeros.h"
BarcoPasajeros::BarcoPasajeros() {}

BarcoPasajeros::BarcoPasajeros(int _cantPasajeros, TipoTamanio _tamanio) : tamanio(_tamanio)
{
	this->cantPasajeros = _cantPasajeros;
	this->tamanio = _tamanio;
}
BarcoPasajeros::BarcoPasajeros(int _cantPasajeros, TipoTamanio _tamanio, std::string _id, std::string _nombre) : Barco(_id, _nombre)
{
	this->cantPasajeros = _cantPasajeros;
	this->tamanio = _tamanio;
}
int BarcoPasajeros::getCantPasajeros()
{
	return this->cantPasajeros;
}

TipoTamanio BarcoPasajeros::getTamanio()
{
	return this->tamanio;
}

void BarcoPasajeros::setCantPasajeros(int _cantPasajeros)
{
	this->cantPasajeros = _cantPasajeros;
}

void BarcoPasajeros::setTamanio(TipoTamanio _tamanio)
{
	this->tamanio = _tamanio;
}

BarcoPasajeros::~BarcoPasajeros() {}
