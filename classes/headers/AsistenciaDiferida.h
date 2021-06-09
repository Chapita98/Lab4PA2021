#ifndef ASISTENCIADIFERIDA_H
#define ASISTENCIADIFERIDA_H

class AsistenciaDiferida
{
private:
	DtFecha *fechaCom[MAX_FECHAS];
	DtFecha *fechaFin[MAX_FECHAS];

public:
	AsistenciaDiferida();

	DtFecha *getFechaCom(int i);
	DtFecha *getFechaFin(int i);

	void setFechaCom(DtFecha *_fecha);
	void setFechaFin(DtFecha *_fecha);

 	virtual ~AsistenciaDiferida();
};

#endif /* ASISTENCIADIFERIDA_H */
