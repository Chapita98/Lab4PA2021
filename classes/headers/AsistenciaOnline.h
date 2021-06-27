#ifndef ASISTENCIAONLINE_H
#define ASISTENCIAONLINE_H
#include "./../../datatypes/headers/DtFecha.h"
#include "./../../ICollection/interfaces/ICollectible.h"

class AsistenciaOnline : public ICollectible
{
private:
	DtFecha *fechaCom;
	DtFecha *fechaFin;
	int idClase;
	int idAsig;

public:
	AsistenciaOnline();
	AsistenciaOnline(int idClase, int idAsig, DtFecha *_fechaCom);

	DtFecha *getFechaCom();
	DtFecha *getFechaFin();
	int getIdClase();
	int getIdAsig();

	void setFechaCom(DtFecha *_fecha);
	void setFechaFin(DtFecha *_fecha);
	void setIdClase(int id);
	void setIdAsig(int id);

	void finalizarAsistencia(DtFecha *fechaF);
	int TiempodeAsistencia();

 	virtual ~AsistenciaOnline();
};

#endif /* ASISTENCIAONLINE_H */
