#include "./../headers/Mensaje.h"

Mensaje::Mensaje() {}

Mensaje::Mensaje(int _id, DtFecha *_fechaEnvio, std::string _contenido)
{
    this->id = _id;
    this->fechaEnvio = _fechaEnvio;
    this->contenido = _contenido;
    this->respuesta = nullptr;
}

int Mensaje::getId()
{
    return this->id;
}

DtFecha *Mensaje::getFechaEnvio()
{
    return this->fechaEnvio;
}

std::string Mensaje::getContenido()
{
    return this->contenido;
}

Mensaje *Mensaje::getRespuesta()
{
    return this->respuesta;
}

void Mensaje::setId(int _id)
{
    this->id = _id;
}

void Mensaje::setFechaEnvio(DtFecha *_fechaEnvio)
{
    this->fechaEnvio = _fechaEnvio;
}

void Mensaje::setContenido(std::string _contenido)
{
    this->contenido = _contenido;
}

void Mensaje::setRespuesta(Mensaje *m)
{
    this->respuesta = m;
}

bool Mensaje::esRespuesta()
{
   if(this->respuesta==nullptr)
   {
	return false;
   }
   else
   {
	return true;   
   }
}

Mensaje::~Mensaje() {}
