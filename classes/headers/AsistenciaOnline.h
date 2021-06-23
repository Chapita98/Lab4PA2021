#ifndef ASISTENCIAONLINE_H
#define ASISTENCIAONLINE_H
#include "./../../datatypes/headers/DtFecha.h"
#include "./../../ICollection/interfaces/ICollectible.h"

class AsistenciaOnline : public ICollectible
{
private:
	DtFecha fechaCom;
	DtFecha fechaFin;
	int idClase;

public:
	AsistenciaOnline();
	AsistenciaOnline(DtFecha _fechaCom, DtFecha _fechaFin);

	DtFecha getFechaCom();
	DtFecha getFechaFin();

	void setFechaCom(DtFecha &_fecha);
	void setFechaFin(DtFecha &_fecha);

 	virtual ~AsistenciaOnline();
};

#endif /* ASISTENCIAONLINE_H */
