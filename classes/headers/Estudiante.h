#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "./Usuario.h"
class Usuario;

class Estudiante : public Usuario
{
private:
	int ci;

public:
	Estudiante();
	Estudiante(int _ci);
	Estudiante(int _ci, std::string _email, std::string _nombre, std::string _imagen, std::string _contrasenia);

	int getCi();

	void setCi(int _ci);

	virtual ~Estudiante();
};

#endif /* ESTUDIANTE_H */
