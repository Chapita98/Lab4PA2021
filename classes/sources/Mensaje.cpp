#include "./../headers/Mensaje.h"

Mensaje::Mensaje() {}

Mensaje::Mensaje(int _id, DtFecha fechaEnvio, std::string _contenido)
{
    this->id = _id;
    this->fechaEnvio = _fechaEnvio;
    this->contenido = _contenido;
}

int Mensaje::getId()
{
    return this->id;
}

DtFecha fechaEnvio::getFechaEnvio()
{
    return this->fechaEnvio;
}

std::string Mensaje::getContenido()
{
    return this->contenido;
}


void Mensaje::setId(int _id)
{
    this->id = _id;
}

void Mensaje::setFechaEnvio(DtFecha _fechaEnvio)
{
    this->fechaEnvio = _fechaEnvio;
}

void Mensaje::setContenido(std::string _contenido)
{
    this->contenido = _contenido;
}


Mensaje::~Mensaje() {}
