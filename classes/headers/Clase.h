#ifndef CLASE_H
#define CLASE_H
#include <string>
#include "./../../datatypes/headers/DtFecha.h"
#include "./AsistenciaDiferida.h"
#include "./AsistenciaOnline.h"
#include "./Mensaje.h"
#include "./../../ICollection/interfaces/ICollectible.h"
//#include "./../../ICollection/interfaces/ICollection.h"
//#include "./../../ICollection/interfaces/IDictionary.h"
#include "./../../ICollection/collections/List.h"
#include "./../../ICollection/collections/OrderedDictionary.h"
#include "./../../ICollection/Integer.h"

class Clase : public ICollectible
{
private:
	int id;
	std::string video;
	std::string nombre;
	DtFecha fechaCom;
	DtFecha fechaFin;
	AsistenciaDiferida *asistenciadif;
	ICollection * asistenciaon;
	IDictionary * mensajes;

public:
	Clase();
	Clase(int _id, std::string _nombre, DtFecha _fechaCom);

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
	void setAsisOn(AsistenciaOnline *aO);
	void setAsisDif(DtFecha _fechaCom);
	void finalizarAsistencia(DtFecha _fechafin);

	bool estaEnVivo();
	void finalizar(int url, DtFecha fecha);
	void BorrarInstancias();

	virtual ~Clase();
};

#endif /* CLASE_H */
