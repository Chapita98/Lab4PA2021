#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "./Usuario.h"
#include "./../../ICollection/interfaces/ICollectible.h"
#include "./../../ICollection/interfaces/IDictionary.h"
#include "./../../ICollection/Integer.h"
class Usuario;

class Estudiante : public Usuario
{
private:
	int ci;
	IDictionary * asignaturas;
	IDictionary * asistenciasdif;
	IDictionary * asistenciason;
public:
	Estudiante();
	Estudiante(int _ci);
	Estudiante(int _ci, std::string _email, std::string _nombre, std::string _imagen, std::string _contrasenia);


	int getCi();

	void setCi(int _ci);

    bool estaInscripto(int id);
	virtual ~Estudiante();
};

#endif /* ESTUDIANTE_H */
