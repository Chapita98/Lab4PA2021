#include "../headers/Barco.h"
Barco::Barco() {}

Barco::Barco(std::string _id, std::string _nombre)
{
	this->id = _id;
	this->nombre = _nombre;
}

std::string Barco::getId()
{
	return this->id;
}

std::string Barco::getNombre()
{
	return this->nombre;
}

void Barco::setId(std::string _id)
{
	this->id = _id;
}

void Barco::setNombre(std::string _nombre)
{
	this->nombre = _nombre;
}

Barco::~Barco() {}
