#include "./../headers/Practico.h"
Practico::Practico() {}

Practico::Practico(int _id, std::string _nombre, DtFecha *_fechaCom) : Clase(_id, _nombre, _fechaCom)
{

}

void Practico::print(std::ostream&){
	std::cout << "Practico"<< std::endl;
	std::cout << "Id: " << this->getId() << std::endl;
	std::cout << "Nombre: " << this->getNombre() << std::endl;
	std::cout << "Fecha de Comienzo: " << std::endl;
	std::cout << this->getFechaCom()->getAnio() << "/" << this->getFechaCom()->getMes() << "/" << this->getFechaCom()->getDia() << std::endl;
	std::cout << this->getFechaCom()->getHora() << ":" << this->getFechaCom()->getMinuto() << ":" << this->getFechaCom()->getSegundo() << std::endl;
	if(this->getFechaFin()!= NULL)
    {
        std::cout << "Fecha de finalizacion: " << std::endl;
        std::cout << this->getFechaFin()->getAnio() << "/" << this->getFechaFin()->getMes() << "/" << this->getFechaFin()->getDia() << std::endl;
        std::cout << this->getFechaFin()->getHora() << ":" << this->getFechaFin()->getMinuto() << ":" << this->getFechaFin()->getSegundo() << std::endl;
    }
}

Practico::~Practico() {}
