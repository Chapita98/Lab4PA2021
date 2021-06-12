#ifndef DTMONITOREO_H
#define DTMONITOREO_H
#include "DtClase.h"
#include <iostream>
#include "./../../ICollection/interfaces/ICollection.h"
#include "./../../classes/headers/Estudiante.h"

class DtMonitoreo : public DtClase
{
private:
	ICollection *estudiantes;

public:
	DtMonitoreo();
	DtMonitoreo(int _id, std::string _video, std::string _nombre, DtFecha _fechaCom, DtFecha _fechaFin);

	//Estudiante *getEstudiante(int i);

	virtual ~DtMonitoreo();
  	//void print(std::ostream&);
};
#endif /* DTMONITOREO_H */
