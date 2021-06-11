#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "./../../ICollection/interfaces/ICollectible.h"

class Usuario : public ICollectible
{
private:
	std::string email;
	std::string nombre;
	std::string imagen;
	std::string contrasenia;

public:
	Usuario();
	Usuario(std::string _email, std::string _nombre, std::string _imagen, std::string _contrasenia);

	std::string getEmail();
	std::string getNombre();
	std::string getImagen();
	std::string getContrasenia();

	void setEmail(std::string _email);
	void setNombre(std::string _nombre);
	void setImagen(std::string _imagen);
	void setContrasenia(std::string _contrasenia);

	virtual ~Usuario();
};

#endif /* USUARIO_H */
