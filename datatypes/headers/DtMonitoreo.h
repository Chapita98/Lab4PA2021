#ifndef DTMONITOREO_H
#define DTMONITOREO_H
#include "DtClase.h"
#include <iostream>

class DtMonitoreo : public DtClase
{
private:
	Estudiante *estudiantes[MAX_ESTUDIANTES];

public:
	DtMonitoreo();
	DtMonitoreo(int _id, std::string _video, std::string _nombre, DtFecha _fechaCom, DtFecha _fechaFin);

	Estudiante *getEstudiante(int i);

	virtual ~DtMonitoreo();
  	//void print(std::ostream&);
};
#endif /* DTMONITOREO_H */
