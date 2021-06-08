#include "../headers/DtBarcoPasajeros.h"
DtBarcoPasajeros::DtBarcoPasajeros() {}

DtBarcoPasajeros::DtBarcoPasajeros(int _cantPasajeros, TipoTamanio _tamanio)
{
	this->cantPasajeros = _cantPasajeros;
	this->tamanio = _tamanio;
}

DtBarcoPasajeros::DtBarcoPasajeros(int _cantPasajeros, TipoTamanio _tamanio, std::string _id, std::string _nombre) : DtBarco(_id, _nombre)
{
	this->cantPasajeros = _cantPasajeros;
	this->tamanio = _tamanio;
}

int DtBarcoPasajeros::getCantPasajeros()
{
	return this->cantPasajeros;
}

TipoTamanio DtBarcoPasajeros::getTamanio()
{
	return this->tamanio;
}

DtBarcoPasajeros::~DtBarcoPasajeros() {}

void DtBarcoPasajeros::print(std::ostream&){
	std::cout << "Id: " << this->getId() << std::endl;
	std::cout << "Nombre: " << this->getNombre() << std::endl;
	std::cout << "Cantidad de Pasajeros: " << this->getCantPasajeros() << std::endl;
	switch(this->getTamanio())
    {
        case BOTE:
            std::cout << "Tamanio: Bote" << std::endl;
            break;
        case CRUCERO:
            std::cout << "Tamanio: Crucero" << std::endl;
            break;
        case GALEON:
            std::cout << "Tamanio: Galeon" << std::endl;
            break;
        case TRANSATLANTICO:
            std::cout << "Tamanio: Transatlantico" << std::endl;
            break;
        }
}
