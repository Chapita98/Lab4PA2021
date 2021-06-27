#ifndef ASISTENCIADIFERIDA_H
#define ASISTENCIADIFERIDA_H
#include "./../../datatypes/headers/DtFecha.h"
#include "./../../ICollection/interfaces/ICollectible.h"
#include "./../../ICollection/interfaces/ICollection.h"
#include "./../../ICollection/collections/List.h"

class AsistenciaDiferida : public ICollectible
{
private:
	ICollection *fechaCom;
	ICollection *fechaFin;
	int idClase;

public:
	AsistenciaDiferida();
	AsistenciaDiferida(int idC);

	ICollection *getFechaCom();
	ICollection *getFechaFin();
	int getIdClase();

	void setFechaCom(DtFecha *_fecha);
	void setFechaFin(DtFecha *_fecha);
	void setIdClase(int id);

    bool estaEnVivo();
 	virtual ~AsistenciaDiferida();
};

#endif /* ASISTENCIADIFERIDA_H */
