#include "../headers/Clase.h"
Clase::Clase()
{
	this->mensajes = new OrderedDictionary;
}

Clase::Clase(int _id, std::string _nombre, DtFecha *_fechaCom)
{
	this->id = _id;
	this->nombre = _nombre;
	this->fechaCom = _fechaCom;
	this->mensajes = new OrderedDictionary;
}

int Clase::getId()
{
	return this->id;
}

std::string Clase::getVideo()
{
	return this->video;
}

std::string Clase::getNombre()
{
	return this->nombre;
}

DtFecha *Clase::getFechaCom()
{
	return this->fechaCom;
}

DtFecha *Clase::getFechaFin()
{
	return this->fechaFin;
}

IDictionary *Clase::getMensajes()
{
    return this->mensajes;
}
void Clase::setId(int _id)
{
	this->id = _id;
}

void Clase::setNombre(std::string _nombre)
{
	this->nombre = _nombre;
}

void Clase::setFechaCom(DtFecha *_fecha)
{
	this->fechaCom = _fecha;
}

void Clase::setFechaFin(DtFecha *_fecha)
{
	this->fechaFin = _fecha;
}

void Clase::setVideo(std::string _video)
{
    this->video = _video;
}

void Clase::setMensaje(Mensaje *m)
{
    IKey *k = new Integer(m->getId());
    this->mensajes->add(k, m);
}

Mensaje *Clase::crearMensaje(std::string contenido, DtFecha *fecha)
{
    int id = this->mensajes->getSize() +1;
    Mensaje *m = new Mensaje(id, fecha, contenido);
    return m;
}

Mensaje *Clase::crearRespuesta(std::string contenido, Mensaje *m, DtFecha *fecha)
{
    int id = this->mensajes->getSize() +1;
    Mensaje *msj = new Mensaje(id, fecha, contenido);
    msj->setRespuesta(m);
    return msj;
}

bool Clase::estaEnVivo()
{
    if(this->video.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Clase::finalizar(int url, DtFecha *fecha)
{
    this->video = url;
    this->fechaFin = fecha;
}

void Clase::BorrarInstancias()
{
    IIterator *i = this->mensajes->getIterator();
    Mensaje *m;
    while(i->hasCurrent())
    {
        m = (Mensaje *) i->getCurrent();
        IKey *k = new Integer(m->getId());
        this->mensajes->remove(k);
        delete m;
        i->next();
    }
}

int Clase::TiempoDictado()
{
    int h, m;
    if(this->fechaFin->getHora() == this->fechaCom->getHora())
    {
        m = this->fechaFin->getMinuto() - this->fechaCom->getMinuto();
    }
    else
    {
        h = this->fechaFin->getHora() - this->fechaCom->getHora();
        if(this->fechaFin->getMinuto() > this->fechaCom->getMinuto())
        {
            m = this->fechaFin->getMinuto() - this->fechaCom->getMinuto();
            h = h*60;
            m = h + m;
        }
        else
        {
            h = h * 60;
            m = this->fechaCom->getMinuto() - this->fechaFin->getMinuto();
            m = h - m;
        }

    }
    return m;
}

std::ostream& operator<<(std::ostream& out , Clase* info) {
	info->print(out);
	return out;
}

Clase::~Clase() {}
