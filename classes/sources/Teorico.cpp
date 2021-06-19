#include "./../headers/Teorico.h"
Teorico::Teorico() {}

Teorico::Teorico(int _asistentes)
{
    this->asistentes = _asistentes;
}

Teorico::Teorico(int _asistentes, int _id, std::string _nombre, DtFecha _fechaCom) : Clase(_id, _nombre, _fechaCom)
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

Teorico::~Teorico() {}
