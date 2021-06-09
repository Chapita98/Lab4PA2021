#include "../headers/Usuario.h"
Usuario::Usuario() {}

Usuario::Usuario(std::string _email, std::string _nombre, std::string _imagen, std::string _contrasenia)
{
	this->email = _email;
	this->nombre = _nombre;
	this->imagen = _imagen;
	this->contrasenia = _contrasenia;
}

std::string Usuario::getEmail()
{
	return this->email;
}

std::string Usuario::getNombre()
{
	return this->nombre;
}

std::string Usuario::getImagen()
{
	return this->imagen;
}

std::string Usuario::getContrasenia()
{
	return this->contrasenia;
}

void Usuario::setEmail(std::string _email)
{
	this->email = _email;
}

void Usuario::setNombre(std::string _nombre)
{
	this->nombre = _nombre;
}

void Usuario::setImagen(std::string _imagen)
{
	this->imagen = _imagen;
}

void Usuario::setContrasenia(std::string _contrasenia)
{
	this->contrasenia = _contrasenia;
}

Usuario::~Usuario() {}
