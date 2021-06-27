#include "./../headers/Docente.h"
Docente::Docente()
{
    this->asignaciones = new OrderedDictionary;
    this->clases = new OrderedDictionary;
}

Docente::Docente(std::string _instituto)
{
    this->instituto = _instituto;
    this->asignaciones = new OrderedDictionary;
    this->clases = new OrderedDictionary;
}

Docente::Docente(std::string _instituto, std::string _email, std::string _nombre, std::string _imagen, std::string _contrasenia) : Usuario(_email, _nombre, _imagen, _contrasenia)
{
    this->instituto = _instituto;
    this->asignaciones = new OrderedDictionary;
    this->clases = new OrderedDictionary;
}

std::string Docente::getInstituto()
{
    return this->instituto;
}

ICollection *Docente::getAsignaturas()
{
    IIterator *i = this->asignaciones->getIterator();
    Integer *id;
    Asignacion *as;
    ICollection *a = new List;
    while(i->hasCurrent())
    {
        as = (Asignacion *) i->getCurrent();
        id = new Integer(as->getIdAsignatura());
        a->add(id);
        i->next();
    }
    return a;
}

Asignacion *Docente::getAsignacion(int id)
{
    IKey *k = new Integer(id);
    return (Asignacion *)this->asignaciones->find(k);
}

IDictionary *Docente::getClasesVivo()
{
    IIterator *i = this->clases->getIterator();
    Clase *c;
    IDictionary *cl = new OrderedDictionary;
    IKey *k = new Integer(0);
    while(i->hasCurrent())
    {
        c = (Clase *) i->getCurrent();
        if (c->estaEnVivo())
        {
            k = new Integer(c->getId());
            cl->add(k,c);
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

IDictionary *Docente::getClases()
{
    return this->clases;
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

bool Docente::estaAsignado(int id)
{
    IKey *k = new Integer(id);
    if(this->asignaciones->member(k))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Docente::finalizarClase(int id, DtFecha *fecha)
{
    IKey *k = new Integer(id);
    Clase *c;
    c = (Clase *) this->clases->find(k);
    c->finalizar(id+100, fecha);
}

void Docente::BorrarAsignacion(int id, IDictionary *cl)
{
    IKey *k = new Integer(id);
    IIterator *i = cl->getIterator();
    Clase *c;
    Asignacion *a = (Asignacion *)this->asignaciones->find(k);
    this->asignaciones->remove(k);
    delete a;
    while(i->hasCurrent())
    {
        c = (Clase *) i->getCurrent();
        k = new Integer(c->getId());
        if(this->clases->member(k))
        {
            this->clases->remove(k);
        }
        i->next();
    }
}

Asignacion *Docente::crearAsignacion(Tipo tipo, int idAsignatura)
{
    Asignacion *a = new Asignacion(tipo, idAsignatura);
    return a;
}

Docente::~Docente() {}
