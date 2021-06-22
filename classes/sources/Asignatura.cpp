#include "./../headers/Asignatura.h"

Asignatura::Asignatura() {
    this->clases = new OrderedDictionary();
}

Asignatura::Asignatura(int _id, std::string _nombre)
{
    this->id = _id;
    this->nombre = _nombre;
    this->clases = new OrderedDictionary();
}

int Asignatura::getId()
{
    return this->id;
}

std::string Asignatura::getNombre()
{
    return this->nombre;
}

IDictionary *Asignatura::getClases()
{
    return this->clases;
}

ICollection *Asignatura::getClasesDif()
{
    IIterator *i = this->clases->getIterator();
    Clase *c;
    ICollection *cl = new List;
    while(i->hasCurrent())
    {
        c = (Clase *) i->getCurrent();
        if(!c->estaEnVivo())
        {
            cl->add(c);
        }
        i->next();
    }
    return cl;
}

void Asignatura::setId(int _id)
{
    this->id = _id;
}

void Asignatura::setClase(Clase *c)
{
    IKey *k = new Integer(c->getId());
    this->clases->add(k, c);
}

void Asignatura::setNombre(std::string _nombre)
{
    this->nombre = _nombre;
}

Clase * Asignatura::crearClase(std::string nombre, DtFecha fechaComienzo, Tipo tipo)
{
    int id = this->clases->getSize() + 1;
    if(tipo == Tipo::MONITOREO)
    {
        return new Monitoreo(id, nombre, fechaComienzo);
    }
    if(tipo == Tipo::TEORICO)
    {
        return new Teorico(0, id, nombre, fechaComienzo);
    }
    if(tipo == Tipo::PRACTICO)
    {
        return new Practico(id, nombre, fechaComienzo);
    }
}

Asignatura::~Asignatura() {}
