#ifndef CLASE_H
#define CLASE_H
#include <string>
#include "./../../datatypes/headers/DtFecha.h"
#include "./../../ICollection/interfaces/ICollectible.h"
#include "./../../ICollection/interfaces/ICollection.h"
#include "./../../ICollection/interfaces/IDictionary.h"

class Clase : public ICollectible
{
private:
	int id;
	std::string video;
	std::string nombre;
	DtFecha fechaCom;
	DtFecha fechaFin;
	ICollection * asistencias;
	IDictionary * mensajes;

public:
	Clase();
	Clase(int _id, std::string _video, std::string _nombre, DtFecha _fechaCom, DtFecha _fechaFin);

	int getId();
	std::string getVideo();
	std::string getNombre();
	DtFecha getFechaCom();
	DtFecha getFechaFin();

	void setId(int _id);
	void setVideo(std::string _video);
	void setNombre(std::string _nombre);
	void setFechaCom(DtFecha &_fechaCom);
	void setFechaFin(DtFecha &_fechaFin);

	virtual ~Clase();
};

#endif /* CLASE_H */
