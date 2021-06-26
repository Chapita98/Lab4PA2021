#include "./../headers/Monitoreo.h"
#include "./../headers/Estudiante.h"
Monitoreo::Monitoreo()
{
    this->estudiantes = new List;
}

Monitoreo::Monitoreo(int _id, std::string _nombre, DtFecha *_fechaCom) : Clase(_id, _nombre, _fechaCom)
{
    this->estudiantes = new List;
}

ICollection *Monitoreo::getEstudiantes()
{
   return this->estudiantes;
}


void Monitoreo::setEstudiante(Estudiante *_estudiante)
{
    this->estudiantes->add(_estudiante);
}

int Monitoreo::getCantidadEstudiantes()
{
    return this->estudiantes->getSize();
}

bool Monitoreo::estaHabilitado(Estudiante *e)
{
    if(this->estudiantes->member(e))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Monitoreo::print(std::ostream&){
	std::cout << "Monitoreo"<< std::endl;
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

    IIterator *i = this->estudiantes->getIterator();
    Estudiante *e;
    std::cout << "Estudiantes: " << std::endl;
    while(i->hasCurrent())
    {
        e = (Estudiante*) i->getCurrent();
        std::cout << e->getNombre() << std::endl;
        i->next();
    }
}

Monitoreo::~Monitoreo() {}
