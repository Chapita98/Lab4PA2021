#include "./../headers/Docente.h"
Docente::Docente() {}

Docente::Docente(std::string _instituto)
{
    this->instituto = _instituto;
}

Docente::Docente(std::string _instituto, std::string _email, std::string _nombre, std::string _imagen, std::string _contrasenia) : Usuario(_email, _nombre, _imagen, _contrasenia)
{
    this->instituto = _instituto;
    /*this->email = _email;
    this->nombre = _nombre;
    this->imagen = _imagen;
    this->contrasenia = _contrasenia;*/
}

std::string Docente::getInstituto()
{
    return this->instituto;
}

std::string Docente::getEmail()
{
    return this->email;
}

std::string Docente::getNombre()
{
    return this->nombre;
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

void Docente::BorrarAsignacion(int id, IDictionary *cl)
{
    IKey *k = new Integer(id);
    IIterator *i = cl->getIterator();
    Clase *c;
    Asignacion *a = (Asignacion *)this->asignaciones->find(k);
    delete a;
    while(i->hasCurrent())
    {
        c = (Clase *) i->getCurrent();
        k = new Integer(c->getId());
        if(this->clases->member(k))
        {
            this->clases->remove(k);
            //Clase *c1 = this->clases->find(k);
            //delete c1;
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
