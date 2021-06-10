#ifndef ASISTENCIADIFERIDA_H
#define ASISTENCIADIFERIDA_H
#include "./../../datatypes/headers/DtFecha.h"

//TODO Luego definir un static const para fecha, si es necesario

class AsistenciaDiferida
{
private:
	DtFecha *fechaCom/*[MAX_FECHAS]*/;
	DtFecha *fechaFin/*[MAX_FECHAS]*/;

public:
	AsistenciaDiferida();
	AsistenciaDiferida(DtFecha _fechaCom, DtFecha _fechaFin);

	DtFecha *getFechaCom(int i);
	DtFecha *getFechaFin(int i);

	void setFechaCom(DtFecha &_fecha, int i);
	void setFechaFin(DtFecha &_fecha, int i);

 	virtual ~AsistenciaDiferida();
};

#endif /* ASISTENCIADIFERIDA_H */
