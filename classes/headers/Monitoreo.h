#ifndef MONITOREO_H
#define MONITOREO_H
#include "./Clase.h"
#include "./../../ICollection/interfaces/ICollection.h"

// TODO fijarse si esto es correcto
static const int MAX_ESTUDIANTES = 30;

class Clase;
class Estudiante;

class Monitoreo : public Clase
{
private:
	ICollection *estudiantes;

public:
	Monitoreo();
	Monitoreo(int _id, std::string _nombre, DtFecha *_fechaCom);

	ICollection *getEstudiantes();
	int getCantidadEstudiantes();

	void setEstudiante(Estudiante *_estudiante);

	bool estaHabilitado(Estudiante *e);
	void print(std::ostream&);

	virtual ~Monitoreo();
};

#endif /* MONITOREO_H */
