#ifndef MONITOREO_H
#define MONITOREO_H
#include "./Clase.h"
class Clase;

class Monitoreo : public Clase
{
private:
	Estudiante *estudiantes[MAX_ESTUDIANTES];

public:
	Monitoreo();
	Monitoreo(int _id, std::string _video, std::string _nombre, DtFecha _fechaCom, DtFecha _fechaFin);

	Estudiante *getEstudiante(int i);

	void setEstudiante(Estudiante *_estudiante);

	virtual ~Monitoreo();
};

#endif /* MONITOREO_H */