#ifndef ASISTENCIAONLINE_H
#define ASISTENCIAONLINE_H

class AsistenciaOnline
{
private:
	DtFecha fechaCom;
	DtFecha fechaFin;

public:
	AsistenciaOnline();
	AsistenciaOnline(DtFecha _fechaCom, DtFecha _fechaFin);

	DtFecha getFechaCom();
	DtFecha getFechaFin();

	void setFechaCom(DtFecha *_fecha);
	void setFechaFin(DtFecha *_fecha);

 	virtual ~AsistenciaOnline();
};

#endif /* ASISTENCIAONLINE_H */
