#include "./../headers/DtTeorico.h"
DtTeorico::DtTeorico() {}

DtTeorico::DtTeorico(int _asistentes)
{
    this->asistentes = _asistentes;
}

DtTeorico::DtTeorico(int _asistentes, int _id, std::string _video, std::string _nombre, DtFecha _fechaCom, DtFecha _fechaFin) : DtClase(_id, _video, _nombre, _fechaCom, _fechaFin)
{
    this->asistentes = _asistentes;
}

int DtTeorico::getAsistentes()
{
    return this->asistentes;
}

DtTeorico::~DtTeorico() {}

/*void DtBarcoPasajeros::print(std::ostream&){
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
}*/
