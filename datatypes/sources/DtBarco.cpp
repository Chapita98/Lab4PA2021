#include "./../headers/DtBarco.h"
DtBarco::DtBarco() {}
DtBarco::DtBarco(std::string _id, std::string _nombre)
{
    this->id = _id;
    this->nombre = _nombre;
}

std::string DtBarco::getId()
{
    return this->id;
}

std::string DtBarco::getNombre()
{
    return this->nombre;
}

DtBarco::~DtBarco()
{
}

std::ostream& operator<<(std::ostream& out , DtBarco* info) {
	info->print(out);
	return out;
}

