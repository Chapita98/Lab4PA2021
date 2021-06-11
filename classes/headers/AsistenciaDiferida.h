#ifndef ASISTENCIADIFERIDA_H
#define ASISTENCIADIFERIDA_H
#include "./../../datatypes/headers/DtFecha.h"
#include "./../../ICollection/interfaces/ICollectible.h"
#include "./../../ICollection/interfaces/ICollection.h"

//TODO Luego definir un static const para fecha, si es necesario

class AsistenciaDiferida : public ICollectible
{
private:
	ICollection *fechaCom;
	ICollection *fechaFin;
	Clase *clase;

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
