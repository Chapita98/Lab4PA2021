#ifndef ASISTENCIADIFERIDA_H
#define ASISTENCIADIFERIDA_H
#include "./../../datatypes/headers/DtFecha.h"
#include "./../../ICollection/interfaces/ICollectible.h"
#include "./../../ICollection/interfaces/ICollection.h"
#include "./../../ICollection/collections/List.h"

//TODO Luego definir un static const para fecha, si es necesario

class AsistenciaDiferida : public ICollectible
{
private:
	ICollection *fechaCom;
	ICollection *fechaFin;
	int idClase;

public:
	AsistenciaDiferida();

	ICollection *getFechaCom();
	ICollection *getFechaFin();
	int getIdClase();

	void setFechaCom(DtFecha *_fecha);
	void setFechaFin(DtFecha *_fecha);
	void setIdClase(int id);

 	virtual ~AsistenciaDiferida();
};

#endif /* ASISTENCIADIFERIDA_H */
