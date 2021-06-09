#include "./../headers/DtPractico.h"
DtPractico::DtPractico() {}

DtPractico::DtPractico(int _id, std::string _video, std::string _nombre, DtFecha _fechaCom, DtFecha _fechaFin) : DtClase(_id, _video, _nombre, _fechaCom, _fechaFin)
{

}

DtPractico::~DtPractico() {}

/*void DtBarcoPesquero::print(std::ostream&){
	std::cout << "Id: " << this->getId() << std::endl;
	std::cout << "Nombre: " << this->getNombre() << std::endl;
	std::cout << "Capacidad: " << this->getCapacidad() << std::endl;
	std::cout << "Carga: " << this->getCarga() << std::endl;
}*/
