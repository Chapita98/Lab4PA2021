#ifndef MONITOREO_H
#define MONITOREO_H
#include "./Clase.h"
#include "./Estudiante.h"
#include "./../../ICollection/interfaces/ICollection.h"

// TODO fijarse si esto es correcto
static const int MAX_ESTUDIANTES = 30;

class Clase;

class Monitoreo : public Clase
{
private:
	ICollection *estudiantes;

public:
	Monitoreo();
	Monitoreo(int _id, std::string _nombre, DtFecha _fechaCom);

	Estudiante *getEstudiante(int i);

	void setEstudiante(Estudiante *_estudiante);

	virtual ~Monitoreo();
};

#endif /* MONITOREO_H */
