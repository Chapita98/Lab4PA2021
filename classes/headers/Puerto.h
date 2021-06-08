#ifndef PUERTO_H
#define PUERTO_H

#include "./../../datatypes/headers/DtFecha.h"
#include "./Arribo.h"
static const int MAX_ARRIBOS = 30;

class Puerto
{
private:
	std::string id;
	std::string nombre;
	DtFecha fechaCreacion;
	int cantidadArribos;
	Arribo *arribos[MAX_ARRIBOS];

public:
	Puerto();
	Puerto(std::string _id, std::string _nombre, DtFecha _fechaCreacion, int _cantArribos);

	std::string getId();
	std::string getNombre();
	DtFecha getFechaCreacion();
	int getCantArribos();
	Arribo *getArribo(int i);

	void setId(std::string _id);
	void setNombre(std::string _nombre);
	void setFechaCreacion(DtFecha &_fechaCreacion);
	void setArribo(Arribo *_arribo);
	void setCantArribos(int cant);

	virtual ~Puerto();
};

#endif /* PUERTO_H */
