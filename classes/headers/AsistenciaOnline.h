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
	AsistenciaOnline(int idClase, DtFecha _fechaCom);

	DtFecha getFechaCom();
	DtFecha getFechaFin();
	int getIdClase();

	void setFechaCom(DtFecha _fecha);
	void setFechaFin(DtFecha _fecha);
	void setIdClase(int id);

 	virtual ~AsistenciaOnline();
};

#endif /* ASISTENCIAONLINE_H */
