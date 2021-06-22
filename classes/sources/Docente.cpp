#include "./../headers/Docente.h"
Docente::Docente() {}

Docente::Docente(std::string _instituto)
{
    this->instituto = _instituto;
}

Docente::Docente(std::string _instituto, std::string _email, std::string _nombre, std::string _imagen, std::string _contrasenia) : Usuario(_email, _nombre, _imagen, _contrasenia)
{
    this->instituto = _instituto;
}

std::string Docente::getInstituto()
{
    return this->instituto;
}

ICollection *Docente::getAsignaturas()
{
    IIterator *i = this->asignaciones->getIterator();
    Integer *k;
    Asignacion *as;
    ICollection *a = NULL;
    while(i->hasCurrent())
    {
        as = (Asignacion *) i->getCurrent();
        k = as->getAsignatura();
        a->add(k);
        i->next();
    }
    return a;
}

Asignacion *Docente::getAsignacion(int id)
{
    IKey *k = new Integer(id);
    return (Asignacion *)this->asignaciones->find(k);
}

ICollection *Docente::getClasesVivo()
{
    IIterator *i = this->clases->getIterator();
    Clase *c;
    ICollection *cl = new List;
    while(i->hasCurrent())
    {
        c = (Clase *) i->getCurrent();
        if (c->estaEnVivo())
        {
            cl->add(c);
        }
        i->next();
    }
    return cl;
}

Clase *Docente::getClase(int id)
{
    IKey *k = new Integer(id);
    return (Clase *)this->clases->find(k);
}

void Docente::setInstituto(std::string _instituto)
{
    this->instituto = _instituto;
}
void Docente::setAsignacion(Asignacion *a, IKey *id)
{
        this->asignaciones->add(id, a);
}

void Docente::setClase(Clase *c)
{
    IKey *i = new Integer(c->getId());
    this->clases->add(i, c);
}

bool Docente::estaAsignado(IKey *id)
{
    if(this->asignaciones->member(id))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Docente::finalizarClase(int id, DtFecha fecha)
{
    IKey *k = new Integer(id);
    Clase *c;
    c = (Clase *) this->clases->find(k);
    c->finalizar(id+100, fecha);
}

Asignacion *Docente::crearAsignacion(Tipo tipo, int idAsignatura)
{
    Asignacion *a = new Asignacion(tipo, idAsignatura);
    return a;
}

Docente::~Docente() {}
