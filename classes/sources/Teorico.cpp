#include "./../headers/Teorico.h"
Teorico::Teorico() {}

Teorico::Teorico(int _asistentes)
{
    this->asistentes = _asistentes;
}

Teorico::Teorico(int _asistentes, int _id, std::string _nombre, DtFecha *_fechaCom) : Clase(_id, _nombre, _fechaCom)
{
    this->asistentes = _asistentes;
}

int Teorico::getAsistentes()
{
    return this->asistentes;
}


void Teorico::setAsistentes(int _asistentes)
{
    this->asistentes = _asistentes;
}

void Teorico::print(std::ostream&){
	std::cout << "Teorico"<< std::endl;
	std::cout << "Id: " << this->getId() << std::endl;
	std::cout << "Nombre: " << this->getNombre() << std::endl;
	std::cout << "Cantidad de asistentes: " << this->getAsistentes() << std::endl;
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

Teorico::~Teorico() {}
