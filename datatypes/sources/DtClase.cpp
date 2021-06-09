#include "../headers/DtClase.h"
DtClase::DtClase() {}

DtClase::DtClase(int _id, std::string _video, std::string _nombre, DtFecha _fechaCom, DtFecha _fechaFin)
{
	this->id = _id;
	this->video = _video;
	this->nombre = _nombre;
	this->fechaCom = _fechaCom;
	this->fechaFin = _fechaFin;
}

int DtClase::getId()
{
	return this->id;
}

std::string DtClase::getVideo()
{
	return this->video;
}

std::string DtClase::getNombre()
{
	return this->nombre;
}

std::string DtClase::getFechaCom()
{
	return this->fechaCom;
}

std::string DtClase::getFechaFin()
{
	return this->fechaFin;
}

DtClase::~DtClase() {}

/*std::ostream& operator<<(std::ostream& out , DtBarco* info) {
	info->print(out);
	return out;
}*/

